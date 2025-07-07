#include "attributes_task.h"
#include "config.h"

// Task handle
TaskHandle_t attributesTaskHandle = NULL;

// Định nghĩa trạng thái relay
std::array<bool, RELAY_COUNT> relayStates = {false, false, false, false, false, false};

// Biến lưu dữ liệu cảm biến đọc từ ThingsBoard về
volatile float temperature = NAN;
volatile float humidity = NAN;


// Điều khiển relay
void setRelay(uint8_t index, bool state) {
  if (index >= RELAY_COUNT) return;
  digitalWrite(RELAY_PINS[index], state ? HIGH : LOW);
  relayStates[index] = state;
  Serial.printf("Relay %d set to %s\n", index + 1, state ? "ON" : "OFF");
}

// Callback cho RPC
RPC_Response processRelayRPC(const RPC_Data &data) {
  String method = data["method"].as<String>();
  Serial.println("Received RPC method: " + method);

  if (method.startsWith("sw")) {
    int relayIndex = method.substring(2).toInt() - 1;
    if (relayIndex >= 0 && relayIndex < RELAY_COUNT) {
      bool state = data["params"].as<bool>();
      setRelay(relayIndex, state);
      return RPC_Response(method.c_str(), state);
    }
  }

  return RPC_Response("error", "Invalid method");
}

// Xử lý client attributes từ server
void processAttributeRequest(const JsonObjectConst& data) {
  Serial.println("Received client attributes:");
  for (auto it = data.begin(); it != data.end(); ++it) {
    const char* key = it->key().c_str();
    Serial.print("Key: ");
    Serial.print(key);
    Serial.print(", Value: ");
    Serial.println(it->value().as<String>());

    if (strcmp(key, "temperature") == 0) {
      temperature = it->value().as<float>();
      Serial.print("Received temperature from client attribute: ");
      Serial.println(temperature);
    }
    else if (strcmp(key, "humidity") == 0) {
      humidity = it->value().as<float>();
      Serial.print("Received humidity from client attribute: ");
      Serial.println(humidity);
    }
  }
  // Đánh dấu là attributes đã thay đổi
  portENTER_CRITICAL(&ledMux);
  attributesChanged = true;
  portEXIT_CRITICAL(&ledMux);
}

// Gửi trạng thái các relay lên client attributes
void sendRelayStates() {
  for (int i = 0; i < RELAY_COUNT; i++) {
    String key = "sw" + String(i + 1);
    tb.sendAttributeData(key.c_str(), relayStates[i]);
  }
  Serial.println("Relay states sent as client attributes");
}

// Yêu cầu client attributes từ server
void requestClientAttributes() {
  Serial.println("Requesting client attributes...");
  // Chỉ cần gọi Client_Attributes_Request với callback
  tb.Client_Attributes_Request(Attribute_Request_Callback(processAttributeRequest));
}

// Task thực thi
void attributesTask(void *pvParameters) {
  Serial.println("Attributes task started");

  // Đăng ký RPC cho relay
  subscribed = false;
  if(tb.connected()) {
    for (int i = 0; i < RELAY_COUNT; i++) {
      String rpcName = "sw" + String(i + 1);
      tb.RPC_Subscribe(RPC_Callback(rpcName.c_str(), processRelayRPC));
    }
    // Đã đăng ký thành công
    subscribed = true;
    Serial.println("RPC subscribed successfully");
    
    // Yêu cầu client attributes ngay khi kết nối
    //requestClientAttributes();
  }

  const unsigned long updateInterval = attributesSendInterval;
  unsigned long lastUpdate = 0;
  unsigned long lastAttributeRequest = 0;
  const unsigned long attributeRequestInterval = 10000; // 10 giây

  for (;;) {
    unsigned long currentTime = millis();

    // Kiểm tra và cập nhật trạng thái theo chu kỳ
    if (currentTime - lastUpdate >= updateInterval) {
      lastUpdate = currentTime;

      bool isWifiConnected = false;
      bool isTbConnected = false;

      portENTER_CRITICAL(&wifiMux);
      isWifiConnected = wifiConnected;
      portEXIT_CRITICAL(&wifiMux);

      portENTER_CRITICAL(&tbMux);
      isTbConnected = coreiotConnected;
      portEXIT_CRITICAL(&tbMux);

      if (isWifiConnected && isTbConnected) {
        // Gửi trạng thái các relay lên client attributes
        sendRelayStates();
        requestClientAttributes();
      }
    }

    // Kiểm tra và đăng ký RPC nếu chưa đăng ký
    if (!subscribed) {
      if (tb.connected()) {
        for (int i = 0; i < RELAY_COUNT; i++) {
          String rpcName = "sw" + String(i + 1);
          tb.RPC_Subscribe(RPC_Callback(rpcName.c_str(), processRelayRPC));
        }
        subscribed = true;
        Serial.println("RPC subscribed successfully");
        
        // Yêu cầu client attributes khi đăng ký lại
        //requestClientAttributes();
      }
    }
    
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}

// Init task
void initAttributesTask() {
  xTaskCreatePinnedToCore(
    attributesTask,
    "AttributesTask",
    4096,
    NULL,
    1,
    &attributesTaskHandle,
    0
  );
}
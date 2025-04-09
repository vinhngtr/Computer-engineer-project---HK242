#include "attributes_task.h"
#include "config.h"

// Task handle
TaskHandle_t attributesTaskHandle = NULL;

// Định nghĩa trạng thái relay
std::array<bool, RELAY_COUNT> relayStates = {false, false, false, false, false, false};

// Biến lưu dữ liệu cảm biến đọc từ ThingsBoard về
float temperature = NAN;
float humidity = NAN;

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

// Callback nhận dữ liệu từ ThingsBoard (telemetry or shared attribute)
void handleSharedAttributeData(const Shared_Attribute_Data &data) {
  if (data.containsKey("temperature")) {
    temperature = data["temperature"].as<float>();
    Serial.print("Received temperature from server: ");
    Serial.println(temperature);
  }

  if (data.containsKey("humidity")) {
    humidity = data["humidity"].as<float>();
    Serial.print("Received humidity from server: ");
    Serial.println(humidity);
  }
}

// Gửi trạng thái các relay
void sendRelayStates() {
  for (int i = 0; i < RELAY_COUNT; i++) {
    String key = "sw" + String(i + 1);
    tb.sendAttributeData(key.c_str(), relayStates[i]);
  }
}

// Task thực thi
void attributesTask(void *pvParameters) {
  Serial.println("Attributes task started");

  for (int i = 0; i < RELAY_COUNT; i++) {
    pinMode(RELAY_PINS[i], OUTPUT);
    setRelay(i, false);
  }

  // Đăng ký RPC cho relay
  for (int i = 0; i < RELAY_COUNT; i++) {
    String rpcName = "sw" + String(i + 1);
    tb.RPC_Subscribe(RPC_Callback(rpcName.c_str(), processRelayRPC));
  }

  // Đăng ký nhận shared attributes
  tb.Shared_Attributes_Subscribe(Shared_Attribute_Callback(handleSharedAttributeData));


  const unsigned long updateInterval = attributesSendInterval;
  unsigned long lastUpdate = 0;

  for (;;) {
    unsigned long currentTime = millis();

    if (currentTime - lastUpdate >= updateInterval) {
      lastUpdate = currentTime;

      bool isWifiConnected = false;
      bool isTbConnected = false;
      bool isAttributesChanged = false;

      portENTER_CRITICAL(&wifiMux);
      isWifiConnected = wifiConnected;
      portEXIT_CRITICAL(&wifiMux);

      portENTER_CRITICAL(&tbMux);
      isTbConnected = coreiotConnected;
      portEXIT_CRITICAL(&tbMux);

      portENTER_CRITICAL(&ledMux);
      isAttributesChanged = attributesChanged;
      portEXIT_CRITICAL(&ledMux);

      if (isWifiConnected && isTbConnected && tb.connected()) {
        // Gửi thông tin WiFi
        tb.sendAttributeData("rssi", WiFi.RSSI());
        tb.sendAttributeData("channel", WiFi.channel());
        tb.sendAttributeData("bssid", WiFi.BSSIDstr().c_str());
        tb.sendAttributeData("localIp", WiFi.localIP().toString().c_str());
        tb.sendAttributeData("ssid", WiFi.SSID().c_str());

        // Gửi trạng thái LED nếu thay đổi
        if (isAttributesChanged) {
          bool currentLedState;
          portENTER_CRITICAL(&ledMux);
          currentLedState = ledState;
          attributesChanged = false;
          portEXIT_CRITICAL(&ledMux);

          tb.sendAttributeData(LED_STATE_ATTR, currentLedState);
          Serial.print("Sent updated LED state attribute: ");
          Serial.println(currentLedState);
        }

        // Gửi trạng thái các relay
        sendRelayStates();
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

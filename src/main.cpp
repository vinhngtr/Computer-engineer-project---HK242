#include "globals.h"
#include "ota_task.h"
#include "wifi_manager.h"
// ================= THINGBOARD LOOP ===================
// ThingsBoard objects
const uint32_t MAX_MESSAGE_SIZE = 1024U;
const char TOKEN[] = "db8bxxy2jbdedociwfn5";
//const char THINGSBOARD_PASSWORD[] = "iot_password";
//const char CLIENT_ID[]= "IOT_SERVER";
const char THINGSBOARD_SERVER[] = "app.coreiot.io";
const uint16_t THINGSBOARD_PORT = 1883U;

// Thông tin WiFi 
// const char *ssid = "vinh ngtr";
// const char *password = "vinhtrong782002";
// const char *mqtt_server = "io.adafruit.com";
// const char *mqtt_username = "vinhtrong782002";
// const char *mqtt_key = "aio_IDwi97EwGbXkbEqgGUo5Wvl87BUI";

// Định nghĩa chân I2C
const int SDA_PIN = 8;
const int SCL_PIN = 9;

// Topic MQTT cho điều khiển relay
// const char *RELAY_CONTROL_TOPIC = "vinhngtr/feeds/relays-control";

DHT20 dht20;
// WiFiClient espClient;
// PubSubClient client(espClient);

WiFiClient wifiClient;
Arduino_MQTT_Client mqttClient(wifiClient);
ThingsBoard tb(mqttClient, MAX_MESSAGE_SIZE);
bool wifiConnected = false;
bool tbConnected = false;

ThingsBoard& getTbInstance() {
  return tb;
}

// Biến kiểm soát thời gian
unsigned long previousMillis = 0;
const long interval = 15000;
///////////////Wifi//////////////////////
portMUX_TYPE wifiMux = portMUX_INITIALIZER_UNLOCKED;
portMUX_TYPE tbMux = portMUX_INITIALIZER_UNLOCKED;
String wifiSsid = "";
String wifiPassword = "";

// void connectWifi(void* pvParameters){
//   for (;;) {
//     bool isConnected = (WiFi.status() == WL_CONNECTED);
//     portENTER_CRITICAL(&wifiMux);
//     wifiConnected = isConnected;
//     portEXIT_CRITICAL(&wifiMux);
    
//     if (!isConnected) {
//       WiFi.disconnect();
//       WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//       // Wait for connection with timeout
//       int retry = 0;
//       while (WiFi.status() != WL_CONNECTED && retry < 20) {
//         vTaskDelay(pdMS_TO_TICKS(50));
//         retry++;
//       }
//       if (WiFi.status() == WL_CONNECTED) {
//         portENTER_CRITICAL(&wifiMux);
//         wifiConnected = true;
//         portEXIT_CRITICAL(&wifiMux);
//       }
//     }
//     // Check WiFi every 5 seconds
//     vTaskDelay(pdMS_TO_TICKS(3000));
//   }
// }

///////////////////////////////RELAY TASK////////////////////////////////

// Trạng thái relay (true = ON, false = OFF)
const int RELAY_PINS[6] = {
    GPIO_PIN_CH1, GPIO_PIN_CH2, GPIO_PIN_CH3, GPIO_PIN_CH4,
    GPIO_PIN_CH5, GPIO_PIN_CH6};

bool relayStates[6] = {false, false, false, false, false, false};
const char SW1_ATTR[] = "sw1";
const char SW2_ATTR[] = "sw2";
const char SW3_ATTR[] = "sw3";
const char SW4_ATTR[] = "sw4";
const char SW5_ATTR[] = "sw5";
const char SW6_ATTR[] = "sw6";
const char TEMPERATURE_ATTR[] = "temperature";
const char HUMIDITY_ATTR[] = "humidity";
// Shared attributes list
constexpr std::array<const char *, 10U> SHARED_ATTRIBUTES_LIST = {
  SW1_ATTR,  SW2_ATTR,  SW3_ATTR,
  SW4_ATTR,  SW5_ATTR,  SW6_ATTR,
  TEMPERATURE_ATTR,  HUMIDITY_ATTR
};

RPC_Callback callbacks[] = {
  { SW1_ATTR, [](const RPC_Data &data) {
      relayStates[0] = data;
      digitalWrite(RELAY_PINS[0], relayStates[0]);
      return RPC_Response();
    }
  },
  { SW2_ATTR, [](const RPC_Data &data) {
      relayStates[1] = data;
      digitalWrite(RELAY_PINS[1], relayStates[1]);
      return RPC_Response();
    }
  },
  { SW3_ATTR, [](const RPC_Data &data) {
      relayStates[2] = data;
      digitalWrite(RELAY_PINS[2], relayStates[2]);
      return RPC_Response("sw2","yes");
    }
  },
  { SW4_ATTR, [](const RPC_Data &data) {
      relayStates[3] = data;
      digitalWrite(RELAY_PINS[3], relayStates[3]);
      return RPC_Response();
    }
  },
  { SW5_ATTR, [](const RPC_Data &data) {
      relayStates[4] = data;
      digitalWrite(RELAY_PINS[4], relayStates[4]);
      return RPC_Response();
    }
  },
  { SW6_ATTR, [](const RPC_Data &data) {
      relayStates[5] = data;
      digitalWrite(RELAY_PINS[5], relayStates[5]);
      return RPC_Response();
    }
  }
};

void connectMQTT(void* pvParameters){
    //Serial.println("CoreIOT task started");
  for (;;) {
    bool isWifiConnected = false;
    portENTER_CRITICAL(&wifiMux);
    isWifiConnected = wifiConnected;
    portEXIT_CRITICAL(&wifiMux);
    if (isWifiConnected) {
      bool isTbConnected = tb.connected();
      portENTER_CRITICAL(&tbMux);
      tbConnected = isTbConnected;
      portEXIT_CRITICAL(&tbMux);
      if (!isTbConnected) {
        Serial.print("Connecting to CoreIOT: ");
        Serial.print(THINGSBOARD_SERVER);
        Serial.print(" with token ");
        Serial.println(TOKEN);
        if (tb.connect(THINGSBOARD_SERVER, TOKEN, THINGSBOARD_PORT)) {
        //if (tb.connect(THINGSBOARD_SERVER, TOKEN, THINGSBOARD_PORT,CLIENT_ID,THINGSBOARD_PASSWORD)) {
          Serial.println("Connected to CoreIOT");
          for (size_t i = 0; i < sizeof(callbacks) / sizeof(callbacks[0]); ++i) {
            tb.RPC_Subscribe(callbacks[i]);
          }
          portENTER_CRITICAL(&tbMux);
          tbConnected = true;
          portEXIT_CRITICAL(&tbMux);
        } else {
          Serial.println("Failed to connect to CoreIOT");
        }
      }
    }
    bool isTbConnected = tb.connected();
    // Check CoreIOT connection every 3 seconds
    vTaskDelay(pdMS_TO_TICKS(2000));
  }
}

void tbLoop(void *pvParameters) {
  Serial.println("ThingsBoard loop task started");
  
  for (;;) {
    bool isWifiConnected = false;
    bool isTbConnected = false;

    portENTER_CRITICAL(&wifiMux);
    isWifiConnected = wifiConnected;
    portEXIT_CRITICAL(&wifiMux);

    portENTER_CRITICAL(&tbMux);
    isTbConnected = tbConnected;
    portEXIT_CRITICAL(&tbMux);
    
    if (isWifiConnected && isTbConnected) {
      // Process ThingsBoard messages
      tb.loop();
      //set_tb_stat(isTbConnected);
      Serial.println("Connected to CoreIOT");
    }
    // Run the loop frequently for better responsiveness
    vTaskDelay(pdMS_TO_TICKS(50));
  }
}

void readSensorTask(void *pvParameters) {
  Serial.println("Sensor task started");

  for (;;) {
    bool isWifiConnected = false;
    bool isTbConnected = false;

    portENTER_CRITICAL(&wifiMux);
    isWifiConnected = wifiConnected;
    portEXIT_CRITICAL(&wifiMux);

    portENTER_CRITICAL(&tbMux);
    isTbConnected = tbConnected;
    portEXIT_CRITICAL(&tbMux);

    if (isWifiConnected && isTbConnected) {
      float temperature = 0.0f;
      float humidity = 0.0f;
      int status = dht20.read();
      if (status == DHT20_OK ) {
        temperature = dht20.getTemperature();
        humidity = dht20.getHumidity();
        Serial.print("Temp: ");
        Serial.print(temperature);
        Serial.print("°C, Hum: ");
        Serial.print(humidity);
        Serial.println("%");
        IPAddress ip = WiFi.localIP();     // Lấy địa chỉ IP
        String ipStr = ip.toString();      // Chuyển sang chuỗi

        tb.sendTelemetryData("IP", ipStr.c_str());
        tb.sendTelemetryData(TEMPERATURE_ATTR, temperature);
        tb.sendTelemetryData(HUMIDITY_ATTR, humidity);
      } else {
        Serial.println("Error reading DHT20");
      }
    }
    // Gửi mỗi 15 giây
    vTaskDelay(pdMS_TO_TICKS(5000));
  }
}
// void setupOTA() {
//   // Cấu hình OTA
//   ArduinoOTA
//     .onStart([]() {
//       Serial.println("Start updating via OTA");
//     })
//     .onEnd([]() {
//       Serial.println("\nOTA Update End");
//     })
//     .onProgress([](unsigned int progress, unsigned int total) {
//       Serial.printf("OTA Progress: %u%%\r", (progress / (total / 100)));
//     })
//     .onError([](ota_error_t error) {
//       Serial.printf("OTA Error[%u]: ", error);
//       if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
//       else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
//       else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
//       else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
//       else if (error == OTA_END_ERROR) Serial.println("End Failed");
//     });

//   ArduinoOTA.begin();

//   // Tạo task xử lý ArduinoOTA.handle()
//   xTaskCreatePinnedToCore([](void *pv) {
//     for (;;) {
//       ArduinoOTA.handle();
//       vTaskDelay(pdMS_TO_TICKS(100));
//     }
//   }, "OTA Task", 4096, NULL, 1, NULL, 1);
// }

void setup()
{
    Serial.begin(115200);
    // Khởi tạo các chân relay
    for (int i = 0; i < 6; i++)
    {
        pinMode(RELAY_PINS[i], OUTPUT);
        digitalWrite(RELAY_PINS[i], LOW); // Tắt tất cả relay ban đầu
    }

    // Khởi tạo I2C với các chân SDA và SCL cụ thể
    Wire.begin(SDA_PIN, SCL_PIN);
    dht20.begin();
  startWiFiManager();
      // Tạo các task
  // xTaskCreatePinnedToCore(
  //   connectWifi, "WiFi Task", 4096, NULL, 1, NULL, 0);

  xTaskCreatePinnedToCore(
    connectMQTT, "MQTT Task", 4096, NULL, 1, NULL, 0);

  xTaskCreatePinnedToCore(
    tbLoop, "TB Loop", 4096, NULL, 1, NULL, 1);

  xTaskCreatePinnedToCore(
    readSensorTask, "Sensor Task", 4096, NULL, 1, NULL, 1);
  // setupOTA();
  initOtaTask("my_device", "1.0.2");
}
void loop()
{
  wifiConnected = WiFi.status() == WL_CONNECTED;
    // if (!client.connected())
    // {
    //     reconnect();
    // }
    // client.loop();

    // Kiểm tra thời gian để gửi dữ liệu mỗi 50 giây
    // unsigned long currentMillis = millis();
    // if (currentMillis - previousMillis >= interval)
    // {
    //     previousMillis = currentMillis;

    //     // Đọc dữ liệu từ DHT20
    //     int status = dht20.read();
    //     if (status == DHT20_OK)
    //     {
    //         float temp = dht20.getTemperature();
    //         float hum = dht20.getHumidity();

    //         // Gửi dữ liệu lên Adafruit IO
    //         String tempTopic = String(mqtt_username) + "/feeds/temperature";
    //         String humTopic = String(mqtt_username) + "/feeds/humidity";
    //         client.publish(tempTopic.c_str(), String(temp).c_str());
    //         client.publish(humTopic.c_str(), String(hum).c_str());

    //         // In thông tin để debug
    //         Serial.print("Temperature: ");
    //         Serial.print(temp);
    //         Serial.print(" °C, Humidity: ");
    //         Serial.print(hum);
    //         Serial.println(" %");
    //     }
    //     else
    //     {
    //         Serial.println("Error reading DHT20");
    //     }
    // }
}
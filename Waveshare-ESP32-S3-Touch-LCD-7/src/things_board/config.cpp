#include "config.h"

// WiFi and ThingsBoard credentials

const char WIFI_SSID[] PROGMEM = "Guest";
const char WIFI_PASSWORD[] PROGMEM = "12345678";
const char TOKEN[] = "vns9s1vqy67gnpfccc6c";
const char THINGSBOARD_PASSWORD[] = "iot_password";
const char CLIENT_ID[]= "IOT_SERVER";
const char THINGSBOARD_SERVER[] = "app.coreiot.io";
const uint16_t THINGSBOARD_PORT = 1883U;

// Constants
const uint32_t MAX_MESSAGE_SIZE = 1024U;
const uint32_t SERIAL_DEBUG_BAUD = 115200U;
const char BLINKING_INTERVAL_ATTR[] = "blinkingInterval";
const char LED_MODE_ATTR[] = "ledMode";
const char LED_STATE_ATTR[] = "ledState";
const char SW1_ATTR[] = "sw1";
const char SW2_ATTR[] = "sw2";
const char SW3_ATTR[] = "sw3";
const char SW4_ATTR[] = "sw4";
const char SW5_ATTR[] = "sw5";
const char SW6_ATTR[] = "sw6";
const char TEMPERATURE_ATTR[] = "temperature";
const char HUMIDITY_ATTR[] = "humidity";

const uint16_t BLINKING_INTERVAL_MS_MIN = 10U;
const uint16_t BLINKING_INTERVAL_MS_MAX = 60000U;

// Global variables
volatile bool attributesChanged = false;
volatile int ledMode = 0;
volatile bool ledState = false;
volatile float currentTemperature = 0.0;
volatile float currentHumidity = 0.0;
volatile bool switchStates[6] = {false};  // sw1 -> switchStates[0], sw2 -> switchStates[1], ...


volatile uint16_t blinkingInterval = 1000U;
const int16_t telemetrySendInterval = 10000U;
const int16_t attributesSendInterval = 5000U;

// Mutex handles
portMUX_TYPE wifiMux = portMUX_INITIALIZER_UNLOCKED;
portMUX_TYPE tbMux = portMUX_INITIALIZER_UNLOCKED;
portMUX_TYPE ledMux = portMUX_INITIALIZER_UNLOCKED;
// Mux cho các công tắc sw1 - sw6
portMUX_TYPE swMux = portMUX_INITIALIZER_UNLOCKED;
// Mux cho nhiệt độ và độ ẩm
portMUX_TYPE sensorMux = portMUX_INITIALIZER_UNLOCKED;

// Status flags
volatile bool wifiConnected = false;
volatile bool coreiotConnected = false;
volatile bool subscribed = false;

// ThingsBoard objects
WiFiClient wifiClient;
Arduino_MQTT_Client mqttClient(wifiClient);
ThingsBoard tb(mqttClient, MAX_MESSAGE_SIZE);

// Shared attributes list
constexpr std::array<const char *, 10U> SHARED_ATTRIBUTES_LIST = {
  LED_STATE_ATTR,
  BLINKING_INTERVAL_ATTR,
  SW1_ATTR,
  SW2_ATTR,
  SW3_ATTR,
  SW4_ATTR,
  SW5_ATTR,
  SW6_ATTR,
  TEMPERATURE_ATTR,
  HUMIDITY_ATTR
};



// RPC callback for LED switch state
RPC_Response setLedSwitchState(const RPC_Data &data) {
  Serial.println("Received Switch state");
  bool newState = data;
  Serial.print("Switch state change: ");
  Serial.println(newState);
  
  // Update LED state
  portENTER_CRITICAL(&ledMux);
  ledState = newState;
  attributesChanged = true;
  portEXIT_CRITICAL(&ledMux);
  
  digitalWrite(LED_PIN, newState);
  
  return RPC_Response("setLedSwitchValue", newState);
}


// Process shared attributes callback
void processSharedAttributes(const Shared_Attribute_Data &data) {
for (auto it = data.begin(); it != data.end(); ++it) {
  if (strcmp(it->key().c_str(), BLINKING_INTERVAL_ATTR) == 0) {
    const uint16_t new_interval = it->value().as<uint16_t>();
    if (new_interval >= BLINKING_INTERVAL_MS_MIN && new_interval <= BLINKING_INTERVAL_MS_MAX) {
      portENTER_CRITICAL(&ledMux);
      blinkingInterval = new_interval;
      portEXIT_CRITICAL(&ledMux);
      
      Serial.print("Blinking interval is set to: ");
      Serial.println(new_interval);
    }
  } else if (strcmp(it->key().c_str(), LED_STATE_ATTR) == 0) {
    bool new_state = it->value().as<bool>();
    
    portENTER_CRITICAL(&ledMux);
    ledState = new_state;
    portEXIT_CRITICAL(&ledMux);
    
    digitalWrite(LED_PIN, new_state);
    Serial.print("LED state is set to: ");
    Serial.println(new_state);
  } else  if (strcmp(it->key().c_str(), SW1_ATTR) == 0) {
      bool sw1 = it->value().as<bool>();
      portENTER_CRITICAL(&swMux);
      switchStates[0] = sw1;
      portEXIT_CRITICAL(&swMux);
      Serial.print("sw1: ");
      Serial.println(sw1);
  } else if (strcmp(it->key().c_str(), SW2_ATTR) == 0) {
      bool sw2 = it->value().as<bool>();
      portENTER_CRITICAL(&swMux);
      switchStates[1] = sw2;
      portEXIT_CRITICAL(&swMux);
      Serial.print("sw2: ");
      Serial.println(sw2);
  } else if (strcmp(it->key().c_str(), SW3_ATTR) == 0) {
      bool sw3 = it->value().as<bool>();
      portENTER_CRITICAL(&swMux);
      switchStates[2] = sw3;
      portEXIT_CRITICAL(&swMux);
      Serial.print("sw3: ");
      Serial.println(sw3);
  } else if (strcmp(it->key().c_str(), SW4_ATTR) == 0) {
      bool sw4 = it->value().as<bool>();
      portENTER_CRITICAL(&swMux);
      switchStates[3] = sw4;
      portEXIT_CRITICAL(&swMux);
      Serial.print("sw4: ");
      Serial.println(sw4);
  } else if (strcmp(it->key().c_str(), SW5_ATTR) == 0) {
      bool sw5 = it->value().as<bool>();
      portENTER_CRITICAL(&swMux);
      switchStates[4] = sw5;
      portEXIT_CRITICAL(&swMux);
      Serial.print("sw5: ");
      Serial.println(sw5);
  } else if (strcmp(it->key().c_str(), SW6_ATTR) == 0) {
      bool sw6 = it->value().as<bool>();
      portENTER_CRITICAL(&swMux);
      switchStates[5] = sw6;
      portEXIT_CRITICAL(&swMux);
      Serial.print("sw6: ");
      Serial.println(sw6);
  } else if (strcmp(it->key().c_str(), TEMPERATURE_ATTR) == 0) {
    float temp = it->value().as<float>();
    portENTER_CRITICAL(&sensorMux);
    currentTemperature = temp;
    portEXIT_CRITICAL(&sensorMux);
    Serial.print("Set shared temperature: ");
    Serial.println(temp);
  }
  
  else if (strcmp(it->key().c_str(), HUMIDITY_ATTR) == 0) {
    float hum = it->value().as<float>();
    portENTER_CRITICAL(&sensorMux);
    currentHumidity = hum;
    portEXIT_CRITICAL(&sensorMux);
    Serial.print("Set shared humidity: ");
    Serial.println(hum);
  }

}

portENTER_CRITICAL(&ledMux);
attributesChanged = true;
portEXIT_CRITICAL(&ledMux);
}

// LED blinking function
void handleLed() {
static unsigned long lastToggleTime = 0;
unsigned long currentTime = millis();

int currentLedMode;
uint16_t currentBlinkingInterval;

portENTER_CRITICAL(&ledMux);
currentLedMode = ledMode;
currentBlinkingInterval = blinkingInterval;
portEXIT_CRITICAL(&ledMux);

if (currentLedMode == 1 && currentTime - lastToggleTime >= currentBlinkingInterval) {
  lastToggleTime = currentTime;
  
  // Toggle LED state
  portENTER_CRITICAL(&ledMux);
  ledState = !ledState;
  attributesChanged = true;
  portEXIT_CRITICAL(&ledMux);
  
  digitalWrite(LED_PIN, ledState);
}
}
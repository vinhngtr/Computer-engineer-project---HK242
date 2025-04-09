#include "config.h"

// WiFi and ThingsBoard credentials

const char WIFI_SSID[] PROGMEM = "abcd";
const char WIFI_PASSWORD[] PROGMEM = "123456789";
const char TOKEN[] = "xvy273e9xiej7c8ll8ln";
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
const uint16_t BLINKING_INTERVAL_MS_MIN = 10U;
const uint16_t BLINKING_INTERVAL_MS_MAX = 60000U;

// Global variables
volatile bool attributesChanged = false;
volatile int ledMode = 0;
volatile bool ledState = false;
volatile uint16_t blinkingInterval = 1000U;
const int16_t telemetrySendInterval = 10000U;
const int16_t attributesSendInterval = 5000U;

// Mutex handles
portMUX_TYPE wifiMux = portMUX_INITIALIZER_UNLOCKED;
portMUX_TYPE tbMux = portMUX_INITIALIZER_UNLOCKED;
portMUX_TYPE ledMux = portMUX_INITIALIZER_UNLOCKED;

// Status flags
volatile bool wifiConnected = false;
volatile bool coreiotConnected = false;
volatile bool subscribed = false;

// ThingsBoard objects
WiFiClient wifiClient;
Arduino_MQTT_Client mqttClient(wifiClient);
ThingsBoard tb(mqttClient, MAX_MESSAGE_SIZE);

// Shared attributes list
constexpr std::array<const char *, 2U> SHARED_ATTRIBUTES_LIST = {
  LED_STATE_ATTR,
  BLINKING_INTERVAL_ATTR
};

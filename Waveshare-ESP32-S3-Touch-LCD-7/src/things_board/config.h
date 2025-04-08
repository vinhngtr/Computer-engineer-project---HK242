#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <WiFi.h>
#include <Arduino_MQTT_Client.h>
#include <ThingsBoard.h>
#include "Wire.h"
#include <ArduinoOTA.h>

// Pin definitions
#define LED_PIN 48

// WiFi and ThingsBoard credentials
extern const char WIFI_SSID[];
extern const char WIFI_PASSWORD[];
extern const char TOKEN[];
extern const char THINGSBOARD_PASSWORD[];
extern const char CLIENT_ID[];
extern const char THINGSBOARD_SERVER[];
extern const uint16_t THINGSBOARD_PORT;

// Constants
extern const uint32_t MAX_MESSAGE_SIZE;
extern const uint32_t SERIAL_DEBUG_BAUD;
extern const char BLINKING_INTERVAL_ATTR[];
extern const char LED_MODE_ATTR[];
extern const char LED_STATE_ATTR[];
extern const uint16_t BLINKING_INTERVAL_MS_MIN;
extern const uint16_t BLINKING_INTERVAL_MS_MAX;

// Global variables
extern volatile bool attributesChanged;
extern volatile int ledMode;
extern volatile bool ledState;
extern volatile uint16_t blinkingInterval;
extern const int16_t telemetrySendInterval;
extern const int16_t attributesSendInterval;

// Mutex handles
extern portMUX_TYPE wifiMux;
extern portMUX_TYPE tbMux;
extern portMUX_TYPE ledMux;

// Status flags
extern volatile bool wifiConnected;
extern volatile bool coreiotConnected;
extern volatile bool subscribed;

// ThingsBoard objects
extern WiFiClient wifiClient;
extern Arduino_MQTT_Client mqttClient;
extern ThingsBoard tb;

// // Function declarations for callbacks
// RPC_Response setLedSwitchState(const RPC_Data &data);
// void processSharedAttributes(const Shared_Attribute_Data &data);

// // Handle LED blinking
// void handleLed();

#endif // CONFIG_H
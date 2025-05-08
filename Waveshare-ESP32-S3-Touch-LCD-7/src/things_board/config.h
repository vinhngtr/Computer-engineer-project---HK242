#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <WiFi.h>
#include <Arduino_MQTT_Client.h>
#include <ThingsBoard.h>
#include <array>
#include <Wire.h>
#include <ArduinoOTA.h>
#include "ui.h"

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
extern const char SW1_ATTR[];
extern const char SW2_ATTR[];
extern const char SW3_ATTR[];
extern const char SW4_ATTR[];
extern const char SW5_ATTR[];
extern const char SW6_ATTR[];
extern const char TEMPERATURE_ATTR[];
extern const char HUMIDITY_ATTR[];
extern const uint16_t BLINKING_INTERVAL_MS_MIN;
extern const uint16_t BLINKING_INTERVAL_MS_MAX;

// Global variables
extern volatile bool attributesChanged;
extern volatile int ledMode;
extern volatile bool ledState;
extern volatile float currentTemperature;
extern volatile float currentHumidity;
extern volatile bool switchStates[6];
extern volatile uint16_t blinkingInterval;
extern const int16_t telemetrySendInterval;
extern const int16_t attributesSendInterval;

// Mutex handles
extern portMUX_TYPE wifiMux;
extern portMUX_TYPE tbMux;
extern portMUX_TYPE ledMux;
extern portMUX_TYPE swMux;
extern portMUX_TYPE sensorMux;

// Status flags
extern volatile bool wifiConnected;
extern volatile bool coreiotConnected;
extern volatile bool subscribed;

// ThingsBoard objects
extern WiFiClient wifiClient;
extern Arduino_MQTT_Client mqttClient;
extern ThingsBoard tb;

// Shared attributes list
extern const std::array<const char *, 10U> SHARED_ATTRIBUTES_LIST;

#endif // CONFIG_H

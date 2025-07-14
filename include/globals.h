#ifndef GLOBALS_H
#define GLOBALS_H

#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT20.h>
#include <Wire.h>
#include <Arduino.h>
#include <ArduinoJson.h>
#include <Thingsboard.h>
#include <Arduino_MQTT_Client.h>
#include <ArduinoOTA.h>
// DEFINE RELAYS
#ifndef GPIO_PIN_CH1
#define GPIO_PIN_CH1 1
#endif

#ifndef GPIO_PIN_CH2
#define GPIO_PIN_CH2 2
#endif

#ifndef GPIO_PIN_CH3
#define GPIO_PIN_CH3 3
#endif

#ifndef GPIO_PIN_CH4
#define GPIO_PIN_CH4 4
#endif

#ifndef GPIO_PIN_CH5
#define GPIO_PIN_CH5 5
#endif

#ifndef GPIO_PIN_CH6
#define GPIO_PIN_CH6 6
#endif

extern bool wifiConnected;

#endif
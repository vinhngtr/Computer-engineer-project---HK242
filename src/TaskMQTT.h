#ifndef INC_TASKMQTT_H_
#define INC_TASKMQTT_H_
#include <Arduino.h>
#include <WiFi.h>
#include <ui.h>
#include <Wire.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>





extern float globalTemperature;
extern float globalHumidity;
extern PubSubClient client; // Khai báo extern

void mqttTask(void *pvParameters);

#endif /* INC_TASKMQTT_H_ */
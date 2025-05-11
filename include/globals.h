#include <Arduino.h>
#include <WiFi.h>
#include <lvgl.h>
#include <ESP_Panel_Library.h>
#include <ESP_IOExpander_Library.h>
#include <ui.h>
#include <Wire.h>
#include <PubSubClient.h>
#include "LittleFS.h"
#include "SPIFFS.h"
#include <TaskMobus.h>
#include <ArduinoJson.h>


#define delay_connect 100
#define MQTT_SERVER "io.adafruit.com"
#define MQTT_PORT 1883
#define IO_USERNAME "vinhtrong782002"
#define IO_KEY "aio_Jurz04TDyrKkT2wVdyKLjeIYNifA"

// Extend IO Pin define
#define TP_RST 1
#define LCD_BL 2
#define LCD_RST 3
#define SD_CS 4
#define USB_SEL 5

// I2C Pin define
#define I2C_MASTER_NUM 0
#define I2C_MASTER_SDA_IO 8
#define I2C_MASTER_SCL_IO 9
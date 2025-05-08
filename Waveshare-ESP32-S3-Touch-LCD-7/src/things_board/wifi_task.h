#ifndef WIFI_TASK_H
#define WIFI_TASK_H

#include "config.h"
#include "ui.h"
// WiFi task function declaration
void wifiTask(void *pvParameters);
extern lv_obj_t * ui_WifiState;
// Initialize WiFi task
void initWiFiTask();

#endif // WIFI_TASK_H
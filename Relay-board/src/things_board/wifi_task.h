#ifndef WIFI_TASK_H
#define WIFI_TASK_H

#include "config.h"

// WiFi task function declaration
void wifiTask(void *pvParameters);

// Initialize WiFi task
void initWiFiTask();

#endif // WIFI_TASK_H
#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H
#include "globals.h"
#include <WiFi.h>
#include <WebServer.h>
#include <Preferences.h>

// Thay đổi nếu muốn đặt tên/mật khẩu khác cho AP
#define WIFI_AP_SSID     "ESP32-Relay"
#define WIFI_AP_PASSWORD "12345678"

#define WIFI_CRED_NAMESPACE "wifiCreds"
#define WIFI_TASK_DELAY_MS 3000
extern bool wifiConnected;
void startWiFiManager();         // Gọi từ setup()
bool isWiFiConnected();          // Đọc trạng thái WiFi

#endif // WIFI_MANAGER_H

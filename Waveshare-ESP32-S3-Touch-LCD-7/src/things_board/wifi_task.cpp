#include "wifi_task.h"

// Task handle for WiFi task
TaskHandle_t wifiTaskHandle = NULL;
void set_wifi_state(bool connected) {
  if (connected) {
      lv_obj_add_state(ui_WifiState, LV_STATE_CHECKED);
      lv_label_set_text(ui_WifiState, "Wifi");
  } else {
      lv_obj_clear_state(ui_WifiState, LV_STATE_CHECKED);
      lv_label_set_text(ui_WifiState, "Wifi");
  }
}

// WiFi task function implementation
void wifiTask(void *pvParameters) {
  Serial.println("WiFi task started");
  
  for (;;) {
    bool isConnected = (WiFi.status() == WL_CONNECTED);
    
    portENTER_CRITICAL(&wifiMux);
    wifiConnected = isConnected;
    portEXIT_CRITICAL(&wifiMux);
    
    if (!isConnected) {
      Serial.println("WiFi disconnected. Attempting to reconnect...");
      
      WiFi.disconnect();
      WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
      
      // Wait for connection with timeout
      int attempts = 0;
      while (WiFi.status() != WL_CONNECTED && attempts < 20) {
        vTaskDelay(pdMS_TO_TICKS(500));
        Serial.print(".");
        attempts++;
      }
      
      if (WiFi.status() == WL_CONNECTED) {
        Serial.println("WiFi reconnected to AP");
        portENTER_CRITICAL(&wifiMux);
        wifiConnected = true;
        portEXIT_CRITICAL(&wifiMux);
      } else {
        Serial.println("Failed to reconnect to WiFi");
      }
    }
    else{
      ui_WifiState ;
    }
    set_wifi_state(isConnected);
    // Check WiFi every 5 seconds
    vTaskDelay(pdMS_TO_TICKS(5000));
  }
}

// Initialize WiFi task
void initWiFiTask() {
  // Create WiFi monitoring task
  xTaskCreatePinnedToCore(
    wifiTask,           // Task function
    "WiFiTask",         // Name
    4096,               // Stack size
    NULL,               // Parameters
    1,                  // Priority
    &wifiTaskHandle,    // Task handle
    0                   // Run on core 0
  );
}
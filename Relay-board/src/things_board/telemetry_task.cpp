#include "telemetry_task.h"

// Task handle for Telemetry task
TaskHandle_t telemetryTaskHandle = NULL;

// Telemetry task function implementation
void telemetryTask(void *pvParameters) {
  Serial.println("Telemetry task started");
  unsigned long lastSendTime = 0;
  
  for (;;) {
    unsigned long currentTime = millis();
    
    if (currentTime - lastSendTime >= telemetrySendInterval) {
      lastSendTime = currentTime;
      
      bool isWifiConnected = false;
      bool isTbConnected = false;
      
      portENTER_CRITICAL(&wifiMux);
      isWifiConnected = wifiConnected;
      portEXIT_CRITICAL(&wifiMux);
      
      portENTER_CRITICAL(&tbMux);
      isTbConnected = coreiotConnected;
      portEXIT_CRITICAL(&tbMux);
      
      if (isWifiConnected && isTbConnected) {
        // Read sensor data
        float temperature = readRS485Temperature();
        float humidity = readRS485Humidity();
        
        if (!isnan(temperature) && !isnan(humidity)) {
          Serial.print("Sending telemetry - Temperature: ");
          Serial.print(temperature);
          Serial.print(" °C, Humidity: ");
          Serial.print(humidity);
          Serial.println(" %");
          
          // Send telemetry data if still connected
          if (tb.connected()) {
            tb.sendTelemetryData("temperature", temperature);
            tb.sendTelemetryData("humidity", humidity);
          }
        } else {
          Serial.println("Failed to read from DHT20 sensor!");
        }
      }
    }
    
    vTaskDelay(pdMS_TO_TICKS(1000));;
  }
}

// Initialize Telemetry task
void initTelemetryTask() {
  // Create Telemetry task
  xTaskCreatePinnedToCore(
    telemetryTask,      // Task function
    "TelemetryTask",    // Name
    4096,               // Stack size
    NULL,               // Parameters
    1,                  // Priority
    &telemetryTaskHandle, // Task handle
    0                   // Run on core 0
  );
}
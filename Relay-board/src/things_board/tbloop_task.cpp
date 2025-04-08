#include "tbloop_task.h"

// Task handle for ThingsBoard loop task
TaskHandle_t tbLoopTaskHandle = NULL;

// ThingsBoard loop task function implementation
void tbLoopTask(void *pvParameters) {
  Serial.println("ThingsBoard loop task started");
  
  for (;;) {
    bool isWifiConnected = false;
    bool isTbConnected = false;
    
    portENTER_CRITICAL(&wifiMux);
    isWifiConnected = wifiConnected;
    portEXIT_CRITICAL(&wifiMux);
    
    portENTER_CRITICAL(&tbMux);
    isTbConnected = coreiotConnected;
    portEXIT_CRITICAL(&tbMux);
    
    if (isWifiConnected && isTbConnected) {
      // Process ThingsBoard messages
      tb.loop();
    }
    
    // Run the loop frequently for better responsiveness
    vTaskDelay(pdMS_TO_TICKS(50));
  }
}

// Initialize ThingsBoard loop task
void initTbLoopTask() {
  // Create ThingsBoard loop task
  xTaskCreatePinnedToCore(
    tbLoopTask,         // Task function
    "TbLoopTask",       // Name
    4096,               // Stack size
    NULL,               // Parameters
    3,                  // Priority (highest for responsiveness)
    &tbLoopTaskHandle,  // Task handle
    0                   // Run on core 0
  );
}
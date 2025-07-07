#include "coreiot_task.h"

// Task handle for CoreIOT task
TaskHandle_t coreiotTaskHandle = NULL;


void set_tb_state(bool connected) {
  if (connected) {
      lv_obj_add_state(ui_TBState, LV_STATE_CHECKED);
      lv_label_set_text(ui_TBState, "  TB  ");
  } else {
      lv_obj_clear_state(ui_TBState, LV_STATE_CHECKED);
      lv_label_set_text(ui_TBState, "  TB  ");
  }
}


// CoreIOT task function implementation
void coreiotTask(void *pvParameters) {
  //Serial.println("CoreIOT task started");
  
  for (;;) {
    bool isWifiConnected = false;
    
    portENTER_CRITICAL(&wifiMux);
    isWifiConnected = wifiConnected;
    portEXIT_CRITICAL(&wifiMux);
    
    if (isWifiConnected) {
      bool isTbConnected = tb.connected();
      
      portENTER_CRITICAL(&tbMux);
      coreiotConnected = isTbConnected;
      portEXIT_CRITICAL(&tbMux);
      
      if (!isTbConnected) {
        // Serial.print("Connecting to CoreIOT: ");
        // Serial.print(THINGSBOARD_SERVER);
        // Serial.print(" with token ");
        // Serial.println(TOKEN);
        Serial.print("Connecting to ");
        Serial.print(THINGSBOARD_SERVER);
        Serial.print(" with ID ");
        Serial.print(CLIENT_ID);
        Serial.print(" and password ");
        Serial.println(THINGSBOARD_PASSWORD);

        if (tb.connect(THINGSBOARD_SERVER, TOKEN, THINGSBOARD_PORT)) {
        //if (tb.connect(THINGSBOARD_SERVER, TOKEN, THINGSBOARD_PORT,CLIENT_ID,THINGSBOARD_PASSWORD)) {

          Serial.println("Connected to CoreIOT");
          
          portENTER_CRITICAL(&tbMux);
          coreiotConnected = true;
          //subscribed = false;  // Need to resubscribe
          portEXIT_CRITICAL(&tbMux);
        } else {
          Serial.println("Failed to connect to CoreIOT");
        }
      }
      
      
      // Check subscription status
      bool isSubscribed = false;
      portENTER_CRITICAL(&tbMux);
      isSubscribed = subscribed;
      portEXIT_CRITICAL(&tbMux);
    }
    bool isTbConnected = tb.connected();
    //set_tb_state(isTbConnected);
    // Check CoreIOT connection every 3 seconds
    vTaskDelay(pdMS_TO_TICKS(3000));
  }
}

// Initialize CoreIOT task
void initCoreIOTTask() {
  // Create CoreIOT connection task
  xTaskCreatePinnedToCore(
    coreiotTask,        // Task function
    "CoreIOTTask",      // Name
    8192,               // Stack size (larger for MQTT operations)
    NULL,               // Parameters
    2,                  // Priority
    &coreiotTaskHandle, // Task handle
    0                   // Run on core 0
  );
}
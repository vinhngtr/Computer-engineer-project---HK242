#include "coreiot_task.h"

// Task handle for CoreIOT task
TaskHandle_t coreiotTaskHandle = NULL;

// Shared attributes list
constexpr std::array<const char *, 2U> SHARED_ATTRIBUTES_LIST = {
  LED_STATE_ATTR,
  BLINKING_INTERVAL_ATTR
};

// RPC callbacks array
const std::array<RPC_Callback, 1U> callbacks = {
  RPC_Callback{ "setLedSwitchValue", setLedSwitchState }
};

// Attribute callbacks
const Shared_Attribute_Callback attributes_callback(&processSharedAttributes, SHARED_ATTRIBUTES_LIST.cbegin(), SHARED_ATTRIBUTES_LIST.cend());
const Attribute_Request_Callback attribute_shared_request_callback(&processSharedAttributes, SHARED_ATTRIBUTES_LIST.cbegin(), SHARED_ATTRIBUTES_LIST.cend());

// CoreIOT task function implementation
void coreiotTask(void *pvParameters) {
  Serial.println("CoreIOT task started");
  
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

        
        // if (tb.connect(THINGSBOARD_SERVER, TOKEN, THINGSBOARD_PORT)) {
        if (tb.connect(THINGSBOARD_SERVER, TOKEN, THINGSBOARD_PORT,CLIENT_ID,THINGSBOARD_PASSWORD)) {

          Serial.println("Connected to CoreIOT");
          
          portENTER_CRITICAL(&tbMux);
          coreiotConnected = true;
          subscribed = false;  // Need to resubscribe
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
      
      bool isTbStillConnected = tb.connected();
      if (isTbStillConnected && !isSubscribed) {
        // Subscribe for RPC
        Serial.println("Subscribing for RPC...");
        bool rpcSubscribed = tb.RPC_Subscribe(callbacks.cbegin(), callbacks.cend());
        
        // Subscribe for shared attributes
        Serial.println("Subscribing for shared attributes...");
        bool attrSubscribed = tb.Shared_Attributes_Subscribe(attributes_callback);
        
        // Request shared attributes
        Serial.println("Requesting shared attributes...");
        bool attrRequested = tb.Shared_Attributes_Request(attribute_shared_request_callback);
        
        if (rpcSubscribed && attrSubscribed && attrRequested) {
          Serial.println("All subscriptions successful");
          portENTER_CRITICAL(&tbMux);
          subscribed = true;
          portEXIT_CRITICAL(&tbMux);
          
          // Send device MAC address after successful connection
          tb.sendAttributeData("macAddress", WiFi.macAddress().c_str());
        } else {
          Serial.println("Subscription failed, will retry");
        }
      }
    }
    
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
#include <Arduino.h>
#include "tb.h"
void setup() {
  // Initialize serial
  Serial.begin(SERIAL_DEBUG_BAUD);
  delay(1000);
  Serial.println("ESP32 RTOS with 5 tasks starting...");
  
  // Set up GPIO
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, ledState);
  
  // Initialize I2C for DHT20
  Wire.begin(SDA_PIN, SCL_PIN);
  initRS485();
  
  // Initial connection to WiFi
  Serial.println("Initial WiFi connection...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    Serial.print(".");
    attempts++;
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to AP");
    wifiConnected = true;
  } else {
    Serial.println("Initial WiFi connection failed, tasks will handle reconnection");
  }
  
  // Initialize all tasks
  initWiFiTask();
  initCoreIOTTask();
  initTelemetryTask();
  initAttributesTask();
  initTbLoopTask();
  
  Serial.println("All tasks created and started");
}

void loop() {
  // Handle LED blinking in the main loop on core 1
  handleLed();
  
  // Short delay to prevent watchdog issues
  delay(10);
}
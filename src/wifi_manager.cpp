#include "wifi_manager.h"

static WebServer server(80);
static Preferences preferences;
static TaskHandle_t wifiTaskHandle = nullptr;
bool wifiConnected = false;

static void handleRoot() {
  String html = "<html><body><h2>ESP32 WiFi Config</h2>";
  html += "<form action=\"/save\" method=\"POST\">";
  html += "SSID: <input type=\"text\" name=\"ssid\"><br>";
  html += "Password: <input type=\"password\" name=\"password\"><br>";
  html += "<input type=\"submit\" value=\"Save\">";
  html += "</form></body></html>";
  server.send(200, "text/html", html);
}

static void handleSave() {
  String ssid = server.arg("ssid");
  String password = server.arg("password");

  if (ssid.length() > 0 && password.length() > 0) {
    preferences.begin(WIFI_CRED_NAMESPACE, false);
    preferences.putString("ssid", ssid);
    preferences.putString("pass", password);
    preferences.end();

    server.send(200, "text/html", "<h2>Saved. Rebooting...</h2>");
    delay(2000);
    ESP.restart();
  } else {
    server.send(400, "text/html", "Missing SSID or Password");
  }
}

static void startAPMode() {
  WiFi.mode(WIFI_AP);
  WiFi.softAP(WIFI_AP_SSID, WIFI_AP_PASSWORD);
  IPAddress ip = WiFi.softAPIP();
  Serial.print("AP mode started. IP: ");
  Serial.println(ip);

  server.on("/", handleRoot);
  server.on("/save", HTTP_POST, handleSave);
  server.begin();
}

static bool connectToStoredWiFi() {
  preferences.begin(WIFI_CRED_NAMESPACE, true);
  String ssid = preferences.getString("ssid", "");
  String pass = preferences.getString("pass", "");
  preferences.end();

  if (ssid == "") {
    Serial.println("No saved WiFi credentials.");
    return false;
  }

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid.c_str(), pass.c_str());

  Serial.printf("Connecting to %s", ssid.c_str());
  for (int i = 0; i < 20; i++) {
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("\nConnected.");
      Serial.print("IP: ");
      Serial.println(WiFi.localIP());
      return true;
    }
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nFailed to connect.");
  return false;
}

static void wifiTask(void* pvParameters) {
  if (connectToStoredWiFi()) {
    wifiConnected = true;
    digitalWrite(GPIO_PIN_CH3, HIGH); // Tắt tất cả relay ban đầu
    vTaskDelete(NULL);
  } else {
    digitalWrite(GPIO_PIN_CH4, HIGH); // Tắt tất cả relay ban đầu
    startAPMode();
    while (true) {
      server.handleClient();
      vTaskDelay(pdMS_TO_TICKS(10));
    }
  }
}

void startWiFiManager() {
  xTaskCreatePinnedToCore(
    wifiTask,        // Task function
    "WiFiManager",   // Name
    8192,            // Stack size
    NULL,            // Parameters
    1,               // Priority
    &wifiTaskHandle, // Task handle
    1                // Core
  );
}

bool isWiFiConnected() {
  return wifiConnected && WiFi.status() == WL_CONNECTED;
}

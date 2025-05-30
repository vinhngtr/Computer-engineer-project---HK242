#include <TaskMQTT.h>

WiFiClient espClient;
PubSubClient client(espClient);

// Topic Adafruit cho cảm biến
const char *TEMPERATURE_TOPIC = "vinhtrong782002/feeds/temperature";
const char *HUMIDITY_TOPIC = "vinhtrong782002/feeds/humidity";

// Biến toàn cục lưu dữ liệu
float globalTemperature = 0.0;
float globalHumidity = 0.0;

#define IO_USERNAME "vinhtrong782002"
#define IO_KEY "aio_IDwi97EwGbXkbEqgGUo5Wvl87BUI"
#define MQTT_SERVER "io.adafruit.com"
#define MQTT_PORT 1883

// Hàm callback khi nhận được tin nhắn MQTT
void mqttCallback(char *topic, byte *payload, unsigned int length)
{
    String message;
    for (unsigned int i = 0; i < length; i++)
        message += (char)payload[i];

    if (strcmp(topic, TEMPERATURE_TOPIC) == 0)
    {
        globalTemperature = message.toFloat();
        Serial.printf("Nhiệt độ: %.2f°C\n", globalTemperature);
    }
    else if (strcmp(topic, HUMIDITY_TOPIC) == 0)
    {
        globalHumidity = message.toFloat();
        Serial.printf("Độ ẩm: %.2f%%\n", globalHumidity);
    }
    
}

// Kết nối lại nếu mất kết nối
void reconnectMQTT()
{
    while (!client.connected())
    {
        String clientId = "ESP32DisplayClient-" + String(random(0xffff), HEX);
        Serial.print("MQTT reconnecting... ");
        if (client.connect(clientId.c_str(), IO_USERNAME, IO_KEY))
        {
            Serial.println("OK");
            client.subscribe(TEMPERATURE_TOPIC);
            client.subscribe(HUMIDITY_TOPIC);
        }
        else
        {
            Serial.printf("Lỗi MQTT: %d. Đợi 5s...\n", client.state());
            vTaskDelay(5000 / portTICK_PERIOD_MS);
        }
    }
}

// Task chạy MQTT
void mqttTask(void *pvParameters)
{
    while (WiFi.status() != WL_CONNECTED)
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    client.setServer(MQTT_SERVER, MQTT_PORT);
    client.setCallback(mqttCallback);

    while (true)
    {
        if (!client.connected())
            reconnectMQTT();
        client.loop();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

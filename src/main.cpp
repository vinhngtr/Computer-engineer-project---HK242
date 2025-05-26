#include "globals.h"

// Thông tin WiFi (thay bằng thông tin của bạn)
const char *ssid = "coffee 24/24 lau1";
const char *password = "khachhanglaso1";
const char *mqtt_server = "io.adafruit.com";
const char *mqtt_username = "vinhngtr";
const char *mqtt_key = "aio_dqhQ72Ajygz9TrJgKupIDgndLO4U";

// Định nghĩa chân I2C
const int SDA_PIN = 8;
const int SCL_PIN = 9;

// Định nghĩa chân relay
const int RELAY_PINS[6] = {1, 2, 3, 4, 5, 6};

// Topic MQTT cho điều khiển relay
const char *RELAY_CONTROL_TOPICS[6] = {
    "vinhngtr/feeds/relay1",
    "vinhngtr/feeds/relay2",
    "vinhngtr/feeds/relay3",
    "vinhngtr/feeds/relay4",
    "vinhngtr/feeds/relay5",
    "vinhngtr/feeds/relay6"};

DHT20 dht20;
WiFiClient espClient;
PubSubClient client(espClient);

// Biến kiểm soát thời gian
unsigned long previousMillis = 0;
const long interval = 50000;

// Trạng thái relay (true = ON, false = OFF)
bool relayStates[6] = {false, false, false, false, false, false};

// Hàm callback khi nhận tin nhắn MQTT
void mqttCallback(char *topic, byte *payload, unsigned int length)
{
    String message;
    for (unsigned int i = 0; i < length; i++)
        message += (char)payload[i];

    Serial.print("Nhận tin nhắn từ topic: ");
    Serial.print(topic);
    Serial.print(" - Nội dung: ");
    Serial.println(message);

    // Kiểm tra topic nào được gửi và điều khiển relay tương ứng
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(topic, RELAY_CONTROL_TOPICS[i]) == 0)
        {
            if (message == "ON" || message == "1")
            {
                digitalWrite(RELAY_PINS[i], HIGH);
                relayStates[i] = true;
                delay(100); // Đợi một chút để đảm bảo relay hoạt động
                Serial.printf("Relay %d: ON\n", i + 1);
            }
            else if (message == "OFF" || message == "0")
            {
                digitalWrite(RELAY_PINS[i], LOW);
                relayStates[i] = false;
                delay(100); // Đợi một chút để đảm bảo relay tắt
                Serial.printf("Relay %d: OFF\n", i + 1);
            }
        }
    }
}

void reconnect()
{
    while (!client.connected())
    {
        Serial.print("Attempting MQTT connection...");
        String clientId = "ESP32RelayClient-" + String(random(0xffff), HEX);

        if (client.connect(clientId.c_str(), mqtt_username, mqtt_key))
        {
            Serial.println("connected");

            // Subscribe tới các topic điều khiển relay
            for (int i = 0; i < 3; i++)
            {
                client.subscribe(RELAY_CONTROL_TOPICS[i]);
                delay(500);
            }

            // Delay dài giữa 2 đợt
            delay(2000);

            // Đợt 2: Subcribe 3 feed còn lại
            for (int i = 3; i < 6; i++)
            {
                client.subscribe(RELAY_CONTROL_TOPICS[i]);
                delay(500);
            }
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

void setup()
{
    Serial.begin(115200);
    // Khởi tạo các chân relay
    for (int i = 0; i < 6; i++)
    {
        pinMode(RELAY_PINS[i], OUTPUT);
        digitalWrite(RELAY_PINS[i], LOW); // Tắt tất cả relay ban đầu
    }

    // Khởi tạo I2C với các chân SDA và SCL cụ thể
    Wire.begin(SDA_PIN, SCL_PIN);

    // Kết nối WiFi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("WiFi connected");

    // Khởi tạo cảm biến DHT20
    dht20.begin();

    client.setServer(mqtt_server, 1883);
    client.setCallback(mqttCallback);

    // Kết nối đến Adafruit IO
    reconnect();
}

void loop()
{
    if (!client.connected())
    {
        reconnect();
    }
    client.loop();

    // Kiểm tra thời gian để gửi dữ liệu mỗi 50 giây
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;

        // Đọc dữ liệu từ DHT20
        int status = dht20.read();
        if (status == DHT20_OK)
        {
            float temp = dht20.getTemperature();
            float hum = dht20.getHumidity();

            // Gửi dữ liệu lên Adafruit IO
            String tempTopic = String(mqtt_username) + "/feeds/temperature";
            String humTopic = String(mqtt_username) + "/feeds/humidity";
            client.publish(tempTopic.c_str(), String(temp).c_str());
            client.publish(humTopic.c_str(), String(hum).c_str());

            // In thông tin để debug
            Serial.print("Temperature: ");
            Serial.print(temp);
            Serial.print(" °C, Humidity: ");
            Serial.print(hum);
            Serial.println(" %");
        }
        else
        {
            Serial.println("Error reading DHT20");
        }
    }
}
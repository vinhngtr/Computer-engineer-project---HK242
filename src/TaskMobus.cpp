#include "TaskMobus.h"

// Topic MQTT cho điều khiển relay (cùng với relay)
const char *RELAY_CONTROL_TOPICS[6] = {
    "vinhtrong782002/feeds/relay1",
    "vinhtrong782002/feeds/relay2",
    "vinhtrong782002/feeds/relay3",
    "vinhtrong782002/feeds/relay4",
    "vinhtrong782002/feeds/relay5",
    "vinhtrong782002/feeds/relay6"};

// Instance toàn cục
RelayController relayController;

RelayController::RelayController() : mqttClient(nullptr), initialized(false)
{
}

RelayController::~RelayController()
{
    // Không cần làm gì đặc biệt
}

void RelayController::begin(PubSubClient *client)
{
    mqttClient = client;
    initialized = true;

    Serial.println("=== RelayController: Đã khởi tạo điều khiển relay ===");
}

void RelayController::checkMqttStatus()
{
    if (!initialized)
    {
        Serial.println("RelayController: Chưa được khởi tạo");
        return;
    }

    if (!mqttClient)
    {
        Serial.println("RelayController: MQTT client chưa được thiết lập");
        return;
    }

    if (mqttClient->connected())
    {
        Serial.println("RelayController: MQTT đã kết nối - Sẵn sàng điều khiển relay!");
    }
    else
    {
        Serial.println("RelayController: MQTT chưa kết nối - Đang chờ kết nối...");
    }
}

bool RelayController::sendRelayCommand(int relayNumber, bool state)
{
    return sendRelayCommand(relayNumber, state ? "1" : "0");
}

bool RelayController::sendRelayCommand(int relayNumber, const char *command)
{
    // Kiểm tra khởi tạo
    if (!initialized)
    {
        Serial.println("RelayController: Chưa được khởi tạo! Gọi begin() trước.");
        return false;
    }

    // Kiểm tra số relay hợp lệ (1-6)
    if (relayNumber < 1 || relayNumber > 6)
    {
        Serial.printf("RelayController: Số relay không hợp lệ: %d (phải từ 1-6)\n", relayNumber);
        return false;
    }

    // Kiểm tra MQTT client
    if (!mqttClient)
    {
        Serial.println("RelayController: MQTT client chưa được thiết lập!");
        return false;
    }

    // Kiểm tra kết nối MQTT
    if (!mqttClient->connected())
    {
        Serial.printf("RelayController: MQTT chưa kết nối, không thể gửi lệnh relay %d\n", relayNumber);
        Serial.println("RelayController: Hãy đảm bảo WiFi và MQTT đã kết nối");
        return false;
    }

    // Lấy topic tương ứng (index = relayNumber - 1)
    const char *topic = RELAY_CONTROL_TOPICS[relayNumber - 1];

    Serial.printf("RelayController: Đang gửi lệnh '%s' đến relay %d...\n", command, relayNumber);
    Serial.printf("RelayController: Topic: %s\n", topic);

    // Gửi lệnh
    bool result = mqttClient->publish(topic, command);

    if (result)
    {
        Serial.printf("RelayController: ✓ Gửi lệnh thành công! Relay %d -> %s\n", relayNumber, command);
    }
    else
    {
        Serial.printf("RelayController: ✗ Gửi lệnh thất bại! Relay %d\n", relayNumber);
    }

    return result;
}

bool RelayController::isReady()
{
    return (initialized && mqttClient != nullptr && mqttClient->connected());
}

// thông báo khi MQTT kết nối
bool RelayController::onMqttConnected()
{
    if (initialized && mqttClient && mqttClient->connected())
    {
        Serial.println("=== RelayController: MQTT đã kết nối - Sẵn sàng điều khiển relay! ===");
        return true;
    }
    else
    {
        Serial.println("=== RelayController: MQTT chưa kết nối - Không thể điều khiển relay! ===");
        return false;
    }
}

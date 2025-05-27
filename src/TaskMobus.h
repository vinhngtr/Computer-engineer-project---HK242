#ifndef TASKMODBUS_H
#define TASKMODBUS_H

#include <PubSubClient.h>

// Topic MQTT cho điều khiển relay
extern const char *RELAY_CONTROL_TOPICS[6];

class RelayController {
private:
    PubSubClient* mqttClient;
    bool initialized;  // Thêm flag để theo dõi trạng thái khởi tạo

public:
    RelayController();
    ~RelayController();
    
    // Khởi tạo controller với MQTT client
    void begin(PubSubClient* client);
    
    // Kiểm tra trạng thái MQTT và in thông báo
    void checkMqttStatus();
    
    // Gửi lệnh điều khiển relay
    bool sendRelayCommand(int relayNumber, bool state);
    bool sendRelayCommand(int relayNumber, const char* command);
    
    // Kiểm tra xem controller có sẵn sàng không
    bool isReady();
    
    // Callback khi MQTT kết nối thành công
    bool onMqttConnected();
    
    // // Callback khi MQTT mất kết nối
    // bool onMqttDisconnected();
};

// Instance toàn cục
extern RelayController relayController;


#endif // TASKMODBUS_H
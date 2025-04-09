#ifndef ATTRIBUTES_TASK_H
#define ATTRIBUTES_TASK_H

#include "config.h"
#include <array>
#include <ThingsBoard.h>

// Số lượng relay
#define RELAY_COUNT 6

// Mảng chân GPIO điều khiển relay
const uint8_t RELAY_PINS[RELAY_COUNT] = {
    1,  // Relay 1
    2,  // Relay 2
    41, // Relay 3
    42, // Relay 4
    45, // Relay 5
    46  // Relay 6
};

// Trạng thái relay
extern std::array<bool, RELAY_COUNT> relayStates;

// Biến đọc dữ liệu cảm biến từ ThingsBoard về
extern float temperature;
extern float humidity;

// Task handle
extern TaskHandle_t attributesTaskHandle;

// Hàm điều khiển relay
void setRelay(uint8_t index, bool state);

// Hàm gửi trạng thái relay lên ThingsBoard
void sendRelayStates();

// Hàm xử lý RPC
RPC_Response processRelayRPC(const RPC_Data &data);

// Attributes task function declaration
void attributesTask(void *pvParameters);

// Khởi tạo task
void initAttributesTask();

#endif // ATTRIBUTES_TASK_H

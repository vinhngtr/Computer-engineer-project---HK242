#include "UI2tb.h"


// Trạng thái các relay (đồng bộ giữa UI và thiết bị)
extern std::array<bool, RELAY_COUNT> relayStates;

void handleSwitchControl(const char* swName, bool state) {
    if (strncmp(swName, "sw", 2) == 0) {
        int relayIndex = atoi(swName + 2) - 1;
        if (relayIndex >= 0 && relayIndex < RELAY_COUNT) {
            setRelay(relayIndex, state);
            // Cập nhật ThingsBoard nếu cần
            // tb.sendAttributeData(swName, state); // Optional nếu muốn phản hồi ngay
            Serial.printf("UI toggled %s to %s\n", swName, state ? "ON" : "OFF");
        }
    }
}

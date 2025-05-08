#ifndef UI2TB_H
#define UI2TB_H

#include "tb.h"
// Khai báo số lượng relay (sửa theo nhu cầu)
#define RELAY_COUNT 6

// Trạng thái các relay (đồng bộ giữa UI và thiết bị)
extern std::array<bool, RELAY_COUNT> relayStates;

// Hàm điều khiển switch
void handleSwitchControl(const char* swName, bool state);

#endif  // UI2TB_H

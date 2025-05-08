#ifndef TB2UI_H
#define TB2UI_H

#include "main.h"
#include "tb.h"
// Số lượng relay sử dụng (nên được định nghĩa trong config.h hoặc main.h)
#ifndef RELAY_COUNT
#define RELAY_COUNT 6
#endif

extern volatile float temperature;
extern volatile float humidity;

// Đối tượng giao diện (biểu đồ, công tắc)
extern lv_obj_t *ui_TempChart;
extern lv_obj_t *ui_HumidityChart;

extern lv_obj_t *ui_LightLvRoom1;
extern lv_obj_t *ui_LightLvRoom2;
extern lv_obj_t *ui_LightLvRoom3;
extern lv_obj_t *ui_ACLvRoom1;
extern lv_obj_t *ui_ACLvRoom2;
extern lv_obj_t *ui_FanLvRoom1;

// Trạng thái các relay (đồng bộ giữa UI và thiết bị)
extern std::array<bool, RELAY_COUNT> relayStates;

// Hàm task cập nhật UI theo cảm biến
void readSensorTask(void *parameter);

// Hàm task đồng bộ trạng thái switch trên UI từ server
void readSwitchTask(void *parameter);

// Hàm nội bộ cập nhật giá trị cho Arc UI (biểu đồ vòng)
void _ui_arc_set(lv_obj_t *target, int val);

// Hàm khởi tạo và tạo các task liên quan đến UI
void initUITB();
#endif // TB2UI_H

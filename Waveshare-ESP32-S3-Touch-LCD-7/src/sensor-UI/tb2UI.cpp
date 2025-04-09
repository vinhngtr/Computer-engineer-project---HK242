#include "tb2UI.h"
extern float temperature;
extern float humidity;
extern std::array<bool, RELAY_COUNT> relayStates;

void _ui_arc_set(lv_obj_t * target, int val) {
    lv_arc_set_value(target, val);
    lv_event_send(target, LV_EVENT_VALUE_CHANGED, 0);
}

void readSensorTask(void *parameter) {
    uint32_t task_delay_ms = LVGL_TASK_MAX_DELAY_MS;
    for(;;) {
        // Lock LVGL vì API của nó không thread-safe
        lvgl_port_lock(-1);

        // Cập nhật giao diện từ giá trị cảm biến thực tế
        _ui_arc_set(ui_TempChart, temperature);  // Cập nhật nhiệt độ lên Arc UI
        _ui_arc_set(ui_HumidityChart, humidity);  // Cập nhật độ ẩm lên Arc UI

        // Giải phóng LVGL mutex
        lvgl_port_unlock();

        // Đợi 2 giây trước lần cập nhật tiếp theo
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

void readSwitchTask(void *parameter) {
    lv_obj_t* switches[] = {
        ui_LightLvRoom1,
        ui_LightLvRoom2,
        ui_LightLvRoom3,
        ui_ACLvRoom1,
        ui_ACLvRoom2,
        ui_FanLvRoom1
    };

    for (;;) {
        lvgl_port_lock(-1);

        for (int i = 0; i < RELAY_COUNT; ++i) {
            if (switches[i]) {
                if (relayStates[i]) {
                    lv_obj_add_state(switches[i], LV_STATE_CHECKED);
                } else {
                    lv_obj_clear_state(switches[i], LV_STATE_CHECKED);
                }
            }
        }

        lvgl_port_unlock();
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}



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

void initUITB() {
    xTaskCreatePinnedToCore(readSensorTask, "SensorUI", 4096, NULL, 1, NULL, 1);
    xTaskCreatePinnedToCore(readSwitchTask, "SwitchUI", 4096, NULL, 1, NULL, 1);
}

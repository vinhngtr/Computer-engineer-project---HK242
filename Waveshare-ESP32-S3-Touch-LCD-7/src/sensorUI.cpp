// #include <main.h>
// #include <ui.h>
// extern int humi;
// extern int temp;

// void _ui_arc_set(lv_obj_t * target, int val) {
//     lv_arc_set_value(target, val);
//     lv_event_send(target, LV_EVENT_VALUE_CHANGED, 0);
// }

// void readSensorTask(void *parameter) {
//     uint32_t task_delay_ms = LVGL_TASK_MAX_DELAY_MS;
//     while (1) {
//         // Lock LVGL vì API của nó không thread-safe
//         lvgl_port_lock(-1);

//         // Cập nhật giao diện từ giá trị cảm biến thực tế
//         _ui_arc_set(ui_TempChart, temp);  // Cập nhật nhiệt độ lên Arc UI
//         _ui_arc_set(ui_HumidityChart, humi);  // Cập nhật độ ẩm lên Arc UI

//         // Giải phóng LVGL mutex
//         lvgl_port_unlock();

//         // Đợi 2 giây trước lần cập nhật tiếp theo
//         vTaskDelay(pdMS_TO_TICKS(2000));
//     }
// }

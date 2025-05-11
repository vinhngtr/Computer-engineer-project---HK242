#include <globals.h>
#include <ArduinoJson.h>
#include <TaskMQTT.h>
extern float globalTemperature;
extern float globalHumidity;
// Define the parseJson function if missing
void parseJson(const String &json, bool isFromUI);

// Thời gian để cập nhật
unsigned long previousMillis = 0;
const long interval = 3000; // 3 giây

/* LVGL porting configurations */
#define LVGL_TICK_PERIOD_MS (2)
#define LVGL_TASK_MAX_DELAY_MS (500)
#define LVGL_TASK_MIN_DELAY_MS (1)
#define LVGL_TASK_STACK_SIZE (4 * 1024)
#define LVGL_TASK_PRIORITY (2)
#define LVGL_BUF_SIZE (ESP_PANEL_LCD_H_RES * 480 / 4)

void TaskUIUpdate(void *pvParameters)
{
    while (1)
    {
        char buffer[32];
        sprintf(buffer, "%.2f °C", globalTemperature);
        lv_label_set_text(ui_ValueTemp, buffer);
        lv_arc_set_value(ui_TempChart, int(globalTemperature));
        sprintf(buffer, "%.2f %%", globalHumidity);
        lv_label_set_text(ui_ValueHumi, buffer);
        lv_arc_set_value(ui_HumidityChart, int(globalHumidity));
        vTaskDelay(1500 / portTICK_PERIOD_MS);
    }
}
ESP_Panel *panel = NULL;
SemaphoreHandle_t lvgl_mux = NULL; // LVGL mutex

void lvgl_port_lock(int timeout_ms)
{
    const TickType_t timeout_ticks = (timeout_ms < 0) ? portMAX_DELAY : pdMS_TO_TICKS(timeout_ms);
    xSemaphoreTakeRecursive(lvgl_mux, timeout_ticks);
}

void lvgl_port_unlock(void)
{
    xSemaphoreGiveRecursive(lvgl_mux);
}

// Biến đếm số thiết bị ON của Living Room
int lightOnLiv = 0; // Đèn
int fanOnLiv = 0;   // Quạt
int acOnLiv = 0;    // Điều hòa

// Biến đếm số thiết bị ON của Kitchen Room
int lightOnK = 0; // Đèn
int fanOnK = 0;   // Quạt
int acOnK = 0;    // Điều hòa

// Biến đếm số thiết bị ON của Bed Room
int lightOnB = 0; // Đèn
int fanOnB = 0;   // Quạt
int acOnB = 0;    // Điều hòa

// Hàm callback khi công tắc thay đổi trạng thái
static void switch_event_handler(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e);
    bool isOn = lv_obj_has_state(target, LV_STATE_CHECKED);

    // Cập nhật số lượng và giao diện
    lvgl_port_lock(-1); // Khóa mutex khi cập nhật UI
    if (target == ui_LightLvRoom1 || target == ui_LightLvRoom2 || target == ui_LightLvRoom3)
    {
        lightOnLiv += isOn ? 1 : -1;
        char buf[32];
        snprintf(buf, sizeof(buf), "%s%d%s", "(", int(lightOnLiv), ")");
        lv_label_set_text(ui_CountLightLV, buf);
        lv_slider_set_value(ui_LivActiveLight, lightOnLiv, LV_ANIM_ON); // Cập nhật slider
    }
    else if (target == ui_FanLvRoom1 || target == ui_FanLvRoom2)
    {
        fanOnLiv += isOn ? 1 : -1;
        char buf[32];
        snprintf(buf, sizeof(buf), "%s%d%s", "(", int(fanOnLiv), ")");
        lv_label_set_text(ui_CountFanLV, buf);
        lv_slider_set_value(ui_LivActiveFan, fanOnLiv, LV_ANIM_ON); // Cập nhật slider
        lvgl_port_unlock();                                         // Giải phóng mutex
    }
    else if (target == ui_Switch2)
    {
        acOnLiv += isOn ? 1 : -1;
        char buf[32];
        snprintf(buf, sizeof(buf), "%s%d%s", "(", int(acOnLiv), ")");
        lv_label_set_text(ui_CountACLV, buf);
        lv_slider_set_value(ui_LivActiveAC, acOnLiv, LV_ANIM_ON); // Cập nhật slider
        lvgl_port_unlock();                                       // Giải phóng mutex
    }
    else if (target == ui_LightBedRoom1 || target == ui_LightBedRoom2 || target == ui_LightBedRoom3)
    {
        lightOnB += isOn ? 1 : -1;
        char buf[32];
        snprintf(buf, sizeof(buf), "%s%d%s", "(", int(lightOnB), ")");
        lv_label_set_text(ui_CountLightB, buf);
        lv_slider_set_value(ui_BedActiveLight, lightOnB, LV_ANIM_ON); // Cập nhật slider
    }
    else if (target == ui_FanBedRoom1 || target == ui_FanBedRoom2)
    {
        fanOnB += isOn ? 1 : -1;
        char buf[32];
        snprintf(buf, sizeof(buf), "%s%d%s", "(", int(fanOnB), ")");
        lv_label_set_text(ui_CountFanB, buf);
        lv_slider_set_value(ui_BedActiveFan, fanOnB, LV_ANIM_ON); // Cập nhật slider
    }
    else if (target == ui_ACBedRoom1)
    {
        acOnB += isOn ? 1 : -1;
        char buf[32];
        snprintf(buf, sizeof(buf), "%s%d%s", "(", int(acOnB), ")");
        lv_label_set_text(ui_CountACB, buf);
        lv_slider_set_value(ui_BedActiveAC, acOnB, LV_ANIM_ON); // Cập nhật slider
    }
}
#if ESP_PANEL_LCD_BUS_TYPE == ESP_PANEL_BUS_TYPE_RGB
/* Display flushing */
void lvgl_port_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    panel->getLcd()->drawBitmap(area->x1, area->y1, area->x2 + 1, area->y2 + 1, color_p);
    lv_disp_flush_ready(disp);
}
#else
/* Display flushing */
void lvgl_port_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    panel->getLcd()->drawBitmap(area->x1, area->y1, area->x2 + 1, area->y2 + 1, color_p);
}

bool notify_lvgl_flush_ready(void *user_ctx)
{
    lv_disp_drv_t *disp_driver = (lv_disp_drv_t *)user_ctx;
    lv_disp_flush_ready(disp_driver);
    return false;
}
#endif /* ESP_PANEL_LCD_BUS_TYPE */

#if ESP_PANEL_USE_LCD_TOUCH
/* Read the touchpad */
void lvgl_port_tp_read(lv_indev_drv_t *indev, lv_indev_data_t *data)
{
    panel->getLcdTouch()->readData();

    bool touched = panel->getLcdTouch()->getTouchState();
    if (!touched)
    {
        data->state = LV_INDEV_STATE_REL;
    }
    else
    {
        TouchPoint point = panel->getLcdTouch()->getPoint();

        data->state = LV_INDEV_STATE_PR;
        /*Set the coordinates*/
        data->point.x = point.x;
        data->point.y = point.y;

        // Serial.printf("Touch point: x %d, y %d\n", point.x, point.y);
    }
}
#endif

void lvgl_port_task(void *arg)
{
    Serial.println("Starting LVGL task");

    uint32_t task_delay_ms = LVGL_TASK_MAX_DELAY_MS;
    while (1)
    {
        // Lock the mutex due to the LVGL APIs are not thread-safe
        lvgl_port_lock(-1);
        task_delay_ms = lv_timer_handler();
        // Release the mutex
        lvgl_port_unlock();
        if (task_delay_ms > LVGL_TASK_MAX_DELAY_MS)
        {
            task_delay_ms = LVGL_TASK_MAX_DELAY_MS;
        }
        else if (task_delay_ms < LVGL_TASK_MIN_DELAY_MS)
        {
            task_delay_ms = LVGL_TASK_MIN_DELAY_MS;
        }
        vTaskDelay(pdMS_TO_TICKS(task_delay_ms));
    }
}

void setup()
{
    Serial.begin(115200); /* prepare for possible serial debug */
    String LVGL_Arduino = "Hello LVGL! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

    Serial.println(LVGL_Arduino);
    Serial.println("I am ESP32_Display_Panel");

    panel = new ESP_Panel();
    /* Initialize LVGL core */
    lv_init();

    /* Initialize LVGL buffers */
    static lv_disp_draw_buf_t draw_buf;
    uint8_t *buf = (uint8_t *)heap_caps_calloc(1, LVGL_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_INTERNAL);
    assert(buf);
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, LVGL_BUF_SIZE);

    /* Initialize the display device */
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    /* Change the following line to your display resolution */
    disp_drv.hor_res = ESP_PANEL_LCD_H_RES;
    disp_drv.ver_res = ESP_PANEL_LCD_V_RES;
    disp_drv.flush_cb = lvgl_port_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

#if ESP_PANEL_USE_LCD_TOUCH
    /* Initialize the input device */
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = lvgl_port_tp_read;
    lv_indev_drv_register(&indev_drv);
#endif
    /* Initialize bus and device of panel */
    panel->init();
#if ESP_PANEL_LCD_BUS_TYPE != ESP_PANEL_BUS_TYPE_RGB
    panel->getLcd()->setCallback(notify_lvgl_flush_ready, &disp_drv);
#endif

    Serial.println("Initialize IO expander");
    ESP_IOExpander *expander = new ESP_IOExpander_CH422G(I2C_MASTER_NUM, ESP_IO_EXPANDER_I2C_CH422G_ADDRESS_000);
    expander->init();
    expander->begin();
    expander->multiPinMode(TP_RST | LCD_BL | LCD_RST | SD_CS | USB_SEL, OUTPUT);
    expander->multiDigitalWrite(TP_RST | LCD_BL | LCD_RST | SD_CS, HIGH);

    // Turn off backlight
    // expander->digitalWrite(USB_SEL, LOW);
    expander->digitalWrite(USB_SEL, LOW);
    /* Add into panel */
    panel->addIOExpander(expander);

    /* Start panel */
    panel->begin();

    // Wire1.begin(DHT20_SDA_IO, DHT20_SCL_IO, 100000); // Bắt đầu với 100kHz

    // dht20.begin();
    /* Create a task to run the LVGL task periodically */
    lvgl_mux = xSemaphoreCreateRecursiveMutex();
    xTaskCreate(lvgl_port_task, "lvgl", LVGL_TASK_STACK_SIZE, NULL, LVGL_TASK_PRIORITY, NULL);
    lvgl_port_lock(-1);
    ui_init();
    lvgl_port_unlock();

    lvgl_port_lock(-1);
    lv_obj_add_event_cb(ui_LightLvRoom1, switch_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_LightLvRoom2, switch_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_LightLvRoom3, switch_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_label_set_text(ui_CountLightLV, "(0)");
    lv_slider_set_value(ui_LivActiveLight, 0, LV_ANIM_OFF);

    lv_obj_add_event_cb(ui_FanLvRoom1, switch_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_FanLvRoom2, switch_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_label_set_text(ui_CountFanLV, "(0)");
    lv_slider_set_value(ui_LivActiveFan, 0, LV_ANIM_OFF);
    lv_obj_add_event_cb(ui_Switch2, switch_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_label_set_text(ui_CountACLV, "(0)");

    lv_obj_add_event_cb(ui_LightBedRoom1, switch_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_LightBedRoom2, switch_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_LightBedRoom3, switch_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_label_set_text(ui_CountLightB, "(0)");
    lv_slider_set_value(ui_BedActiveLight, 0, LV_ANIM_OFF);
    lv_obj_add_event_cb(ui_FanBedRoom1, switch_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_FanBedRoom2, switch_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_label_set_text(ui_CountFanB, "(0)");
    lv_slider_set_value(ui_BedActiveFan, 0, LV_ANIM_OFF);
    lv_obj_add_event_cb(ui_ACBedRoom1, switch_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_label_set_text(ui_CountACB, "(0)");
    lv_slider_set_value(ui_BedActiveAC, 0, LV_ANIM_OFF);

    /* Lock the mutex due to the LVGL APIs are not thread-safe */
    lvgl_port_unlock();

    xTaskCreatePinnedToCore(mqttTask, "MQTT", 4096, NULL, 1, NULL, 1);
    xTaskCreatePinnedToCore(TaskUIUpdate, "TaskUIUpdate", 4096, NULL, 1, NULL, 1);
    setupRS485(); // Setup RS485
    /* Release the mutex */
    Serial.println("Setup done");
}

void loop()
{
    // Xử lý sự kiện LVGL
    lv_task_handler();
    delay(5);
}
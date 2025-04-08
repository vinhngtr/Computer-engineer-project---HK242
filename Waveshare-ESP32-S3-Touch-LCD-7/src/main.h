#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include <lvgl.h>
#include <ESP_Panel_Library.h>
#include <ESP_IOExpander_Library.h>
#include <ui.h>
#include "things_board/tb.h"

// Extend IO Pin define
#define TP_RST 1
#define LCD_BL 2
#define LCD_RST 3
#define SD_CS 4
#define USB_SEL 5

// I2C Pin define
#define I2C_MASTER_NUM 0
#define I2C_MASTER_SDA_IO 8
#define I2C_MASTER_SCL_IO 9

// LVGL configurations
#define LVGL_TICK_PERIOD_MS     (2)
#define LVGL_TASK_MAX_DELAY_MS  (500)
#define LVGL_TASK_MIN_DELAY_MS  (1)
#define LVGL_TASK_STACK_SIZE    (4 * 1024)
#define LVGL_TASK_PRIORITY      (2)
#define LVGL_BUF_SIZE           (ESP_PANEL_LCD_H_RES * 20)

extern ESP_Panel *panel;
extern SemaphoreHandle_t lvgl_mux;

// Function declarations
void lvgl_port_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
bool notify_lvgl_flush_ready(void *user_ctx);
void lvgl_port_tp_read(lv_indev_drv_t *indev, lv_indev_data_t *data);
void lvgl_port_lock(int timeout_ms);
void lvgl_port_unlock(void);
void lvgl_port_task(void *arg);
void setup();
void loop();

#endif // MAIN_H

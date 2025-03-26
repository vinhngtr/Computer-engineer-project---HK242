// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.1
// LVGL version: 8.3.6
// Project name: Squareline

#include "../ui.h"

void ui_bedRoomScreen2_screen_init(void)
{
    ui_bedRoomScreen2 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_bedRoomScreen2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(ui_bedRoomScreen2, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_bedRoomScreen2, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_bedRoomScreen2, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_bedRoomScreen2, 30, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel10 = lv_obj_create(ui_bedRoomScreen2);
    lv_obj_set_width(ui_Panel10, lv_pct(74));
    lv_obj_set_height(ui_Panel10, lv_pct(60));
    lv_obj_clear_flag(ui_Panel10, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel10, lv_color_hex(0x002894), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_dvName5 = lv_label_create(ui_Panel10);
    lv_obj_set_width(ui_dvName5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_dvName5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_dvName5, 0);
    lv_obj_set_y(ui_dvName5, -9);
    lv_obj_set_align(ui_dvName5, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_dvName5, "LIGHTING");
    lv_obj_set_style_text_font(ui_dvName5, &ui_font_font48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lightName3 = lv_label_create(ui_Panel10);
    lv_obj_set_width(ui_lightName3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lightName3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_lightName3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lightName3,
                      "LIGHT Bulb 1             LIGHT Bulb 2               LIGHT Bulb 3\n\n\n\n\nLIGHT Bulb 4             LIGHT Bulb5               LIGHT Bulb 6");
    lv_obj_set_style_text_font(ui_lightName3, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LightBedRoom7 = lv_switch_create(ui_Panel10);
    lv_obj_set_width(ui_LightBedRoom7, 100);
    lv_obj_set_height(ui_LightBedRoom7, 50);
    lv_obj_set_x(ui_LightBedRoom7, 20);
    lv_obj_set_y(ui_LightBedRoom7, 0);
    lv_obj_set_align(ui_LightBedRoom7, LV_ALIGN_LEFT_MID);

    ui_LightBedRoom8 = lv_switch_create(ui_Panel10);
    lv_obj_set_width(ui_LightBedRoom8, 100);
    lv_obj_set_height(ui_LightBedRoom8, 50);
    lv_obj_set_x(ui_LightBedRoom8, 200);
    lv_obj_set_y(ui_LightBedRoom8, 0);
    lv_obj_set_align(ui_LightBedRoom8, LV_ALIGN_LEFT_MID);

    ui_LightBedRoom9 = lv_switch_create(ui_Panel10);
    lv_obj_set_width(ui_LightBedRoom9, 100);
    lv_obj_set_height(ui_LightBedRoom9, 50);
    lv_obj_set_x(ui_LightBedRoom9, 410);
    lv_obj_set_y(ui_LightBedRoom9, 1);
    lv_obj_set_align(ui_LightBedRoom9, LV_ALIGN_LEFT_MID);

    ui_LightBedRoom10 = lv_switch_create(ui_Panel10);
    lv_obj_set_width(ui_LightBedRoom10, 100);
    lv_obj_set_height(ui_LightBedRoom10, 50);
    lv_obj_set_x(ui_LightBedRoom10, 20);
    lv_obj_set_y(ui_LightBedRoom10, 95);
    lv_obj_set_align(ui_LightBedRoom10, LV_ALIGN_LEFT_MID);

    ui_LightBedRoom11 = lv_switch_create(ui_Panel10);
    lv_obj_set_width(ui_LightBedRoom11, 100);
    lv_obj_set_height(ui_LightBedRoom11, 50);
    lv_obj_set_x(ui_LightBedRoom11, 200);
    lv_obj_set_y(ui_LightBedRoom11, 95);
    lv_obj_set_align(ui_LightBedRoom11, LV_ALIGN_LEFT_MID);

    ui_LightBedRoom12 = lv_switch_create(ui_Panel10);
    lv_obj_set_width(ui_LightBedRoom12, 100);
    lv_obj_set_height(ui_LightBedRoom12, 50);
    lv_obj_set_x(ui_LightBedRoom12, 410);
    lv_obj_set_y(ui_LightBedRoom12, 95);
    lv_obj_set_align(ui_LightBedRoom12, LV_ALIGN_LEFT_MID);

    ui_Panel11 = lv_obj_create(ui_bedRoomScreen2);
    lv_obj_set_width(ui_Panel11, lv_pct(25));
    lv_obj_set_height(ui_Panel11, lv_pct(60));
    lv_obj_set_align(ui_Panel11, LV_ALIGN_TOP_RIGHT);
    lv_obj_clear_flag(ui_Panel11, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel11, lv_color_hex(0x002894), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_dvName6 = lv_label_create(ui_Panel11);
    lv_obj_set_width(ui_dvName6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_dvName6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_dvName6, 0);
    lv_obj_set_y(ui_dvName6, -9);
    lv_obj_set_align(ui_dvName6, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_dvName6, "FAN");
    lv_obj_set_style_text_font(ui_dvName6, &ui_font_font48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_fanName3 = lv_label_create(ui_Panel11);
    lv_obj_set_width(ui_fanName3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_fanName3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_fanName3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_fanName3, "FAN 1\n\n\n\nFAN 2");
    lv_obj_set_style_text_font(ui_fanName3, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_FanBedRoom3 = lv_switch_create(ui_Panel11);
    lv_obj_set_width(ui_FanBedRoom3, 100);
    lv_obj_set_height(ui_FanBedRoom3, 50);
    lv_obj_set_align(ui_FanBedRoom3, LV_ALIGN_CENTER);

    ui_FanBedRoom4 = lv_switch_create(ui_Panel11);
    lv_obj_set_width(ui_FanBedRoom4, 100);
    lv_obj_set_height(ui_FanBedRoom4, 50);
    lv_obj_set_x(ui_FanBedRoom4, 0);
    lv_obj_set_y(ui_FanBedRoom4, 95);
    lv_obj_set_align(ui_FanBedRoom4, LV_ALIGN_CENTER);

    ui_Panel12 = lv_obj_create(ui_bedRoomScreen2);
    lv_obj_set_width(ui_Panel12, lv_pct(42));
    lv_obj_set_height(ui_Panel12, lv_pct(30));
    lv_obj_set_x(ui_Panel12, lv_pct(0));
    lv_obj_set_y(ui_Panel12, lv_pct(-5));
    lv_obj_set_align(ui_Panel12, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_clear_flag(ui_Panel12, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel12, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Panel12, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Panel12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ACName5 = lv_label_create(ui_Panel12);
    lv_obj_set_width(ui_ACName5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ACName5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ACName5, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_ACName5, "AC 1");
    lv_obj_set_style_text_font(ui_ACName5, &ui_font_font48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ac1control1 = lv_slider_create(ui_Panel12);
    lv_slider_set_range(ui_ac1control1, 16, 30);
    lv_slider_set_value(ui_ac1control1, 20, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_ac1control1) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_ac1control1, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_ac1control1, 200);
    lv_obj_set_height(ui_ac1control1, 20);

    ui_ACBedRoomTemp3 = lv_label_create(ui_Panel12);
    lv_obj_set_width(ui_ACBedRoomTemp3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ACBedRoomTemp3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ACBedRoomTemp3, 3);
    lv_obj_set_y(ui_ACBedRoomTemp3, -9);
    lv_obj_set_align(ui_ACBedRoomTemp3, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_ACBedRoomTemp3, "20°C");
    lv_obj_set_style_text_font(ui_ACBedRoomTemp3, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ACBedRoom3 = lv_switch_create(ui_Panel12);
    lv_obj_set_width(ui_ACBedRoom3, 70);
    lv_obj_set_height(ui_ACBedRoom3, 35);
    lv_obj_set_align(ui_ACBedRoom3, LV_ALIGN_BOTTOM_RIGHT);

    ui_Panel13 = lv_obj_create(ui_bedRoomScreen2);
    lv_obj_set_width(ui_Panel13, lv_pct(42));
    lv_obj_set_height(ui_Panel13, lv_pct(30));
    lv_obj_set_x(ui_Panel13, lv_pct(0));
    lv_obj_set_y(ui_Panel13, lv_pct(-5));
    lv_obj_set_align(ui_Panel13, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_clear_flag(ui_Panel13, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel13, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Panel13, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Panel13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ACName6 = lv_label_create(ui_Panel13);
    lv_obj_set_width(ui_ACName6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ACName6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ACName6, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_ACName6, "AC 2");
    lv_obj_set_style_text_font(ui_ACName6, &ui_font_font48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ac2control1 = lv_slider_create(ui_Panel13);
    lv_slider_set_range(ui_ac2control1, 16, 30);
    lv_slider_set_value(ui_ac2control1, 20, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_ac2control1) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_ac2control1, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_ac2control1, 200);
    lv_obj_set_height(ui_ac2control1, 20);

    ui_ACBedRoomTemp4 = lv_label_create(ui_Panel13);
    lv_obj_set_width(ui_ACBedRoomTemp4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ACBedRoomTemp4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ACBedRoomTemp4, 3);
    lv_obj_set_y(ui_ACBedRoomTemp4, -9);
    lv_obj_set_align(ui_ACBedRoomTemp4, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_ACBedRoomTemp4, "20°C");
    lv_obj_set_style_text_font(ui_ACBedRoomTemp4, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ACBedRoom4 = lv_switch_create(ui_Panel13);
    lv_obj_set_width(ui_ACBedRoom4, 70);
    lv_obj_set_height(ui_ACBedRoom4, 35);
    lv_obj_set_align(ui_ACBedRoom4, LV_ALIGN_BOTTOM_RIGHT);

    ui_ImgButton3 = lv_imgbtn_create(ui_bedRoomScreen2);
    lv_imgbtn_set_src(ui_ImgButton3, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_115668498, NULL);
    lv_imgbtn_set_src(ui_ImgButton3, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_115668498, NULL);
    lv_obj_set_width(ui_ImgButton3, 125);
    lv_obj_set_height(ui_ImgButton3, 101);
    lv_obj_set_x(ui_ImgButton3, 111);
    lv_obj_set_y(ui_ImgButton3, -24);
    lv_obj_set_align(ui_ImgButton3, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_style_radius(ui_ImgButton3, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ImgButton3, lv_color_hex(0x1089DE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ImgButton3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_transform_angle(ui_ImgButton3, 900, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ImgButton3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_ImgButton3, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LBRSlider4 = lv_slider_create(ui_bedRoomScreen2);
    lv_slider_set_range(ui_LBRSlider4, 0, 6);
    lv_slider_set_value(ui_LBRSlider4, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_LBRSlider4) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_LBRSlider4, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_LBRSlider4, 150);
    lv_obj_set_height(ui_LBRSlider4, 10);
    lv_obj_set_align(ui_LBRSlider4, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_LBRSlider4, LV_OBJ_FLAG_HIDDEN);     /// Flags

    ui_LBRSlider5 = lv_slider_create(ui_bedRoomScreen2);
    lv_slider_set_range(ui_LBRSlider5, 0, 2);
    lv_slider_set_value(ui_LBRSlider5, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_LBRSlider5) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_LBRSlider5, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_LBRSlider5, 150);
    lv_obj_set_height(ui_LBRSlider5, 10);
    lv_obj_set_align(ui_LBRSlider5, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_LBRSlider5, LV_OBJ_FLAG_HIDDEN);     /// Flags

    ui_LBRSlider6 = lv_slider_create(ui_bedRoomScreen2);
    lv_slider_set_range(ui_LBRSlider6, 0, 2);
    lv_slider_set_value(ui_LBRSlider6, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_LBRSlider6) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_LBRSlider6, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_LBRSlider6, 150);
    lv_obj_set_height(ui_LBRSlider6, 10);
    lv_obj_set_align(ui_LBRSlider6, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_LBRSlider6, LV_OBJ_FLAG_HIDDEN);     /// Flags

    lv_obj_add_event_cb(ui_LightBedRoom7, ui_event_LightBedRoom7, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_LightBedRoom8, ui_event_LightBedRoom8, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_LightBedRoom9, ui_event_LightBedRoom9, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_LightBedRoom10, ui_event_LightBedRoom10, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_LightBedRoom11, ui_event_LightBedRoom11, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_LightBedRoom12, ui_event_LightBedRoom12, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_FanBedRoom3, ui_event_FanBedRoom3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_FanBedRoom4, ui_event_FanBedRoom4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ac1control1, ui_event_ac1control1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ACBedRoom3, ui_event_ACBedRoom3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ac2control1, ui_event_ac2control1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ImgButton3, ui_event_ImgButton3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_LBRSlider4, ui_event_LBRSlider4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_LBRSlider5, ui_event_LBRSlider5, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_LBRSlider6, ui_event_LBRSlider6, LV_EVENT_ALL, NULL);

}

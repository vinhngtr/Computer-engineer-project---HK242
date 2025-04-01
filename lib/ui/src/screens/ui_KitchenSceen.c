// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.1
// LVGL version: 8.3.6
// Project name: Squareline

#include "../ui.h"

void ui_KitchenSceen_screen_init(void)
{
    ui_KitchenSceen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_KitchenSceen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(ui_KitchenSceen, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_KitchenSceen, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_KitchenSceen, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_KitchenSceen, 30, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel10 = lv_obj_create(ui_KitchenSceen);
    lv_obj_set_width(ui_Panel10, lv_pct(74));
    lv_obj_set_height(ui_Panel10, lv_pct(45));
    lv_obj_set_x(ui_Panel10, 0);
    lv_obj_set_y(ui_Panel10, -7);
    lv_obj_clear_flag(ui_Panel10, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel10, lv_color_hex(0x4D8E13), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_dvName5 = lv_label_create(ui_Panel10);
    lv_obj_set_width(ui_dvName5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_dvName5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_dvName5, 38);
    lv_obj_set_y(ui_dvName5, -10);
    lv_obj_set_align(ui_dvName5, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_dvName5, "KITCHEN ROOM");
    lv_obj_set_style_text_color(ui_dvName5, lv_color_hex(0xD1F100), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_dvName5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_dvName5, &ui_font_font48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lightName3 = lv_label_create(ui_Panel10);
    lv_obj_set_width(ui_lightName3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lightName3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lightName3, 0);
    lv_obj_set_y(ui_lightName3, 38);
    lv_obj_set_align(ui_lightName3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lightName3, "LIGHT Bulb 1             LIGHT Bulb 2               LIGHT Bulb 3\n\n\n\n");
    lv_obj_set_style_text_font(ui_lightName3, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SWLightBed1 = lv_switch_create(ui_Panel10);
    lv_obj_set_width(ui_SWLightBed1, 100);
    lv_obj_set_height(ui_SWLightBed1, 50);
    lv_obj_set_x(ui_SWLightBed1, 9);
    lv_obj_set_y(ui_SWLightBed1, 39);
    lv_obj_set_align(ui_SWLightBed1, LV_ALIGN_LEFT_MID);

    ui_SWLightBed2 = lv_switch_create(ui_Panel10);
    lv_obj_set_width(ui_SWLightBed2, 100);
    lv_obj_set_height(ui_SWLightBed2, 50);
    lv_obj_set_x(ui_SWLightBed2, 203);
    lv_obj_set_y(ui_SWLightBed2, 40);
    lv_obj_set_align(ui_SWLightBed2, LV_ALIGN_LEFT_MID);

    ui_SWLightBed3 = lv_switch_create(ui_Panel10);
    lv_obj_set_width(ui_SWLightBed3, 100);
    lv_obj_set_height(ui_SWLightBed3, 50);
    lv_obj_set_x(ui_SWLightBed3, 417);
    lv_obj_set_y(ui_SWLightBed3, 40);
    lv_obj_set_align(ui_SWLightBed3, LV_ALIGN_LEFT_MID);

    ui_BackHome3 = lv_btn_create(ui_Panel10);
    lv_obj_set_width(ui_BackHome3, 50);
    lv_obj_set_height(ui_BackHome3, 50);
    lv_obj_set_x(ui_BackHome3, -241);
    lv_obj_set_y(ui_BackHome3, -58);
    lv_obj_set_align(ui_BackHome3, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_BackHome3, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BackHome3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BackHome3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image5 = lv_img_create(ui_BackHome3);
    lv_img_set_src(ui_Image5, &ui_img_1385603933);
    lv_obj_set_width(ui_Image5, LV_SIZE_CONTENT);   /// 25
    lv_obj_set_height(ui_Image5, LV_SIZE_CONTENT);    /// 25
    lv_obj_set_x(ui_Image5, -1);
    lv_obj_set_y(ui_Image5, 0);
    lv_obj_set_align(ui_Image5, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel11 = lv_obj_create(ui_KitchenSceen);
    lv_obj_set_width(ui_Panel11, lv_pct(25));
    lv_obj_set_height(ui_Panel11, lv_pct(70));
    lv_obj_set_x(ui_Panel11, 1);
    lv_obj_set_y(ui_Panel11, -8);
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

    ui_SWFanBed1 = lv_switch_create(ui_Panel11);
    lv_obj_set_width(ui_SWFanBed1, 100);
    lv_obj_set_height(ui_SWFanBed1, 50);
    lv_obj_set_align(ui_SWFanBed1, LV_ALIGN_CENTER);

    ui_SWFanBed2 = lv_switch_create(ui_Panel11);
    lv_obj_set_width(ui_SWFanBed2, 100);
    lv_obj_set_height(ui_SWFanBed2, 50);
    lv_obj_set_x(ui_SWFanBed2, 0);
    lv_obj_set_y(ui_SWFanBed2, 95);
    lv_obj_set_align(ui_SWFanBed2, LV_ALIGN_CENTER);

    ui_Panel12 = lv_obj_create(ui_KitchenSceen);
    lv_obj_set_width(ui_Panel12, lv_pct(50));
    lv_obj_set_height(ui_Panel12, lv_pct(23));
    lv_obj_set_x(ui_Panel12, lv_pct(0));
    lv_obj_set_y(ui_Panel12, lv_pct(-30));
    lv_obj_set_align(ui_Panel12, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_clear_flag(ui_Panel12, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel12, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Panel12, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Panel12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AirKIT1 = lv_label_create(ui_Panel12);
    lv_obj_set_width(ui_AirKIT1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AirKIT1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AirKIT1, 0);
    lv_obj_set_y(ui_AirKIT1, 8);
    lv_obj_set_align(ui_AirKIT1, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_AirKIT1, "Air 1");
    lv_obj_set_style_text_font(ui_AirKIT1, &ui_font_font48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_valTempKIT = lv_label_create(ui_Panel12);
    lv_obj_set_width(ui_valTempKIT, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_valTempKIT, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_valTempKIT, -112);
    lv_obj_set_y(ui_valTempKIT, 11);
    lv_obj_set_align(ui_valTempKIT, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_valTempKIT, "20°C");
    lv_obj_set_style_text_font(ui_valTempKIT, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SWAirKIT1 = lv_switch_create(ui_Panel12);
    lv_obj_set_width(ui_SWAirKIT1, 70);
    lv_obj_set_height(ui_SWAirKIT1, 35);
    lv_obj_set_x(ui_SWAirKIT1, -2);
    lv_obj_set_y(ui_SWAirKIT1, -5);
    lv_obj_set_align(ui_SWAirKIT1, LV_ALIGN_BOTTOM_RIGHT);

    ui_Panel13 = lv_obj_create(ui_KitchenSceen);
    lv_obj_set_width(ui_Panel13, lv_pct(50));
    lv_obj_set_height(ui_Panel13, lv_pct(23));
    lv_obj_set_x(ui_Panel13, lv_pct(-50));
    lv_obj_set_y(ui_Panel13, lv_pct(-4));
    lv_obj_set_align(ui_Panel13, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_clear_flag(ui_Panel13, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel13, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Panel13, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Panel13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ACName6 = lv_label_create(ui_Panel13);
    lv_obj_set_width(ui_ACName6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ACName6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ACName6, 0);
    lv_obj_set_y(ui_ACName6, 11);
    lv_obj_set_align(ui_ACName6, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_ACName6, "Air 2");
    lv_obj_set_style_text_font(ui_ACName6, &ui_font_font48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_valTempKIT2 = lv_label_create(ui_Panel13);
    lv_obj_set_width(ui_valTempKIT2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_valTempKIT2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_valTempKIT2, -113);
    lv_obj_set_y(ui_valTempKIT2, 12);
    lv_obj_set_align(ui_valTempKIT2, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_valTempKIT2, "20°C");
    lv_obj_set_style_text_font(ui_valTempKIT2, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SWAirKIT2 = lv_switch_create(ui_Panel13);
    lv_obj_set_width(ui_SWAirKIT2, 70);
    lv_obj_set_height(ui_SWAirKIT2, 35);
    lv_obj_set_x(ui_SWAirKIT2, -3);
    lv_obj_set_y(ui_SWAirKIT2, -7);
    lv_obj_set_align(ui_SWAirKIT2, LV_ALIGN_BOTTOM_RIGHT);

    lv_obj_add_event_cb(ui_BackHome3, ui_event_BackHome3, LV_EVENT_ALL, NULL);

}

// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.1
// LVGL version: 8.3.6
// Project name: Squareline

#include "../ui.h"

void ui_BedoomSceen_screen_init(void)
{
    ui_BedoomSceen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_BedoomSceen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(ui_BedoomSceen, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_BedoomSceen, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_BedoomSceen, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_BedoomSceen, 30, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel5 = lv_obj_create(ui_BedoomSceen);
    lv_obj_set_width(ui_Panel5, lv_pct(74));
    lv_obj_set_height(ui_Panel5, lv_pct(45));
    lv_obj_clear_flag(ui_Panel5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel5, lv_color_hex(0x4D8E13), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_dvName3 = lv_label_create(ui_Panel5);
    lv_obj_set_width(ui_dvName3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_dvName3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_dvName3, 30);
    lv_obj_set_y(ui_dvName3, -9);
    lv_obj_set_align(ui_dvName3, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_dvName3, "BED ROOM ");
    lv_obj_set_style_text_color(ui_dvName3, lv_color_hex(0xD1F100), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_dvName3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_dvName3, &ui_font_font48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lightName2 = lv_label_create(ui_Panel5);
    lv_obj_set_width(ui_lightName2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lightName2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lightName2, 3);
    lv_obj_set_y(ui_lightName2, 18);
    lv_obj_set_align(ui_lightName2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lightName2, "LIGHT Bulb 1             LIGHT Bulb 2               LIGHT Bulb 3\n\n\n");
    lv_obj_set_style_text_font(ui_lightName2, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LightBedRoom1 = lv_switch_create(ui_Panel5);
    lv_obj_set_width(ui_LightBedRoom1, 100);
    lv_obj_set_height(ui_LightBedRoom1, 50);
    lv_obj_set_x(ui_LightBedRoom1, 10);
    lv_obj_set_y(ui_LightBedRoom1, 38);
    lv_obj_set_align(ui_LightBedRoom1, LV_ALIGN_LEFT_MID);

    ui_LightBedRoom2 = lv_switch_create(ui_Panel5);
    lv_obj_set_width(ui_LightBedRoom2, 100);
    lv_obj_set_height(ui_LightBedRoom2, 50);
    lv_obj_set_x(ui_LightBedRoom2, 208);
    lv_obj_set_y(ui_LightBedRoom2, 38);
    lv_obj_set_align(ui_LightBedRoom2, LV_ALIGN_LEFT_MID);

    ui_LightBedRoom3 = lv_switch_create(ui_Panel5);
    lv_obj_set_width(ui_LightBedRoom3, 100);
    lv_obj_set_height(ui_LightBedRoom3, 50);
    lv_obj_set_x(ui_LightBedRoom3, 422);
    lv_obj_set_y(ui_LightBedRoom3, 37);
    lv_obj_set_align(ui_LightBedRoom3, LV_ALIGN_LEFT_MID);

    ui_BackHome2 = lv_btn_create(ui_Panel5);
    lv_obj_set_width(ui_BackHome2, 50);
    lv_obj_set_height(ui_BackHome2, 50);
    lv_obj_set_x(ui_BackHome2, -235);
    lv_obj_set_y(ui_BackHome2, -59);
    lv_obj_set_align(ui_BackHome2, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_BackHome2, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BackHome2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BackHome2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image2 = lv_img_create(ui_BackHome2);
    lv_img_set_src(ui_Image2, &ui_img_1385603933);
    lv_obj_set_width(ui_Image2, LV_SIZE_CONTENT);   /// 25
    lv_obj_set_height(ui_Image2, LV_SIZE_CONTENT);    /// 25
    lv_obj_set_x(ui_Image2, -1);
    lv_obj_set_y(ui_Image2, 0);
    lv_obj_set_align(ui_Image2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel6 = lv_obj_create(ui_BedoomSceen);
    lv_obj_set_width(ui_Panel6, lv_pct(25));
    lv_obj_set_height(ui_Panel6, lv_pct(70));
    lv_obj_set_align(ui_Panel6, LV_ALIGN_TOP_RIGHT);
    lv_obj_clear_flag(ui_Panel6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel6, lv_color_hex(0x002894), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_dvName4 = lv_label_create(ui_Panel6);
    lv_obj_set_width(ui_dvName4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_dvName4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_dvName4, 0);
    lv_obj_set_y(ui_dvName4, -9);
    lv_obj_set_align(ui_dvName4, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_dvName4, "FAN");
    lv_obj_set_style_text_font(ui_dvName4, &ui_font_font48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_fanName2 = lv_label_create(ui_Panel6);
    lv_obj_set_width(ui_fanName2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_fanName2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_fanName2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_fanName2, "FAN 1\n\n\n\nFAN 2");
    lv_obj_set_style_text_font(ui_fanName2, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_FanBedRoom1 = lv_switch_create(ui_Panel6);
    lv_obj_set_width(ui_FanBedRoom1, 100);
    lv_obj_set_height(ui_FanBedRoom1, 50);
    lv_obj_set_align(ui_FanBedRoom1, LV_ALIGN_CENTER);

    ui_FanBedRoom2 = lv_switch_create(ui_Panel6);
    lv_obj_set_width(ui_FanBedRoom2, 100);
    lv_obj_set_height(ui_FanBedRoom2, 50);
    lv_obj_set_x(ui_FanBedRoom2, 0);
    lv_obj_set_y(ui_FanBedRoom2, 95);
    lv_obj_set_align(ui_FanBedRoom2, LV_ALIGN_CENTER);

    ui_Panel7 = lv_obj_create(ui_BedoomSceen);
    lv_obj_set_width(ui_Panel7, lv_pct(50));
    lv_obj_set_height(ui_Panel7, lv_pct(23));
    lv_obj_set_x(ui_Panel7, lv_pct(0));
    lv_obj_set_y(ui_Panel7, lv_pct(48));
    lv_obj_clear_flag(ui_Panel7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Panel7, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Panel7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ACName3 = lv_label_create(ui_Panel7);
    lv_obj_set_width(ui_ACName3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ACName3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ACName3, -1);
    lv_obj_set_y(ui_ACName3, 3);
    lv_obj_set_align(ui_ACName3, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_ACName3, "Air 1");
    lv_obj_set_style_text_font(ui_ACName3, &ui_font_font48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ACBedRoomTemp1 = lv_label_create(ui_Panel7);
    lv_obj_set_width(ui_ACBedRoomTemp1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ACBedRoomTemp1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ACBedRoomTemp1, -116);
    lv_obj_set_y(ui_ACBedRoomTemp1, 4);
    lv_obj_set_align(ui_ACBedRoomTemp1, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_ACBedRoomTemp1, "20°C");
    lv_obj_set_style_text_font(ui_ACBedRoomTemp1, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ACBedRoom1 = lv_switch_create(ui_Panel7);
    lv_obj_set_width(ui_ACBedRoom1, 70);
    lv_obj_set_height(ui_ACBedRoom1, 35);
    lv_obj_set_x(ui_ACBedRoom1, 8);
    lv_obj_set_y(ui_ACBedRoom1, -11);
    lv_obj_set_align(ui_ACBedRoom1, LV_ALIGN_BOTTOM_RIGHT);

    ui_Panel9 = lv_obj_create(ui_BedoomSceen);
    lv_obj_set_width(ui_Panel9, lv_pct(50));
    lv_obj_set_height(ui_Panel9, lv_pct(23));
    lv_obj_set_x(ui_Panel9, lv_pct(-50));
    lv_obj_set_y(ui_Panel9, lv_pct(-4));
    lv_obj_set_align(ui_Panel9, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_clear_flag(ui_Panel9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel9, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Panel9, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Panel9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ACName4 = lv_label_create(ui_Panel9);
    lv_obj_set_width(ui_ACName4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ACName4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ACName4, -4);
    lv_obj_set_y(ui_ACName4, -1);
    lv_obj_set_align(ui_ACName4, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_ACName4, "Air 2");
    lv_obj_set_style_text_font(ui_ACName4, &ui_font_font48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ACBedRoomTemp2 = lv_label_create(ui_Panel9);
    lv_obj_set_width(ui_ACBedRoomTemp2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ACBedRoomTemp2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ACBedRoomTemp2, -116);
    lv_obj_set_y(ui_ACBedRoomTemp2, 4);
    lv_obj_set_align(ui_ACBedRoomTemp2, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_ACBedRoomTemp2, "20°C");
    lv_obj_set_style_text_font(ui_ACBedRoomTemp2, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ACBedRoom2 = lv_switch_create(ui_Panel9);
    lv_obj_set_width(ui_ACBedRoom2, 70);
    lv_obj_set_height(ui_ACBedRoom2, 35);
    lv_obj_set_x(ui_ACBedRoom2, 7);
    lv_obj_set_y(ui_ACBedRoom2, -12);
    lv_obj_set_align(ui_ACBedRoom2, LV_ALIGN_BOTTOM_RIGHT);

    lv_obj_add_event_cb(ui_BackHome2, ui_event_BackHome2, LV_EVENT_ALL, NULL);

}

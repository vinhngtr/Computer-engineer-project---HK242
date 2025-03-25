// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.1
// LVGL version: 8.3.6
// Project name: Squareline

#ifndef _SQUARELINE_UI_H
#define _SQUARELINE_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "ui_events.h"

// SCREEN: ui_FirstScreen
void ui_FirstScreen_screen_init(void);
extern lv_obj_t * ui_FirstScreen;
extern lv_obj_t * ui_Panel1;
extern lv_obj_t * ui_Label3;
void ui_event_ImgButton1(lv_event_t * e);
extern lv_obj_t * ui_ImgButton1;
// CUSTOM VARIABLES

// SCREEN: ui_mainScreen
void ui_mainScreen_screen_init(void);
extern lv_obj_t * ui_mainScreen;
void ui_event_lvRoom(lv_event_t * e);
extern lv_obj_t * ui_lvRoom;
extern lv_obj_t * ui_roomName1;
extern lv_obj_t * ui_light1;
extern lv_obj_t * ui_fan1;
extern lv_obj_t * ui_ac1;
extern lv_obj_t * ui_kitchenRoom;
extern lv_obj_t * ui_roomName4;
extern lv_obj_t * ui_light4;
extern lv_obj_t * ui_fan4;
extern lv_obj_t * ui_ac4;
extern lv_obj_t * ui_bedRoom1;
extern lv_obj_t * ui_roomName2;
extern lv_obj_t * ui_light2;
extern lv_obj_t * ui_fan2;
extern lv_obj_t * ui_ac2;
extern lv_obj_t * ui_bedRoom2;
extern lv_obj_t * ui_roomName3;
extern lv_obj_t * ui_light3;
extern lv_obj_t * ui_fan3;
extern lv_obj_t * ui_ac3;
extern lv_obj_t * ui_bedRoom3;
extern lv_obj_t * ui_roomName5;
extern lv_obj_t * ui_light5;
extern lv_obj_t * ui_fan5;
extern lv_obj_t * ui_ac5;
void ui_event_eTemp(lv_event_t * e);
extern lv_obj_t * ui_eTemp;
extern lv_obj_t * ui_envTemp;
void ui_event_eHumi(lv_event_t * e);
extern lv_obj_t * ui_eHumi;
extern lv_obj_t * ui_envHumi;
// CUSTOM VARIABLES

// SCREEN: ui_lvRoomScreen
void ui_lvRoomScreen_screen_init(void);
extern lv_obj_t * ui_lvRoomScreen;
extern lv_obj_t * ui_Panel2;
extern lv_obj_t * ui_dvName1;
extern lv_obj_t * ui_lightName1;
extern lv_obj_t * ui_LightLvRoom1;
extern lv_obj_t * ui_LightLvRoom2;
extern lv_obj_t * ui_LightLvRoom3;
extern lv_obj_t * ui_LightLvRoom4;
extern lv_obj_t * ui_LightLvRoom5;
extern lv_obj_t * ui_LightLvRoom6;
extern lv_obj_t * ui_Panel3;
extern lv_obj_t * ui_dvName2;
extern lv_obj_t * ui_fanName1;
extern lv_obj_t * ui_FanLvRoom1;
extern lv_obj_t * ui_FanLvRoom2;
extern lv_obj_t * ui_Panel4;
extern lv_obj_t * ui_ACName1;
void ui_event_Slider1(lv_event_t * e);
extern lv_obj_t * ui_Slider1;
extern lv_obj_t * ui_ACLvRoomTemp1;
extern lv_obj_t * ui_Switch2;
extern lv_obj_t * ui_Panel8;
extern lv_obj_t * ui_ACName2;
void ui_event_Slider3(lv_event_t * e);
extern lv_obj_t * ui_Slider3;
extern lv_obj_t * ui_ACLvRoomTemp2;
extern lv_obj_t * ui_Switch3;
void ui_event_ImgButton2(lv_event_t * e);
extern lv_obj_t * ui_ImgButton2;
// CUSTOM VARIABLES

// SCREEN: ui_bedRoomScreen1
void ui_bedRoomScreen1_screen_init(void);
extern lv_obj_t * ui_bedRoomScreen1;
extern lv_obj_t * ui_Panel5;
extern lv_obj_t * ui_dvName3;
extern lv_obj_t * ui_lightName2;
extern lv_obj_t * ui_LightBedRoom1;
extern lv_obj_t * ui_LightBedRoom2;
extern lv_obj_t * ui_LightBedRoom3;
extern lv_obj_t * ui_LightBedRoom4;
extern lv_obj_t * ui_LightBedRoom5;
extern lv_obj_t * ui_LightBedRoom6;
extern lv_obj_t * ui_Panel6;
extern lv_obj_t * ui_dvName4;
extern lv_obj_t * ui_fanName2;
extern lv_obj_t * ui_FanBedRoom1;
extern lv_obj_t * ui_FanBedRoom2;
extern lv_obj_t * ui_Panel7;
extern lv_obj_t * ui_ACName3;
void ui_event_Slider2(lv_event_t * e);
extern lv_obj_t * ui_Slider2;
extern lv_obj_t * ui_ACBedRoomTemp1;
extern lv_obj_t * ui_Switch1;
extern lv_obj_t * ui_Panel9;
extern lv_obj_t * ui_ACName4;
void ui_event_Slider4(lv_event_t * e);
extern lv_obj_t * ui_Slider4;
extern lv_obj_t * ui_ACBedRoomTemp2;
extern lv_obj_t * ui_Switch4;
// CUSTOM VARIABLES

// EVENTS

extern lv_obj_t * ui____initial_actions0;

// IMAGES AND IMAGE SETS
LV_IMG_DECLARE(ui_img_115668498);    // assets/next (1).png

// FONTS
LV_FONT_DECLARE(ui_font_font32);
LV_FONT_DECLARE(ui_font_font48);
LV_FONT_DECLARE(ui_font_font20);

// UI INIT
void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif

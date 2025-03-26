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
extern lv_obj_t * ui_mainLightLVROOM;
extern lv_obj_t * ui_mainFanLVROOM;
extern lv_obj_t * ui_mainACLVROOM;
extern lv_obj_t * ui_kitchenRoom;
extern lv_obj_t * ui_roomName4;
extern lv_obj_t * ui_light4;
extern lv_obj_t * ui_fan4;
extern lv_obj_t * ui_ac4;
void ui_event_bedRoom1(lv_event_t * e);
extern lv_obj_t * ui_bedRoom1;
extern lv_obj_t * ui_roomName2;
extern lv_obj_t * ui_mainLightBEDROOM1;
extern lv_obj_t * ui_mainFanBEDROOM1;
extern lv_obj_t * ui_mainACBEDROOM1;
void ui_event_bedRoom2(lv_event_t * e);
extern lv_obj_t * ui_bedRoom2;
extern lv_obj_t * ui_roomName3;
extern lv_obj_t * ui_mainLightBEDROOM2;
extern lv_obj_t * ui_mainFanBEDROOM2;
extern lv_obj_t * ui_mainACBEDROOM2;
extern lv_obj_t * ui_resroom;
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
void ui_event_lvRoomScreen(lv_event_t * e);
extern lv_obj_t * ui_lvRoomScreen;
extern lv_obj_t * ui_Panel2;
extern lv_obj_t * ui_dvName1;
extern lv_obj_t * ui_lightName1;
void ui_event_LightLvRoom1(lv_event_t * e);
extern lv_obj_t * ui_LightLvRoom1;
extern lv_obj_t * ui_LightLvRoom2;
extern lv_obj_t * ui_LightLvRoom3;
extern lv_obj_t * ui_LightLvRoom4;
extern lv_obj_t * ui_LightLvRoom5;
extern lv_obj_t * ui_LightLvRoom6;
extern lv_obj_t * ui_Panel3;
extern lv_obj_t * ui_dvName2;
extern lv_obj_t * ui_fanName1;
void ui_event_FanLvRoom1(lv_event_t * e);
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
extern lv_obj_t * ui_lvRoomValue;
// CUSTOM VARIABLES

// SCREEN: ui_bedRoomScreen1
void ui_bedRoomScreen1_screen_init(void);
extern lv_obj_t * ui_bedRoomScreen1;
extern lv_obj_t * ui_Panel5;
extern lv_obj_t * ui_dvName3;
extern lv_obj_t * ui_lightName2;
void ui_event_LightBedRoom1(lv_event_t * e);
extern lv_obj_t * ui_LightBedRoom1;
void ui_event_LightBedRoom2(lv_event_t * e);
extern lv_obj_t * ui_LightBedRoom2;
void ui_event_LightBedRoom3(lv_event_t * e);
extern lv_obj_t * ui_LightBedRoom3;
void ui_event_LightBedRoom4(lv_event_t * e);
extern lv_obj_t * ui_LightBedRoom4;
void ui_event_LightBedRoom5(lv_event_t * e);
extern lv_obj_t * ui_LightBedRoom5;
void ui_event_LightBedRoom6(lv_event_t * e);
extern lv_obj_t * ui_LightBedRoom6;
extern lv_obj_t * ui_Panel6;
extern lv_obj_t * ui_dvName4;
extern lv_obj_t * ui_fanName2;
void ui_event_FanBedRoom1(lv_event_t * e);
extern lv_obj_t * ui_FanBedRoom1;
void ui_event_FanBedRoom2(lv_event_t * e);
extern lv_obj_t * ui_FanBedRoom2;
extern lv_obj_t * ui_Panel7;
extern lv_obj_t * ui_ACName3;
void ui_event_ac1control(lv_event_t * e);
extern lv_obj_t * ui_ac1control;
extern lv_obj_t * ui_ACBedRoomTemp1;
void ui_event_ACBedRoom1(lv_event_t * e);
extern lv_obj_t * ui_ACBedRoom1;
extern lv_obj_t * ui_Panel9;
extern lv_obj_t * ui_ACName4;
void ui_event_ac2control(lv_event_t * e);
extern lv_obj_t * ui_ac2control;
extern lv_obj_t * ui_ACBedRoomTemp2;
extern lv_obj_t * ui_ACBedRoom2;
void ui_event_ImgButton4(lv_event_t * e);
extern lv_obj_t * ui_ImgButton4;
void ui_event_LBRSlider1(lv_event_t * e);
extern lv_obj_t * ui_LBRSlider1;
void ui_event_LBRSlider2(lv_event_t * e);
extern lv_obj_t * ui_LBRSlider2;
void ui_event_LBRSlider3(lv_event_t * e);
extern lv_obj_t * ui_LBRSlider3;
// CUSTOM VARIABLES

// SCREEN: ui_bedRoomScreen2
void ui_bedRoomScreen2_screen_init(void);
extern lv_obj_t * ui_bedRoomScreen2;
extern lv_obj_t * ui_Panel10;
extern lv_obj_t * ui_dvName5;
extern lv_obj_t * ui_lightName3;
void ui_event_LightBedRoom7(lv_event_t * e);
extern lv_obj_t * ui_LightBedRoom7;
void ui_event_LightBedRoom8(lv_event_t * e);
extern lv_obj_t * ui_LightBedRoom8;
void ui_event_LightBedRoom9(lv_event_t * e);
extern lv_obj_t * ui_LightBedRoom9;
void ui_event_LightBedRoom10(lv_event_t * e);
extern lv_obj_t * ui_LightBedRoom10;
void ui_event_LightBedRoom11(lv_event_t * e);
extern lv_obj_t * ui_LightBedRoom11;
void ui_event_LightBedRoom12(lv_event_t * e);
extern lv_obj_t * ui_LightBedRoom12;
extern lv_obj_t * ui_Panel11;
extern lv_obj_t * ui_dvName6;
extern lv_obj_t * ui_fanName3;
void ui_event_FanBedRoom3(lv_event_t * e);
extern lv_obj_t * ui_FanBedRoom3;
void ui_event_FanBedRoom4(lv_event_t * e);
extern lv_obj_t * ui_FanBedRoom4;
extern lv_obj_t * ui_Panel12;
extern lv_obj_t * ui_ACName5;
void ui_event_ac1control1(lv_event_t * e);
extern lv_obj_t * ui_ac1control1;
extern lv_obj_t * ui_ACBedRoomTemp3;
void ui_event_ACBedRoom3(lv_event_t * e);
extern lv_obj_t * ui_ACBedRoom3;
extern lv_obj_t * ui_Panel13;
extern lv_obj_t * ui_ACName6;
void ui_event_ac2control1(lv_event_t * e);
extern lv_obj_t * ui_ac2control1;
extern lv_obj_t * ui_ACBedRoomTemp4;
extern lv_obj_t * ui_ACBedRoom4;
void ui_event_ImgButton3(lv_event_t * e);
extern lv_obj_t * ui_ImgButton3;
void ui_event_LBRSlider4(lv_event_t * e);
extern lv_obj_t * ui_LBRSlider4;
void ui_event_LBRSlider5(lv_event_t * e);
extern lv_obj_t * ui_LBRSlider5;
void ui_event_LBRSlider6(lv_event_t * e);
extern lv_obj_t * ui_LBRSlider6;
// CUSTOM VARIABLES

// EVENTS

extern lv_obj_t * ui____initial_actions0;

// IMAGES AND IMAGE SETS
LV_IMG_DECLARE(ui_img_115668498);    // assets/next (1).png

// FONTS
LV_FONT_DECLARE(ui_font_font20);
LV_FONT_DECLARE(ui_font_font32);
LV_FONT_DECLARE(ui_font_font48);

// UI INIT
void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif

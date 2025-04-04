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
void ui_event_btnHome(lv_event_t * e);
extern lv_obj_t * ui_btnHome;
extern lv_obj_t * ui_Image3;
// CUSTOM VARIABLES

// SCREEN: ui_mainScreen
void ui_mainScreen_screen_init(void);
extern lv_obj_t * ui_mainScreen;
extern lv_obj_t * ui_TabView1;
extern lv_obj_t * ui_TabView2;
void ui_event_KitchenRoom(lv_event_t * e);
extern lv_obj_t * ui_KitchenRoom;
extern lv_obj_t * ui_roomName3;
extern lv_obj_t * ui_LightKitRoom;
extern lv_obj_t * ui_FanKitRoom;
extern lv_obj_t * ui_AirKitRoom;
extern lv_obj_t * ui_titleBtn2;
extern lv_obj_t * ui_LightActive2;
extern lv_obj_t * ui_FanActive2;
extern lv_obj_t * ui_AirActive2;
void ui_event_BedRoom(lv_event_t * e);
extern lv_obj_t * ui_BedRoom;
extern lv_obj_t * ui_roomName4;
extern lv_obj_t * ui_LightBedRoom;
extern lv_obj_t * ui_FanBedRoom;
extern lv_obj_t * ui_AirBedRoom;
extern lv_obj_t * ui_titleComp1;
void ui_event_BedActiveLight(lv_event_t * e);
extern lv_obj_t * ui_BedActiveLight;
void ui_event_BedActiveFan(lv_event_t * e);
extern lv_obj_t * ui_BedActiveFan;
void ui_event_BedActiveAC(lv_event_t * e);
extern lv_obj_t * ui_BedActiveAC;
void ui_event_LvRoom(lv_event_t * e);
extern lv_obj_t * ui_LvRoom;
extern lv_obj_t * ui_roomName1;
extern lv_obj_t * ui_LightLvRoom;
extern lv_obj_t * ui_FanLvRoom;
extern lv_obj_t * ui_AirLvRoom;
extern lv_obj_t * ui_titleComp;
void ui_event_LivActiveLight(lv_event_t * e);
extern lv_obj_t * ui_LivActiveLight;
extern lv_obj_t * ui_CountLight;
void ui_event_LivActiveFan(lv_event_t * e);
extern lv_obj_t * ui_LivActiveFan;
extern lv_obj_t * ui_CountFan;
void ui_event_LivActiveAC(lv_event_t * e);
extern lv_obj_t * ui_LivActiveAC;
extern lv_obj_t * ui_CountAC;
void ui_event_TempChart(lv_event_t * e);
extern lv_obj_t * ui_TempChart;
extern lv_obj_t * ui_TitleTemp;
extern lv_obj_t * ui_ValueTemp;
void ui_event_HumidityChart(lv_event_t * e);
extern lv_obj_t * ui_HumidityChart;
extern lv_obj_t * ui_TitleHumi;
extern lv_obj_t * ui_ValueHumi;
extern lv_obj_t * ui_HeaedMain;
extern lv_obj_t * ui_TitleVIEW;
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
void ui_event_LightLvRoom2(lv_event_t * e);
extern lv_obj_t * ui_LightLvRoom2;
void ui_event_LightLvRoom3(lv_event_t * e);
extern lv_obj_t * ui_LightLvRoom3;
void ui_event_BackHome(lv_event_t * e);
extern lv_obj_t * ui_BackHome;
extern lv_obj_t * ui_Image4;
extern lv_obj_t * ui_Panel3;
extern lv_obj_t * ui_dvName2;
extern lv_obj_t * ui_fanName1;
extern lv_obj_t * ui_FanLvRoom1;
extern lv_obj_t * ui_FanLvRoom2;
extern lv_obj_t * ui_Panel4;
extern lv_obj_t * ui_ACName1;
extern lv_obj_t * ui_ACLvRoomTemp1;
extern lv_obj_t * ui_Switch2;
extern lv_obj_t * ui_Panel8;
extern lv_obj_t * ui_ACName2;
extern lv_obj_t * ui_ACLvRoomTemp2;
extern lv_obj_t * ui_Switch1;
// CUSTOM VARIABLES

// SCREEN: ui_BedoomSceen
void ui_BedoomSceen_screen_init(void);
extern lv_obj_t * ui_BedoomSceen;
extern lv_obj_t * ui_Panel5;
extern lv_obj_t * ui_dvName3;
extern lv_obj_t * ui_lightName2;
extern lv_obj_t * ui_LightBedRoom1;
extern lv_obj_t * ui_LightBedRoom2;
extern lv_obj_t * ui_LightBedRoom3;
void ui_event_BackHome2(lv_event_t * e);
extern lv_obj_t * ui_BackHome2;
extern lv_obj_t * ui_Image2;
extern lv_obj_t * ui_Panel6;
extern lv_obj_t * ui_dvName4;
extern lv_obj_t * ui_fanName2;
extern lv_obj_t * ui_FanBedRoom1;
extern lv_obj_t * ui_FanBedRoom2;
extern lv_obj_t * ui_Panel7;
extern lv_obj_t * ui_ACName3;
extern lv_obj_t * ui_ACBedRoomTemp1;
extern lv_obj_t * ui_ACBedRoom1;
extern lv_obj_t * ui_Panel9;
extern lv_obj_t * ui_ACName4;
extern lv_obj_t * ui_ACBedRoomTemp2;
extern lv_obj_t * ui_ACBedRoom2;
// CUSTOM VARIABLES

// SCREEN: ui_KitchenSceen
void ui_KitchenSceen_screen_init(void);
extern lv_obj_t * ui_KitchenSceen;
extern lv_obj_t * ui_Panel10;
extern lv_obj_t * ui_dvName5;
extern lv_obj_t * ui_lightName3;
extern lv_obj_t * ui_SWLightBed1;
extern lv_obj_t * ui_SWLightBed2;
extern lv_obj_t * ui_SWLightBed3;
void ui_event_BackHome3(lv_event_t * e);
extern lv_obj_t * ui_BackHome3;
extern lv_obj_t * ui_Image5;
extern lv_obj_t * ui_Panel11;
extern lv_obj_t * ui_dvName6;
extern lv_obj_t * ui_fanName3;
extern lv_obj_t * ui_SWFanBed1;
extern lv_obj_t * ui_SWFanBed2;
extern lv_obj_t * ui_Panel12;
extern lv_obj_t * ui_AirKIT1;
extern lv_obj_t * ui_valTempKIT;
extern lv_obj_t * ui_SWAirKIT1;
extern lv_obj_t * ui_Panel13;
extern lv_obj_t * ui_ACName6;
extern lv_obj_t * ui_valTempKIT2;
extern lv_obj_t * ui_SWAirKIT2;
// CUSTOM VARIABLES

// EVENTS

extern lv_obj_t * ui____initial_actions0;

// IMAGES AND IMAGE SETS
LV_IMG_DECLARE(ui_img_115668498);    // assets/next (1).png
LV_IMG_DECLARE(ui_img_1385603933);    // assets/icons8-left-25.png

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

SET(SOURCES screens/ui_Initial_Screen.c
    screens/ui_SetingWifi.c
    screens/ui_mainScreen.c
    screens/ui_LVRoomScreen.c
    screens/ui_BedoomSceen.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.cpp
    images/ui_img_hcmut_png.c
    images/ui_img_1385603933.c
    fonts/ui_font_Font20.c
    fonts/ui_font_Font30.c
    fonts/ui_font_Font48.c)

add_library(ui ${SOURCES})

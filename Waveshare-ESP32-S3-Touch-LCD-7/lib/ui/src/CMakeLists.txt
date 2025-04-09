SET(SOURCES screens/ui_FirstScreen.c
    screens/ui_mainScreen.c
    screens/ui_LVRoomScreen.c
    screens/ui_BedoomSceen.c
    screens/ui_KitchenSceen.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.cpp
    images/ui_img_115668498.c
    images/ui_img_1385603933.c
    fonts/ui_font_font20.c
    fonts/ui_font_font32.c
    fonts/ui_font_font48.c)

add_library(ui ${SOURCES})

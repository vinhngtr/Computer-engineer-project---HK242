SET(SOURCES screens/ui_FirstScreen.c
    screens/ui_SecondScreen.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    images/ui_img_115668498.c
    fonts/ui_font_font48.c)

add_library(ui ${SOURCES})

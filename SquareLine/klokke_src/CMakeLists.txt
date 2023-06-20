SET(SOURCES screens/ui_landing_page.c
    screens/ui_PasswordScreen.c
    screens/ui_Unlocking.c
    screens/ui_unlocked_screen.c
    screens/ui_not_unlocked_screen.c
    ui.c
    ui_helpers.c
    images/ui_img_32757238.c
    images/ui_img_1114486417.c)

add_library(ui ${SOURCES})

SET(SOURCES screens/ui_landing_page.c
    screens/ui_PasswordScreen.c
    screens/ui_Unlocking.c
    screens/ui_unlocked_screen.c
    screens/ui_not_unlocked_screen.c
    screens/ui_ringing_screen.c
    screens/ui_not_ringing_screen.c
    ui.c
    ui_helpers.c
    images/ui_img_32757238.c
    images/ui_img_1114486417.c
    images/ui_img_1999303404.c
    images/ui_img_15611405.c
    images/ui_img_1048971941.c
    images/ui_img_386404288.c)

add_library(ui ${SOURCES})

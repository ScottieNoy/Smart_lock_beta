SET(SOURCES screens/ui_landing_page.c
    screens/ui_add_passcode_screen.c
    screens/ui_Unlocking.c
    screens/ui_passcode_control_screen.c
    screens/ui_adding_passcode_screen.c
    screens/ui_removing_passcode_screen.c
    screens/ui_remove_passcode_screen.c
    screens/ui_notification_screen.c
    ui.c
    ui_helpers.c
    ui_events.c
    images/ui_img_1999303404.c
    images/ui_img_15611405.c
    images/ui_img_1114486417.c
    images/ui_img_32757238.c
    images/ui_img_1048971941.c
    images/ui_img_386404288.c)

add_library(ui ${SOURCES})

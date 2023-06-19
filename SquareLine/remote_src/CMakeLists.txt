SET(SOURCES screens/ui_landing_page.c
    screens/ui_add_passcode_screen.c
    screens/ui_Unlocking.c
    screens/ui_passcode_control_screen.c
    screens/ui_adding_passcode_screen.c
    screens/ui_removing_passcode_screen.c
    screens/ui_remove_passcode_screen.c
    ui.c
    ui_helpers.c)

add_library(ui ${SOURCES})

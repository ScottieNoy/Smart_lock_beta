SET(SOURCES screens/ui_landing_page.c
    screens/ui_PasswordScreen.c
    screens/ui_Unlocking.c
    ui.c
    ui_helpers.c
    ui_events.c)

add_library(ui ${SOURCES})

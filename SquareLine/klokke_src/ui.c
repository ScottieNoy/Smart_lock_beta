// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: klokke

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////

// SCREEN: ui_landing_page
void ui_landing_page_screen_init(void);
void ui_event_landing_page( lv_event_t * e);
lv_obj_t *ui_landing_page;
lv_obj_t *ui_Buttonpanel;
lv_obj_t *ui_DateBatteryPanelMain;
lv_obj_t *ui_date_placeholder;
void ui_event_button1( lv_event_t * e);
lv_obj_t *ui_button1;
lv_obj_t *ui_passcode_button_label1;
lv_obj_t *ui_cam_panel;
lv_obj_t *ui_Image1;

// SCREEN: ui_PasswordScreen
void ui_PasswordScreen_screen_init(void);
lv_obj_t *ui_PasswordScreen;
lv_obj_t *ui_Buttonpanel1;
void ui_event_delivery_button1( lv_event_t * e);
lv_obj_t *ui_delivery_button1;
lv_obj_t *ui_Go_Back;
lv_obj_t *ui_DateBatteryPanelPassword;
lv_obj_t *ui_date_placeholder1;
void ui_event_PasswordKeyboard( lv_event_t * e);
lv_obj_t *ui_PasswordKeyboard;
void ui_event_passwordArea( lv_event_t * e);
lv_obj_t *ui_passwordArea;

// SCREEN: ui_Unlocking
void ui_Unlocking_screen_init(void);
void ui_event_Unlocking( lv_event_t * e);
lv_obj_t *ui_Unlocking;
lv_obj_t *ui_Spinner2;
lv_obj_t *ui_Label1;

// SCREEN: ui_unlocked_screen
void ui_unlocked_screen_screen_init(void);
void ui_event_unlocked_screen( lv_event_t * e);
lv_obj_t *ui_unlocked_screen;
lv_obj_t *ui_unlocked_label;
lv_obj_t *ui_unlocked_image;

// SCREEN: ui_not_unlocked_screen
void ui_not_unlocked_screen_screen_init(void);
void ui_event_not_unlocked_screen( lv_event_t * e);
lv_obj_t *ui_not_unlocked_screen;
lv_obj_t *ui_not_unlocked_label;
lv_obj_t *ui_not_unlocked_image;

// SCREEN: ui_ringing_screen
void ui_ringing_screen_screen_init(void);
void ui_event_ringing_screen( lv_event_t * e);
lv_obj_t *ui_ringing_screen;
lv_obj_t *ui_ringing_label;
lv_obj_t *ui_ringing_image;

// SCREEN: ui_not_ringing_screen
void ui_not_ringing_screen_screen_init(void);
void ui_event_not_ringing_screen( lv_event_t * e);
lv_obj_t *ui_not_ringing_screen;
lv_obj_t *ui_not_ringing_label;
lv_obj_t *ui_not_ringing_image;
lv_obj_t *ui____initial_actions0;
const lv_img_dsc_t *ui_imgset_861137800[4] = {&ui_img_1114486417, &ui_img_32757238, &ui_img_1048971941, &ui_img_386404288};
const lv_img_dsc_t *ui_imgset_1515648418[1] = {&ui_img_15611405};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_landing_page( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_SCREEN_LOADED) {
      beginServer( e );
}
if ( event_code == LV_EVENT_SCREEN_UNLOADED) {
      stopServer( e );
}
}
void ui_event_button1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_RELEASED) {
      _ui_screen_change( ui_PasswordScreen, LV_SCR_LOAD_ANIM_NONE, 500, 0);
}
}
void ui_event_delivery_button1( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_RELEASED) {
      _ui_screen_change( ui_landing_page, LV_SCR_LOAD_ANIM_NONE, 500, 0);
}
}
void ui_event_PasswordKeyboard( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT  ) {
lv_indev_wait_release(lv_indev_get_act());
      _ui_screen_change( ui_Unlocking, LV_SCR_LOAD_ANIM_NONE, 500, 0);
}
}
void ui_event_passwordArea( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_VALUE_CHANGED) {
      unlock( e );
}
}
void ui_event_Unlocking( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_SCREEN_LOADED) {
      unlocking( e );
}
}
void ui_event_unlocked_screen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_SCREEN_LOADED) {
      _ui_screen_change( ui_landing_page, LV_SCR_LOAD_ANIM_NONE, 500, 5000);
}
}
void ui_event_not_unlocked_screen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_SCREEN_LOADED) {
      _ui_screen_change( ui_landing_page, LV_SCR_LOAD_ANIM_NONE, 500, 5000);
}
}
void ui_event_ringing_screen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_SCREEN_LOADED) {
      _ui_screen_change( ui_landing_page, LV_SCR_LOAD_ANIM_NONE, 500, 5000);
}
}
void ui_event_not_ringing_screen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_SCREEN_LOADED) {
      _ui_screen_change( ui_landing_page, LV_SCR_LOAD_ANIM_NONE, 500, 5000);
}
}

///////////////////// SCREENS ////////////////////

void ui_init( void )
{
lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_landing_page_screen_init();
ui_PasswordScreen_screen_init();
ui_Unlocking_screen_init();
ui_unlocked_screen_screen_init();
ui_not_unlocked_screen_screen_init();
ui_ringing_screen_screen_init();
ui_not_ringing_screen_screen_init();
ui____initial_actions0 = lv_obj_create(NULL);
lv_disp_load_scr( ui_landing_page);
}

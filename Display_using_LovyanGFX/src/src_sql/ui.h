// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: klokke

#ifndef _KLOKKE_UI_H
#define _KLOKKE_UI_H

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
// SCREEN: ui_landing_page
void ui_landing_page_screen_init(void);
void ui_event_landing_page( lv_event_t * e);
extern lv_obj_t *ui_landing_page;
extern lv_obj_t *ui_Buttonpanel;
extern lv_obj_t *ui_DateBatteryPanelMain;
extern lv_obj_t *ui_date_placeholder;
extern lv_obj_t *ui_battery_placeholder;
void ui_event_button1( lv_event_t * e);
extern lv_obj_t *ui_button1;
extern lv_obj_t *ui_passcode_button_label1;
void ui_event_delivery_button( lv_event_t * e);
extern lv_obj_t *ui_delivery_button;
extern lv_obj_t *ui_delivery_button_label;
extern lv_obj_t *ui_cam_panel;
extern lv_obj_t *ui_Image1;
// SCREEN: ui_PasswordScreen
void ui_PasswordScreen_screen_init(void);
extern lv_obj_t *ui_PasswordScreen;
extern lv_obj_t *ui_Buttonpanel1;
void ui_event_delivery_button1( lv_event_t * e);
extern lv_obj_t *ui_delivery_button1;
extern lv_obj_t *ui_Go_Back;
extern lv_obj_t *ui_DateBatteryPanelPassword;
extern lv_obj_t *ui_date_placeholder1;
extern lv_obj_t *ui_battery_placeholder1;
extern lv_obj_t *ui_PasswordKeyboard;
extern lv_obj_t *ui_TextArea1;
// SCREEN: ui_Unlocking
void ui_Unlocking_screen_init(void);
void ui_event_Unlocking( lv_event_t * e);
extern lv_obj_t *ui_Unlocking;
extern lv_obj_t *ui_Spinner2;
extern lv_obj_t *ui_Label1;
extern lv_obj_t *ui____initial_actions0;

void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif

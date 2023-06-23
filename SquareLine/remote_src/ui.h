// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: remote

#ifndef _REMOTE_UI_H
#define _REMOTE_UI_H

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
void ui_event_passcode_control_button( lv_event_t * e);
extern lv_obj_t *ui_passcode_control_button;
extern lv_obj_t *ui_passcode_control_label;
void ui_event_Unlock_button( lv_event_t * e);
extern lv_obj_t *ui_Unlock_button;
extern lv_obj_t *ui_Unlock_button_label;
extern lv_obj_t *ui_cam_panel;
extern lv_obj_t *ui_Image1;
// SCREEN: ui_add_passcode_screen
void ui_add_passcode_screen_screen_init(void);
extern lv_obj_t *ui_add_passcode_screen;
extern lv_obj_t *ui_add_passcode_go_back_button_pane;
void ui_event_add_passcode_go_back_button( lv_event_t * e);
extern lv_obj_t *ui_add_passcode_go_back_button;
extern lv_obj_t *ui_add_passcode_go_back_button_labe;
extern lv_obj_t *ui_DateBatteryPanelPassword;
extern lv_obj_t *ui_date_placeholder1;
extern lv_obj_t *ui_battery_placeholder1;
void ui_event_add_passcode_keyboard( lv_event_t * e);
extern lv_obj_t *ui_add_passcode_keyboard;
void ui_event_add_passcode_text_area( lv_event_t * e);
extern lv_obj_t *ui_add_passcode_text_area;
// SCREEN: ui_Unlocking
void ui_Unlocking_screen_init(void);
void ui_event_Unlocking( lv_event_t * e);
extern lv_obj_t *ui_Unlocking;
extern lv_obj_t *ui_unlocking_screen_spinner;
extern lv_obj_t *ui_Label1;
// SCREEN: ui_passcode_control_screen
void ui_passcode_control_screen_screen_init(void);
extern lv_obj_t *ui_passcode_control_screen;
extern lv_obj_t *ui_passcode_control_label1;
extern lv_obj_t *ui_go_back_button_panel;
void ui_event_passcode_control_go_back_button( lv_event_t * e);
extern lv_obj_t *ui_passcode_control_go_back_button;
extern lv_obj_t *ui_passcode_control_go_back_but_lab;
extern lv_obj_t *ui_DateBatteryPanelPassword1;
extern lv_obj_t *ui_date_placeholder2;
extern lv_obj_t *ui_battery_placeholder2;
extern lv_obj_t *ui_Buttonpanel3;
void ui_event_add_passcode_button( lv_event_t * e);
extern lv_obj_t *ui_add_passcode_button;
extern lv_obj_t *ui_add_passcode_button_label;
void ui_event_remove_passcode_button( lv_event_t * e);
extern lv_obj_t *ui_remove_passcode_button;
extern lv_obj_t *ui_remove_passcode_button_label;
// SCREEN: ui_adding_passcode_screen
void ui_adding_passcode_screen_screen_init(void);
void ui_event_adding_passcode_screen( lv_event_t * e);
extern lv_obj_t *ui_adding_passcode_screen;
extern lv_obj_t *ui_adding_passcode_spinner;
extern lv_obj_t *ui_Adding_Passcode_label;
// SCREEN: ui_removing_passcode_screen
void ui_removing_passcode_screen_screen_init(void);
void ui_event_removing_passcode_screen( lv_event_t * e);
extern lv_obj_t *ui_removing_passcode_screen;
extern lv_obj_t *ui_remove_passcode_spinner;
extern lv_obj_t *ui_remove_Passcode_label;
// SCREEN: ui_remove_passcode_screen
void ui_remove_passcode_screen_screen_init(void);
extern lv_obj_t *ui_remove_passcode_screen;
extern lv_obj_t *ui_remove_passcode;
void ui_event_remove_passcode_go_back_button( lv_event_t * e);
extern lv_obj_t *ui_remove_passcode_go_back_button;
extern lv_obj_t *ui_remove_passcode_go_back_button_l;
extern lv_obj_t *ui_DateBatteryPanelPassword2;
extern lv_obj_t *ui_date_placeholder3;
extern lv_obj_t *ui_battery_placeholder3;
void ui_event_remove_passcode_keyboard( lv_event_t * e);
extern lv_obj_t *ui_remove_passcode_keyboard;
void ui_event_remove_passcode_text_area( lv_event_t * e);
extern lv_obj_t *ui_remove_passcode_text_area;
// SCREEN: ui_notification_screen
void ui_notification_screen_screen_init(void);
void ui_event_notification_screen( lv_event_t * e);
extern lv_obj_t *ui_notification_screen;
extern lv_obj_t *ui_notification_labl;
extern lv_obj_t *ui_Image3;
void ui_event_remove_passcode_go_back_button1( lv_event_t * e);
extern lv_obj_t *ui_remove_passcode_go_back_button1;
extern lv_obj_t *ui_remove_passcode_go_back_button_l;
extern lv_obj_t *ui____initial_actions0;

LV_IMG_DECLARE( ui_img_1999303404);   // assets/output-onlinepngtools.png
LV_IMG_DECLARE( ui_img_15611405);   // assets/output-onlinepngtools-2.png
LV_IMG_DECLARE( ui_img_1114486417);   // assets/pngwing.com-2.png
LV_IMG_DECLARE( ui_img_32757238);   // assets/pngwing.com-3.png
LV_IMG_DECLARE( ui_img_1048971941);   // assets/pngwing.com-4.png
LV_IMG_DECLARE( ui_img_386404288);   // assets/pngwing.com-5.png

void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif

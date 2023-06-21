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
void ui_event_button1( lv_event_t * e);
extern lv_obj_t *ui_button1;
extern lv_obj_t *ui_passcode_button_label1;
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
void ui_event_PasswordKeyboard( lv_event_t * e);
extern lv_obj_t *ui_PasswordKeyboard;
void ui_event_passwordArea( lv_event_t * e);
extern lv_obj_t *ui_passwordArea;
// SCREEN: ui_Unlocking
void ui_Unlocking_screen_init(void);
void ui_event_Unlocking( lv_event_t * e);
extern lv_obj_t *ui_Unlocking;
extern lv_obj_t *ui_Spinner2;
extern lv_obj_t *ui_Label1;
// SCREEN: ui_unlocked_screen
void ui_unlocked_screen_screen_init(void);
void ui_event_unlocked_screen( lv_event_t * e);
extern lv_obj_t *ui_unlocked_screen;
extern lv_obj_t *ui_unlocked_label;
extern lv_obj_t *ui_unlocked_image;
// SCREEN: ui_not_unlocked_screen
void ui_not_unlocked_screen_screen_init(void);
void ui_event_not_unlocked_screen( lv_event_t * e);
extern lv_obj_t *ui_not_unlocked_screen;
extern lv_obj_t *ui_not_unlocked_label;
extern lv_obj_t *ui_not_unlocked_image;
// SCREEN: ui_ringing_screen
void ui_ringing_screen_screen_init(void);
void ui_event_ringing_screen( lv_event_t * e);
extern lv_obj_t *ui_ringing_screen;
extern lv_obj_t *ui_ringing_label;
extern lv_obj_t *ui_ringing_image;
// SCREEN: ui_not_ringing_screen
void ui_not_ringing_screen_screen_init(void);
void ui_event_not_ringing_screen( lv_event_t * e);
extern lv_obj_t *ui_not_ringing_screen;
extern lv_obj_t *ui_not_ringing_label;
extern lv_obj_t *ui_not_ringing_image;
extern lv_obj_t *ui____initial_actions0;

LV_IMG_DECLARE( ui_img_32757238);   // assets/pngwing.com-3.png
LV_IMG_DECLARE( ui_img_1114486417);   // assets/pngwing.com-2.png
LV_IMG_DECLARE( ui_img_1999303404);   // assets/output-onlinepngtools.png
LV_IMG_DECLARE( ui_img_15611405);   // assets/output-onlinepngtools-2.png
LV_IMG_DECLARE( ui_img_1048971941);   // assets/pngwing.com-4.png
LV_IMG_DECLARE( ui_img_386404288);   // assets/pngwing.com-5.png

void ui_init(void);
extern char date[20];

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif

// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: remote

#include "../ui.h"

void ui_landing_page_screen_init(void)
{
ui_landing_page = lv_obj_create(NULL);
lv_obj_clear_flag( ui_landing_page, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Buttonpanel = lv_obj_create(ui_landing_page);
lv_obj_set_width( ui_Buttonpanel, 320);
lv_obj_set_height( ui_Buttonpanel, 180);
lv_obj_set_x( ui_Buttonpanel, 0 );
lv_obj_set_y( ui_Buttonpanel, 150 );
lv_obj_set_align( ui_Buttonpanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Buttonpanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Buttonpanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Buttonpanel, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Buttonpanel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_Buttonpanel, lv_color_hex(0xFF4136), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Buttonpanel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Buttonpanel, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_Buttonpanel, LV_BORDER_SIDE_TOP, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_DateBatteryPanelMain = lv_obj_create(ui_landing_page);
lv_obj_set_width( ui_DateBatteryPanelMain, 320);
lv_obj_set_height( ui_DateBatteryPanelMain, 60);
lv_obj_set_x( ui_DateBatteryPanelMain, 0 );
lv_obj_set_y( ui_DateBatteryPanelMain, -210 );
lv_obj_set_align( ui_DateBatteryPanelMain, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_DateBatteryPanelMain, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_DateBatteryPanelMain, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_DateBatteryPanelMain, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_DateBatteryPanelMain, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_DateBatteryPanelMain, lv_color_hex(0xFF4136), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_DateBatteryPanelMain, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_DateBatteryPanelMain, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_DateBatteryPanelMain, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_date_placeholder = lv_label_create(ui_DateBatteryPanelMain);
lv_obj_set_width( ui_date_placeholder, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_date_placeholder, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_date_placeholder, LV_ALIGN_LEFT_MID );
lv_label_set_text(ui_date_placeholder,"Mon 19 Jun");
lv_obj_set_style_text_color(ui_date_placeholder, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_date_placeholder, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_battery_placeholder = lv_label_create(ui_DateBatteryPanelMain);
lv_obj_set_width( ui_battery_placeholder, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_battery_placeholder, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_battery_placeholder, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_battery_placeholder,"95%");
lv_obj_set_style_text_color(ui_battery_placeholder, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_battery_placeholder, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_passcode_control_button = lv_btn_create(ui_landing_page);
lv_obj_set_width( ui_passcode_control_button, 120);
lv_obj_set_height( ui_passcode_control_button, 40);
lv_obj_set_x( ui_passcode_control_button, -75 );
lv_obj_set_y( ui_passcode_control_button, 165 );
lv_obj_set_align( ui_passcode_control_button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_passcode_control_button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_passcode_control_button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_passcode_control_button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_passcode_control_button, lv_color_hex(0x007BFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_passcode_control_button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_passcode_control_button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_passcode_control_button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_passcode_control_label = lv_label_create(ui_passcode_control_button);
lv_obj_set_width( ui_passcode_control_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_passcode_control_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_passcode_control_label, LV_ALIGN_CENTER );
lv_label_set_text(ui_passcode_control_label,"Passcode\nControl");

ui_Unlock_button = lv_btn_create(ui_landing_page);
lv_obj_set_width( ui_Unlock_button, 120);
lv_obj_set_height( ui_Unlock_button, 40);
lv_obj_set_x( ui_Unlock_button, 75 );
lv_obj_set_y( ui_Unlock_button, 166 );
lv_obj_set_align( ui_Unlock_button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Unlock_button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Unlock_button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Unlock_button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Unlock_button, lv_color_hex(0x007BFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Unlock_button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_Unlock_button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_Unlock_button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Unlock_button_label = lv_label_create(ui_Unlock_button);
lv_obj_set_width( ui_Unlock_button_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Unlock_button_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Unlock_button_label, LV_ALIGN_CENTER );
lv_label_set_text(ui_Unlock_button_label,"Unlock Door");

ui_cam_panel = lv_obj_create(ui_landing_page);
lv_obj_set_width( ui_cam_panel, 320);
lv_obj_set_height( ui_cam_panel, 240);
lv_obj_set_x( ui_cam_panel, 0 );
lv_obj_set_y( ui_cam_panel, -60 );
lv_obj_set_align( ui_cam_panel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_cam_panel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_cam_panel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_cam_panel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_cam_panel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_cam_panel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image1 = lv_img_create(ui_cam_panel);
lv_obj_set_width( ui_Image1, 320);
lv_obj_set_height( ui_Image1, 240);
lv_obj_set_align( ui_Image1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image1, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

lv_obj_add_event_cb(ui_passcode_control_button, ui_event_passcode_control_button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Unlock_button, ui_event_Unlock_button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_landing_page, ui_event_landing_page, LV_EVENT_ALL, NULL);

}

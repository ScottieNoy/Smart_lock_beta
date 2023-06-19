// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: remote

#include "../ui.h"

void ui_remove_passcode_screen_screen_init(void)
{
ui_remove_passcode_screen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_remove_passcode_screen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_remove_passcode_screen, lv_color_hex(0x898889), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_remove_passcode_screen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_remove_passcode = lv_obj_create(ui_remove_passcode_screen);
lv_obj_set_width( ui_remove_passcode, 320);
lv_obj_set_height( ui_remove_passcode, 79);
lv_obj_set_align( ui_remove_passcode, LV_ALIGN_BOTTOM_MID );
lv_obj_clear_flag( ui_remove_passcode, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_remove_passcode, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_remove_passcode, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_remove_passcode, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_remove_passcode, lv_color_hex(0xFF4136), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_remove_passcode, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_remove_passcode, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_remove_passcode, LV_BORDER_SIDE_TOP, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_remove_passcode_go_back_button = lv_btn_create(ui_remove_passcode_screen);
lv_obj_set_width( ui_remove_passcode_go_back_button, 120);
lv_obj_set_height( ui_remove_passcode_go_back_button, 40);
lv_obj_set_x( ui_remove_passcode_go_back_button, 0 );
lv_obj_set_y( ui_remove_passcode_go_back_button, 199 );
lv_obj_set_align( ui_remove_passcode_go_back_button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_remove_passcode_go_back_button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_remove_passcode_go_back_button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_remove_passcode_go_back_button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_remove_passcode_go_back_button, lv_color_hex(0x007BFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_remove_passcode_go_back_button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_remove_passcode_go_back_button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_remove_passcode_go_back_button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_remove_passcode_go_back_button_l = lv_label_create(ui_remove_passcode_go_back_button);
lv_obj_set_width( ui_remove_passcode_go_back_button_l, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_remove_passcode_go_back_button_l, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_remove_passcode_go_back_button_l, LV_ALIGN_CENTER );
lv_label_set_text(ui_remove_passcode_go_back_button_l,"Go Back");

ui_DateBatteryPanelPassword2 = lv_obj_create(ui_remove_passcode_screen);
lv_obj_set_width( ui_DateBatteryPanelPassword2, 320);
lv_obj_set_height( ui_DateBatteryPanelPassword2, 60);
lv_obj_set_x( ui_DateBatteryPanelPassword2, 0 );
lv_obj_set_y( ui_DateBatteryPanelPassword2, -210 );
lv_obj_set_align( ui_DateBatteryPanelPassword2, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_DateBatteryPanelPassword2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_DateBatteryPanelPassword2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_DateBatteryPanelPassword2, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_DateBatteryPanelPassword2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_DateBatteryPanelPassword2, lv_color_hex(0xFF4136), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_DateBatteryPanelPassword2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_DateBatteryPanelPassword2, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_DateBatteryPanelPassword2, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_date_placeholder3 = lv_label_create(ui_DateBatteryPanelPassword2);
lv_obj_set_width( ui_date_placeholder3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_date_placeholder3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_date_placeholder3, LV_ALIGN_LEFT_MID );
lv_label_set_text(ui_date_placeholder3,"Mon 19 Jun");
lv_obj_set_style_text_color(ui_date_placeholder3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_date_placeholder3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_battery_placeholder3 = lv_label_create(ui_DateBatteryPanelPassword2);
lv_obj_set_width( ui_battery_placeholder3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_battery_placeholder3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_battery_placeholder3, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_battery_placeholder3,"95%");
lv_obj_set_style_text_color(ui_battery_placeholder3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_battery_placeholder3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_remove_passcode_keyboard = lv_keyboard_create(ui_remove_passcode_screen);
lv_keyboard_set_mode(ui_remove_passcode_keyboard,LV_KEYBOARD_MODE_NUMBER);
lv_obj_set_width( ui_remove_passcode_keyboard, 300);
lv_obj_set_height( ui_remove_passcode_keyboard, 229);
lv_obj_set_x( ui_remove_passcode_keyboard, 0 );
lv_obj_set_y( ui_remove_passcode_keyboard, -90 );
lv_obj_set_align( ui_remove_passcode_keyboard, LV_ALIGN_BOTTOM_MID );

ui_remove_passcode_text_area = lv_textarea_create(ui_remove_passcode_screen);
lv_obj_set_width( ui_remove_passcode_text_area, 283);
lv_obj_set_height( ui_remove_passcode_text_area, LV_SIZE_CONTENT);   /// 131
lv_obj_set_x( ui_remove_passcode_text_area, 0 );
lv_obj_set_y( ui_remove_passcode_text_area, -126 );
lv_obj_set_align( ui_remove_passcode_text_area, LV_ALIGN_CENTER );
lv_textarea_set_max_length(ui_remove_passcode_text_area,4);
lv_textarea_set_placeholder_text(ui_remove_passcode_text_area,"Passcode to remove");
lv_textarea_set_one_line(ui_remove_passcode_text_area,true);
lv_textarea_set_password_mode(ui_remove_passcode_text_area, true);
lv_obj_set_style_text_font(ui_remove_passcode_text_area, &lv_font_montserrat_48, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_text_align(ui_remove_passcode_text_area, LV_TEXT_ALIGN_LEFT, LV_PART_TEXTAREA_PLACEHOLDER| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_remove_passcode_text_area, &lv_font_montserrat_30, LV_PART_TEXTAREA_PLACEHOLDER| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_remove_passcode_go_back_button, ui_event_remove_passcode_go_back_button, LV_EVENT_ALL, NULL);
lv_keyboard_set_textarea(ui_remove_passcode_keyboard,ui_remove_passcode_text_area);
lv_obj_add_event_cb(ui_remove_passcode_keyboard, ui_event_remove_passcode_keyboard, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_remove_passcode_text_area, ui_event_remove_passcode_text_area, LV_EVENT_ALL, NULL);

}

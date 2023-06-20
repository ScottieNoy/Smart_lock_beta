// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: remote

#include "../ui.h"

void ui_passcode_control_screen_screen_init(void)
{
ui_passcode_control_screen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_passcode_control_screen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_passcode_control_screen, lv_color_hex(0x898889), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_passcode_control_screen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_passcode_control_label1 = lv_label_create(ui_passcode_control_screen);
lv_obj_set_width( ui_passcode_control_label1, 320);
lv_obj_set_height( ui_passcode_control_label1, 40);
lv_obj_set_x( ui_passcode_control_label1, 0 );
lv_obj_set_y( ui_passcode_control_label1, -145 );
lv_obj_set_align( ui_passcode_control_label1, LV_ALIGN_CENTER );
lv_label_set_text(ui_passcode_control_label1,"Passcode Control");
lv_obj_set_style_text_align(ui_passcode_control_label1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_passcode_control_label1, &lv_font_montserrat_30, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_go_back_button_panel = lv_obj_create(ui_passcode_control_screen);
lv_obj_set_width( ui_go_back_button_panel, 320);
lv_obj_set_height( ui_go_back_button_panel, 79);
lv_obj_set_align( ui_go_back_button_panel, LV_ALIGN_BOTTOM_MID );
lv_obj_clear_flag( ui_go_back_button_panel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_go_back_button_panel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_go_back_button_panel, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_go_back_button_panel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_go_back_button_panel, lv_color_hex(0xFF4136), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_go_back_button_panel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_go_back_button_panel, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_go_back_button_panel, LV_BORDER_SIDE_TOP, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_passcode_control_go_back_button = lv_btn_create(ui_passcode_control_screen);
lv_obj_set_width( ui_passcode_control_go_back_button, 120);
lv_obj_set_height( ui_passcode_control_go_back_button, 40);
lv_obj_set_x( ui_passcode_control_go_back_button, 0 );
lv_obj_set_y( ui_passcode_control_go_back_button, 200 );
lv_obj_set_align( ui_passcode_control_go_back_button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_passcode_control_go_back_button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_passcode_control_go_back_button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_passcode_control_go_back_button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_passcode_control_go_back_button, lv_color_hex(0x007BFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_passcode_control_go_back_button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_passcode_control_go_back_button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_passcode_control_go_back_button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_passcode_control_go_back_but_lab = lv_label_create(ui_passcode_control_go_back_button);
lv_obj_set_width( ui_passcode_control_go_back_but_lab, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_passcode_control_go_back_but_lab, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_passcode_control_go_back_but_lab, LV_ALIGN_CENTER );
lv_label_set_text(ui_passcode_control_go_back_but_lab,"Go Back");

ui_DateBatteryPanelPassword1 = lv_obj_create(ui_passcode_control_screen);
lv_obj_set_width( ui_DateBatteryPanelPassword1, 320);
lv_obj_set_height( ui_DateBatteryPanelPassword1, 60);
lv_obj_set_x( ui_DateBatteryPanelPassword1, 0 );
lv_obj_set_y( ui_DateBatteryPanelPassword1, -210 );
lv_obj_set_align( ui_DateBatteryPanelPassword1, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_DateBatteryPanelPassword1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_DateBatteryPanelPassword1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_DateBatteryPanelPassword1, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_DateBatteryPanelPassword1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_DateBatteryPanelPassword1, lv_color_hex(0xFF4136), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_DateBatteryPanelPassword1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_DateBatteryPanelPassword1, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_DateBatteryPanelPassword1, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_date_placeholder2 = lv_label_create(ui_DateBatteryPanelPassword1);
lv_obj_set_width( ui_date_placeholder2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_date_placeholder2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_date_placeholder2, LV_ALIGN_LEFT_MID );
lv_label_set_text(ui_date_placeholder2,"Mon 19 Jun");
lv_obj_set_style_text_color(ui_date_placeholder2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_date_placeholder2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_battery_placeholder2 = lv_label_create(ui_DateBatteryPanelPassword1);
lv_obj_set_width( ui_battery_placeholder2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_battery_placeholder2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_battery_placeholder2, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_battery_placeholder2,"95%");
lv_obj_set_style_text_color(ui_battery_placeholder2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_battery_placeholder2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Buttonpanel3 = lv_obj_create(ui_passcode_control_screen);
lv_obj_set_width( ui_Buttonpanel3, 320);
lv_obj_set_height( ui_Buttonpanel3, 270);
lv_obj_set_x( ui_Buttonpanel3, 0 );
lv_obj_set_y( ui_Buttonpanel3, 26 );
lv_obj_set_align( ui_Buttonpanel3, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Buttonpanel3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Buttonpanel3, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Buttonpanel3, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Buttonpanel3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_Buttonpanel3, lv_color_hex(0xFF4136), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Buttonpanel3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Buttonpanel3, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_Buttonpanel3, LV_BORDER_SIDE_TOP, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_add_passcode_button = lv_btn_create(ui_passcode_control_screen);
lv_obj_set_width( ui_add_passcode_button, 140);
lv_obj_set_height( ui_add_passcode_button, 40);
lv_obj_set_x( ui_add_passcode_button, 0 );
lv_obj_set_y( ui_add_passcode_button, -40 );
lv_obj_set_align( ui_add_passcode_button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_add_passcode_button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_add_passcode_button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_add_passcode_button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_add_passcode_button, lv_color_hex(0x007BFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_add_passcode_button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_add_passcode_button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_add_passcode_button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_add_passcode_button_label = lv_label_create(ui_add_passcode_button);
lv_obj_set_width( ui_add_passcode_button_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_add_passcode_button_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_add_passcode_button_label, LV_ALIGN_CENTER );
lv_label_set_text(ui_add_passcode_button_label,"Add passcode");

ui_remove_passcode_button = lv_btn_create(ui_passcode_control_screen);
lv_obj_set_width( ui_remove_passcode_button, 140);
lv_obj_set_height( ui_remove_passcode_button, 40);
lv_obj_set_x( ui_remove_passcode_button, 0 );
lv_obj_set_y( ui_remove_passcode_button, 70 );
lv_obj_set_align( ui_remove_passcode_button, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_remove_passcode_button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_remove_passcode_button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_remove_passcode_button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_remove_passcode_button, lv_color_hex(0x007BFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_remove_passcode_button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_remove_passcode_button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_remove_passcode_button, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_remove_passcode_button_label = lv_label_create(ui_remove_passcode_button);
lv_obj_set_width( ui_remove_passcode_button_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_remove_passcode_button_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_remove_passcode_button_label, LV_ALIGN_CENTER );
lv_label_set_text(ui_remove_passcode_button_label,"Remove passcode");

lv_obj_add_event_cb(ui_passcode_control_go_back_button, ui_event_passcode_control_go_back_button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_add_passcode_button, ui_event_add_passcode_button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_remove_passcode_button, ui_event_remove_passcode_button, LV_EVENT_ALL, NULL);

}
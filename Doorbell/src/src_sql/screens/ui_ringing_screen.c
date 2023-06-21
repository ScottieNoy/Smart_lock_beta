// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: klokke

#include "../ui.h"

void ui_ringing_screen_screen_init(void)
{
ui_ringing_screen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_ringing_screen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ringing_screen, lv_color_hex(0x313031), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ringing_screen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_ringing_screen, lv_color_hex(0x313031), LV_PART_SCROLLBAR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ringing_screen, 255, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);

ui_ringing_label = lv_label_create(ui_ringing_screen);
lv_obj_set_width( ui_ringing_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_ringing_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_ringing_label, 0 );
lv_obj_set_y( ui_ringing_label, 65 );
lv_obj_set_align( ui_ringing_label, LV_ALIGN_CENTER );
lv_label_set_text(ui_ringing_label,"Dorbell is ringing");
lv_obj_set_style_text_color(ui_ringing_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_ringing_label, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_ringing_label, &lv_font_montserrat_26, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ringing_image = lv_img_create(ui_ringing_screen);
lv_img_set_src(ui_ringing_image, &ui_img_1999303404);
lv_obj_set_width( ui_ringing_image, 100);
lv_obj_set_height( ui_ringing_image, 100);
lv_obj_set_x( ui_ringing_image, 0 );
lv_obj_set_y( ui_ringing_image, -50 );
lv_obj_set_align( ui_ringing_image, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_ringing_image, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_ringing_image, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

lv_obj_add_event_cb(ui_ringing_screen, ui_event_ringing_screen, LV_EVENT_ALL, NULL);

}

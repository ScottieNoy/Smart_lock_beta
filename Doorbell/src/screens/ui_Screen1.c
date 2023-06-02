// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: doorbell

#include "../ui.h"

void ui_Screen1_screen_init(void)
{
ui_Screen1 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Delivery1 = lv_btn_create(ui_Screen1);
lv_obj_set_width( ui_Delivery1, 100);
lv_obj_set_height( ui_Delivery1, 50);
lv_obj_set_x( ui_Delivery1, 3 );
lv_obj_set_y( ui_Delivery1, -121 );
lv_obj_set_align( ui_Delivery1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Delivery1, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Delivery1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Delivery_label = lv_label_create(ui_Delivery1);
lv_obj_set_width( ui_Delivery_label, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Delivery_label, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Delivery_label, 1 );
lv_obj_set_y( ui_Delivery_label, -2 );
lv_obj_set_align( ui_Delivery_label, LV_ALIGN_CENTER );
lv_label_set_text(ui_Delivery_label,"Delivery");

ui_Delivery2 = lv_btn_create(ui_Screen1);
lv_obj_set_width( ui_Delivery2, 100);
lv_obj_set_height( ui_Delivery2, 50);
lv_obj_set_x( ui_Delivery2, 7 );
lv_obj_set_y( ui_Delivery2, 60 );
lv_obj_set_align( ui_Delivery2, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Delivery2, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_Delivery2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Delivery_label1 = lv_label_create(ui_Delivery2);
lv_obj_set_width( ui_Delivery_label1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Delivery_label1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Delivery_label1, 1 );
lv_obj_set_y( ui_Delivery_label1, -2 );
lv_obj_set_align( ui_Delivery_label1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Delivery_label1,"Enter passcode");

lv_obj_add_event_cb(ui_Delivery1, ui_event_Delivery1, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Delivery2, ui_event_Delivery2, LV_EVENT_ALL, NULL);

}
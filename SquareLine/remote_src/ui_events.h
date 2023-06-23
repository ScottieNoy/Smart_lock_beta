// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: remote

#ifndef _UI_EVENTS_H
#define _UI_EVENTS_H

#ifdef __cplusplus
extern "C" {
#endif

void beginStream(lv_event_t * e);
void stopStream(lv_event_t * e);
void unlock(lv_event_t * e);
void addPasscode(lv_event_t * e);
void removePasscode(lv_event_t * e);
void stopNotification(lv_event_t * e);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif

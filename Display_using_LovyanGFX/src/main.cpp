#pragma GCC optimize("Ofast")
#define LGFX_USE_V1

#include <LovyanGFX.hpp>
#include <lvgl.h>
// #include <lv_demo.h>
#include <src_sql/ui.h>
#include <SD.h>
#include "lgfx_ESP32_3248S035.h"
#include <WiFi.h>
#include <HTTPClient.h>

// Built in RGB LED
#define LED_PIN_R 4
#define LED_PIN_G 16
#define LED_PIN_B 17

/*Change to your screen resolution*/
static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 480;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[2][ screenWidth * 10 ];

LGFX gfx;


/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
    if (gfx.getStartCount() == 0)
    {   // Processing if not yet started
        gfx.startWrite();
    }
    gfx.pushImageDMA( area->x1
                    , area->y1
                    , area->x2 - area->x1 + 1
                    , area->y2 - area->y1 + 1
                    , ( lgfx::swap565_t* )&color_p->full);
    lv_disp_flush_ready( disp );
}

void sd_access_sample( void )
{
    if (gfx.getStartCount() > 0)
    {   // Free the bus before accessing the SD card
        gfx.endWrite();
    }

    // Something to manipulate the SD card.
    auto file = SD.open("/file");
    file.close();
}
// A buffer for the JPEG image data
uint8_t *jpegData = NULL;
size_t jpegDataLen = 0;

HTTPClient http;
const char* streamUrl = "http://192.168.1.80/snapshot";

int xPos = 0;
int yPos = 120;

void showingImage() {
  http.begin(streamUrl);
  int httpCode = http.GET();
  if(httpCode > 0) {
    if(httpCode == HTTP_CODE_OK) {
      // Free previous image data if it exists
      if(jpegData != NULL) {
          free(jpegData);
          jpegData = NULL;
      }
      // Get the JPEG data
      jpegDataLen = http.getSize();
      jpegData = (uint8_t*) malloc(jpegDataLen);
      if(jpegData == NULL) {
          Serial.println("Failed to allocate memory for JPEG data");
          return;
      }
      WiFiClient * stream = http.getStreamPtr();
      stream->readBytes(jpegData, jpegDataLen);
      uint32_t t = millis();
      
      gfx.drawJpg(jpegData, jpegDataLen, xPos, yPos,480,320);
      
      t = millis() - t;
      Serial.print(t); Serial.println(" ms");
    }
  }
  else {
    Serial.printf("HTTP GET failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
}

/*Read the touchpad*/
void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data )
{
    uint16_t touchX, touchY;

    data->state = LV_INDEV_STATE_REL;

    if( gfx.getTouch( &touchX, &touchY ) )
    {
        data->state = LV_INDEV_STATE_PR;

        /*Set the coordinates*/
        data->point.x = touchX;
        data->point.y = touchY;
    }
}

void setup()
{
    Serial.begin(115200);
    gfx.begin();

    WiFi.begin("TheilvigNet-2.4G", "plantagen");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    lv_init();
    lv_disp_draw_buf_init( &draw_buf, buf[0], buf[1], screenWidth * 10 );

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register( &disp_drv );

    /*Initialize the input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init( &indev_drv );
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register( &indev_drv );

    // Setup the LED
    pinMode(LED_PIN_R, OUTPUT);
    pinMode(LED_PIN_G, OUTPUT);
    pinMode(LED_PIN_B, OUTPUT);
    digitalWrite(LED_PIN_R, LOW); // Turn off Red LED
    digitalWrite(LED_PIN_G, LOW); // Turn off Green LED
    digitalWrite(LED_PIN_B, LOW); // Turn off Blue LED

    ui_init();
    //lv_demo_benchmark();

}

void loop()
{
    showingImage();
    lv_timer_handler(); /* let the GUI do its work */
    delay(10);
}
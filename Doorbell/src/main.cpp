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
#include <time.h>

#define INDICATOR_TIME 10000

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;   // Set your GMT offset in seconds
const int   daylightOffset_sec = 3600;  // If daylight saving time is in effect

char date[20];  // Buffer to hold the formatted date

void getFormattedDate()
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  strftime(date, sizeof(date), "%a %d %B", &timeinfo); // Format the date
}

// Built in RGB LED
#define LED_PIN_R 4
#define LED_PIN_G 16
#define LED_PIN_B 17
#define BUTTON_PIN 22
#define BLITZ_PIN 21
#define DEBOUNCE_TIME 50

// Variables will change:
int lastSteadyState = LOW;       // the previous steady state from the input pin
int lastFlickerableState = LOW;  // the previous flickerable state from the input pin
int currentState;                // the current reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled

/*Change to your screen resolution*/
static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 480;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[2][ screenWidth * 10 ];

LGFX gfx;
bool showImage = false;
bool sendPasscode = false;
char * passcode;
bool taskCreated = false;
bool accessGranted = false;
bool sendNotification = false;
bool blitzOn = false;
bool displayOn = true;
int timer;


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
const char* streamUrl = "http://172.20.10.13/snapshot";

HTTPClient http2;

const char* unlockUrl = "http://172.20.10.6/try-passcode";
const char* notificationUrl = "http://172.20.10.6/ring-notification-post";

int xPos = 0;
int yPos = 60;

void showingImage(void * pvParameters) {
    http.begin(streamUrl);
    for(;;) {
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
        vTaskDelay(10 / portTICK_PERIOD_MS);

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

    WiFi.begin("Oscar", "oscar12345");
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
    pinMode(BLITZ_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    digitalWrite(LED_PIN_R, HIGH); // Turn off Red LED
    digitalWrite(LED_PIN_G, HIGH); // Turn off Green LED
    digitalWrite(LED_PIN_B, HIGH); // Turn off Blue LED
    digitalWrite(BLITZ_PIN, LOW); // Turn off Blitz
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    getFormattedDate();

    ui_init();

    //lv_demo_benchmark();

}

TaskHandle_t Task1;


void loop()
{
    if(lv_disp_get_inactive_time(NULL) > 10000 && displayOn) {
        gfx.sleep();
        displayOn = false;
        showImage = false;
    }
    if(lv_disp_get_inactive_time(NULL) < 10000 && !displayOn) {
        gfx.wakeup();
        displayOn = true;
        if(lv_obj_get_screen(lv_scr_act()) == ui_landing_page) {
            showImage = true;
        }
    }
    if(showImage && !blitzOn) {
        Serial.println("Turning on Blitz");
        digitalWrite(BLITZ_PIN, HIGH);
        blitzOn = true;
    }
    if(!showImage && blitzOn) {
        Serial.println("Turning off Blitz");
        digitalWrite(BLITZ_PIN, LOW);
        blitzOn = false;
    }

    currentState = digitalRead(BUTTON_PIN);
    // If the switch/button changed, due to noise or pressing:
    if (currentState != lastFlickerableState) {
        // reset the debouncing timer
        lastDebounceTime = millis();
        // save the the last flickerable state
        lastFlickerableState = currentState;
    }
    if ((millis() - lastDebounceTime) > DEBOUNCE_TIME) {
        // whatever the reading is at, it's been there for longer than the debounce
        // delay, so take it as the actual current state:

        // if the button state has changed:
        if(lastSteadyState == HIGH && currentState == LOW){
            http2.begin(notificationUrl);
            http2.addHeader("Content-Type", "application/x-www-form-urlencoded");  //Specify content-type header
            int httpCode2 = http2.POST("ring=true");
            if(httpCode2 > 0) {
                if(httpCode2 == HTTP_CODE_OK) {
                    timer = millis();
                    digitalWrite(LED_PIN_B, LOW); // Turn on Blue LED
                    lv_disp_trig_activity(NULL);
                    _ui_screen_change( ui_ringing_screen, LV_SCR_LOAD_ANIM_NONE, 500, 0);
                }
                
            }
            else {
                Serial.printf("HTTP POST failed, error: %s\n", http2.errorToString(httpCode2).c_str());
                _ui_screen_change( ui_not_ringing_screen, LV_SCR_LOAD_ANIM_NONE, 500, 0);
            }
            
            lastSteadyState = currentState;
            http2.end();
        }

        // save the the last steady state
        lastSteadyState = currentState;
    }
    if(millis() - timer > INDICATOR_TIME) {
        digitalWrite(LED_PIN_R, HIGH); // Turn off Red LED
        digitalWrite(LED_PIN_G, HIGH); // Turn off Green LED
        digitalWrite(LED_PIN_B, HIGH); // Turn off Blue LED
    }
    if(showImage && !taskCreated) {
        taskCreated = true;
        Task1 = new TaskHandle_t;
        xTaskCreatePinnedToCore(showingImage, "showingImage", 10000, NULL, 1, &Task1, 0);
    } else if(!showImage && taskCreated) {
        taskCreated = false;
        vTaskDelete(Task1);
    }
    if(sendPasscode) {
        http2.begin(unlockUrl);
        http2.addHeader("Content-Type", "application/x-www-form-urlencoded");  //Specify content-type header
        int httpCode2 = http2.POST("passcode="+(String)passcode);
        if(httpCode2 == HTTP_CODE_OK) {
                accessGranted = true;
                timer = millis();
                digitalWrite(LED_PIN_G, LOW); // Turn on Green LED
        } else {
            accessGranted = false;
            timer = millis();
            digitalWrite(LED_PIN_R, LOW); // Turn on Red LED
        }
        lv_textarea_set_text(ui_passwordArea, "");
        http2.end();

        
    }
    lv_timer_handler(); /* let the GUI do its work */
    delay(10);
}
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

#define NOTIFICATION_TIME 10000
#define UNLOCK_TIME 10000

// Built in RGB LED
#define LED_PIN_R 4
#define LED_PIN_G 16
#define LED_PIN_B 17
#define BUZZER_PIN 3

/*Change to your screen resolution*/
static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 480;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[2][ screenWidth * 10 ];

LGFX gfx;
bool showImage = false;
bool addPasscodeBool = false;
bool removePasscodeBool = false;
char * passcode;
bool taskCreated = false;
bool unlockBool = false;
int notificationTimer;
int unlockTimer;

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
const char* addPasscodeUrl = "http://172.20.10.6/new-passcode";
const char* removePasscodeUrl = "http://172.20.10.6/remove-passcode";
const char* unlockUrl = "http://172.20.10.6/unlock-notification";
const char* notificationUrl = "http://172.20.10.6/ring-notification-get";

int xPos = 0;
int yPos = 60;

void showingImage(void * pvParameters) {
    for(;;) {
        http.begin(notificationUrl);
        int httpNotificationCode = http.GET();
        if(httpNotificationCode > 0) {
            if(httpNotificationCode == HTTP_CODE_OK) {
                Serial.println("Notification");
                notificationTimer = millis();
                digitalWrite(BUZZER_PIN, HIGH); 
            }      
        }
        http.end();
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
                
                // Check for memory allocation failure
                if(jpegData == NULL) {
                    Serial.println("Failed to allocate memory for JPEG data");
                    http.end();
                    continue;
                }
                WiFiClient * stream = http.getStreamPtr();
                stream->setTimeout(500);
                stream->readBytes(jpegData, jpegDataLen);
                uint32_t t = millis();
                
                gfx.drawJpg(jpegData, jpegDataLen, xPos, yPos,480,320);
                
                t = millis() - t;
                Serial.print(t); Serial.println(" ms");
            } else {
                Serial.printf("HTTP GET failed, error: %s\n", http.errorToString(httpCode).c_str());
            }
        } else {
            Serial.printf("HTTP GET returned negative or zero response code, error: %s\n", http.errorToString(httpCode).c_str());
        }
        http.end();
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
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(LED_PIN_R, HIGH); // Turn off Red LED
    digitalWrite(LED_PIN_G, HIGH); // Turn off Green LED
    digitalWrite(LED_PIN_B, HIGH); // Turn off Blue LED
    digitalWrite(BUZZER_PIN, LOW); // Turn off Buzzer
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    getFormattedDate();
    ui_init();


}

TaskHandle_t Task1;


void loop()
{
    if(millis()-unlockTimer > UNLOCK_TIME) {
        digitalWrite(LED_PIN_G, HIGH); // Turn off Green LED
        digitalWrite(LED_PIN_R, HIGH); // Turn off Red LED
    }
    if(millis()-notificationTimer > NOTIFICATION_TIME) {
        digitalWrite(BUZZER_PIN, LOW);
    }
    getFormattedDate();
    if(millis()-notificationTimer > NOTIFICATION_TIME) {
        digitalWrite(BUZZER_PIN, LOW);
    }
    
    if( unlockBool ) {
        Serial.println("Unlocking door");
        http2.begin(unlockUrl);
        http2.addHeader("Content-Type", "application/x-www-form-urlencoded");  //Specify content-type header
        int httpReturnCode = http2.POST("unlock=true");   //Send the request
        if(httpReturnCode == HTTP_CODE_OK) {
            unlockTimer = millis();
            digitalWrite(LED_PIN_G, LOW); // Turn on Green LED
        } else {
            digitalWrite(LED_PIN_R, LOW); // Turn on Red LED
        }
        unlockBool = false;
        http2.end();
    }
    if(showImage && !taskCreated) {
        taskCreated = true;
        Task1 = new TaskHandle_t;
        xTaskCreatePinnedToCore(showingImage, "showingImage", 10000, NULL, 1, &Task1, 0);
    } else if(!showImage && taskCreated) {
        taskCreated = false;
        vTaskDelete(Task1);
    }
    if(addPasscodeBool) {
        Serial.println("Adding code");
        http2.begin(addPasscodeUrl);
        http2.addHeader("Content-Type", "application/x-www-form-urlencoded");  //Specify content-type header
        int httpReturnCode = http2.POST("passcode=" + (String)passcode);   //Send the request
        if (httpReturnCode == HTTP_CODE_OK) {
            Serial.print("Passcode added: ");
            Serial.println(passcode);
        } else {
            Serial.println("Error on sending POST: " + httpReturnCode);
        }
        lv_textarea_set_text(ui_add_passcode_text_area, "");
        addPasscodeBool = false;
        http2.end();  //Close connection

    }
    if(removePasscodeBool) {
        Serial.println("Removing passcode");
        http2.begin(removePasscodeUrl);
        http2.addHeader("Content-Type", "application/x-www-form-urlencoded");  //Specify content-type header
        int httpReturnCode = http2.POST("passcode=" + (String)passcode);   //Send the request
        if (httpReturnCode == HTTP_CODE_OK) {
            Serial.print("Passcode removed: ");
            Serial.println(passcode);
        } else {
            Serial.println("Error on sending POST: " + httpReturnCode);
        }
        lv_textarea_set_text(ui_remove_passcode_text_area, "");
        removePasscodeBool = false;
        http2.end();  //Close connection

    }
    lv_timer_handler(); /* let the GUI do its work */
    delay(10);
}
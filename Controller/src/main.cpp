// ===================== Include Libraries ========================= //
#include <Arduino.h>
#include "ConnectWiFi.h"
#include <PubSubClient.h>
#include "ESPServer.h"

// ===================== Pin Definitions =========================== //

int unlockPin = 3;                                                   // Unlock Pin

// ===================== Variable Definitions ====================== //

bool isLocked = false;                                               // Is the door locked?

// ===================== WiFi Definitions ========================== //

const char* ssid = "Oscar";                                                // WiFi Name
const char* password = "oscar12345";                                       // WiFi Password

// =================== JPEG-Steam Definitions ====================== //

char* adminServer = "http://172.20.10.13";
char* streamServer = "http://172.20.10.13/stream";
char* snapshotServer = "http://172.20.10.13/snapshot";

// const char* intensityOfFlashServer = "http://192.168.1.80/flash?v=0"; // 0-255

// ====================== Global Objects =========================== //

ConnectWiFi wifi;                                                    // WiFi Object
ESPServer server(80);                                                // Web Server Object


// ===================== Function Definitions ====================== //



// ===================== Setup and Loop ============================ //

void setup() {                                                       // Setup
  Serial.begin(115200);                                              // Start Serial Monitor
  wifi.connect(ssid, password);                                      // Connect to WiFi
  server.begin(streamServer, snapshotServer, adminServer, &unlockPin);           // Start Web Server

  }

void loop() {                                                        // Loop
  if(!wifi.isConnected()) {                                          // If not connected to WiFi
    wifi.connect(ssid, password);                                    // Connect to WiFi
  } 

}
// ===================== End of File =============================== //

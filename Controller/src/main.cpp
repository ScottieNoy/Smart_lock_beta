// ===================== Include Libraries ========================= //
#include <Arduino.h>
#include "ConnectWiFi.h"
#include <PubSubClient.h>
#include "ESPServer.h"

// ===================== Pin Definitions =========================== //

int lockPin = 2;                                                     // Lock Pin
int unlockPin = 3;                                                   // Unlock Pin

// ===================== Variable Definitions ====================== //

bool isLocked = false;                                               // Is the door locked?

// ===================== WiFi Definitions ========================== //

char* ssid = "TheilvigNet-2.4G";                                     // WiFi Name
char* password = "plantagen";                                        // WiFi Password

// =================== JPEG-Steam Definitions ====================== //

char* streamServer = "http://192.168.1.80/stream";
char* snapshotServer = "http://192.168.1.80/snapshot";

// const char* intensityOfFlashServer = "http://192.168.1.80/flash?v=0"; // 0-255

// ===================== MQTT Definitions ========================== //

// const char* mqttServer = "your_mqtt_server";
// const int mqttPort = 1883;
// const char* mqttUsername = "your_mqtt_username";
// const char* mqttPassword = "your_mqtt_password";
// const char* mqttTopic = "lock_topic";

// ====================== Global Objects =========================== //

ConnectWiFi wifi;                                                    // WiFi Object
ESPServer server(80);                  // Web Server Object
// PubSubClient mqttClient(wifi);                                    // MQTT Client Object

// ===================== Function Definitions ====================== //

// void mqttCallback(char* topic, byte* payload, unsigned int length) {
//   String message = "";
//   for (int i = 0; i < length; i++) {
//     message += (char)payload[i];
//   }
  
//   // Convert the received message to boolean
//   bool newLockState = (message == "true");
  
//   // Update the lock state
//   isLocked = newLockState;
  
//   // Print the received message and lock state
//   Serial.print("Received message: ");
//   Serial.println(message);
//   Serial.print("Lock state: ");
//   Serial.println(isLocked ? "Locked" : "Unlocked");
// }

// ===================== Setup and Loop ============================ //

void setup() {                                                       // Setup
  Serial.begin(115200);                                              // Start Serial Monitor
  wifi.connect(ssid, password);                                      // Connect to WiFi
  server.begin(streamServer, snapshotServer);                        // Start Web Server

  // mqttClient.setServer(mqttServer, mqttPort);                        // Set MQTT Server
  // mqttClient.setCallback(mqttCallback);                              // Set MQTT Callback

  // while (!mqttClient.connected()) {                                  // Connect to MQTT broker
  //   if (mqttClient.connect("ESP32Client", mqttUsername, mqttPassword)) {
  //     Serial.println("Connected to MQTT broker");
  //     mqttClient.subscribe(mqttTopic);
  //   } else {
  //     Serial.print("MQTT connection failed, retrying...");
  //     delay(5000);
  //   }
  // }

  }

void loop() {                                                        // Loop
  if(!wifi.isConnected()) {                                          // If not connected to WiFi
    wifi.connect(ssid, password);                                    // Connect to WiFi
  } 

  // if (!mqttClient.connected()) {                                     // If not connected to MQTT broker
  //   Serial.println("Reconnecting to MQTT broker...");                // Reconnect to MQTT broker
  //   if (mqttClient.connect("ESP32Client", mqttUsername, mqttPassword)) { 
  //     Serial.println("Connected to MQTT broker");                    // Print connection success
  //     mqttClient.subscribe(mqttTopic);                               // Subscribe to MQTT topic
  //   }
  // }
  // mqttClient.loop();                                                 // Check for MQTT messages
  
}
// ===================== End of File =============================== //

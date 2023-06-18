// This is to make sure we don't declare the function more than once by including the header multiple times:
#ifndef ESPSERVER_H   
#define ESPSERVER_H

// Liberies included:
#include <ESPAsyncWebServer.h>
#include <WiFiUdp.h>
//#include <NTPClient.h>
#include <SPIFFS.h>

#define BUTTONTIMEOUT 15000             // defining the timeout for the button to be pressed in milliseconds (ms) (15 seconds)

class ESPServer {                       // This is the ESPServer class.
public:                                 // It has two public functions:
  ESPServer(int port);                  // The constructor
  void begin(char* streamServer, char* snapshotServer); // The begin function
  
  
  
private:                                // It has three private fields:
  AsyncWebServer *_server;              // A pointer to an AsyncWebServer object
  char* streamServer;                   // A pointer to a char array
  char* snapshotServer;                 // A pointer to a char array
};

#endif // ESPSERVER_H                   // This is to make sure we don't declare the function more than once by including the header multiple times.

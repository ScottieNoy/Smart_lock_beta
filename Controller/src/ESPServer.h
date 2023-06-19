// This is to make sure we don't declare the function more than once by including the header multiple times:
#ifndef ESPSERVER_H   
#define ESPSERVER_H

// Libraries included:
#include <ESPAsyncWebServer.h>
#include <WiFiUdp.h>
#include <SPIFFS.h>
#include <vector>

#define MAX_PASSCODES 100                // defining the maximum number of passcodes

#define BUTTONTIMEOUT 15000             // defining the timeout for the button to be pressed in milliseconds (ms) (15 seconds)

class ESPServer {                       // This is the ESPServer class.
public:                                 // It has two public functions:
  ESPServer(int port);                  // The constructor
  void begin(const char* streamServer, const char* snapshotServer, const char* adminServer); // The begin function
  void addPasscode(String passcode);    // The addPasscode function
  void removePasscode(String passcode); // The removePasscode function
  bool isPasscodeCorrect(String passcode);    // The isPasscodeCorrect function
  
private:                                // It has three private fields:
  AsyncWebServer *_server;              // A pointer to an AsyncWebServer object
  const char* streamServer;                   // A pointer to a char array
  const char* snapshotServer;                 // A pointer to a char array
  const char* adminServer;                    // A pointer to a char array
  // adding passcodes char array
  String _passcodes[MAX_PASSCODES];   // A pointer to a char array
};

#endif // ESPSERVER_H                   // This is to make sure we don't declare the function more than once by including the header multiple times

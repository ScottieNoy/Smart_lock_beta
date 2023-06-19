// This is to make sure we don't declare the function more than once by including the header multiple times:
#ifndef CONNECTWIFI_H
#define CONNECTWIFI_H

#include <WiFi.h>
#include <Arduino.h>

class ConnectWiFi {

public:
  void connect(const char* ssid, const char* password);
  bool isConnected();
  String getIP();
  String IpAddress2String(const IPAddress& ipAddress);


private:
  const char* ssid;
  const char* password;

};
#endif // CONNECTWIFI_H

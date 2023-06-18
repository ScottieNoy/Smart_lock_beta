// Liberies included:
#include "ESPServer.h"


// This is the constructor for the ESPServer class.
// It takes a port number.
// It creates a new AsyncWebServer object and stores it in the _server field.

// This constructor is defined in src/ESPServer.cpp
// This constructor is declared in src/ESPServer.h
// This constructor is called in src/main.cpp

ESPServer::ESPServer(int port)                                                      // Constructor
  : _server(new AsyncWebServer(port)) {                                             // Initializer list
}

void ESPServer::begin(char* streamServer, char* snapshotServer) {                    // This is the begin function.
  
        String streamServerString = streamServer;
        String snapshotServerString = snapshotServer;
        String snapshotPath = "/snapshot";

        String html = "<!DOCTYPE html>";
        html += "<html>";
        html += "<head>";
        html += "<title>ESP32 Stream Server</title>";
        html += "<style>";
        html += "body { text-align: center; padding: 20px; background-color: #282c34; color: #61dafb; font-family: Arial, sans-serif; }";
        html += "h1 { font-size: 2em; }";
        html += "img { border-radius: 15px; }";
        html += "button { padding: 10px 20px; font-size: 1em; border-radius: 5px; color: #282c34; background-color: #61dafb; border: none; cursor: pointer; transition: background-color 0.3s; }";
        html += "button:hover { background-color: #bbe1fa; }";
        html += "</style>";
        html += "</head>";
        html += "<body>";
        html += "<h1>ESP32 Stream</h1>";
        html += "<img id='stream' src='" + streamServerString + "' alt='Stream not available' style='width:80%; max-width:600px; margin: 20px auto; display: block;'>";
        html += "<button id='snapshot'>Download Snapshot</button>";
        html += "<p>Click the above button to capture a snapshot from the stream.</p>";
        html += "<script>";
        html += "document.getElementById('snapshot').onclick = function () {";
        html += "window.location.href = '" + snapshotPath + "';";
        html += "}";
        html += "</script>";
        html += "</body>";
        html += "</html>";

        // The snapshot page with a 'Go Back' button
        String snapshotPage = "<!DOCTYPE html>";
        snapshotPage += "<html>";
        snapshotPage += "<head>";
        snapshotPage += "<title>Snapshot</title>";
        snapshotPage += "<style>";
        snapshotPage += "body { text-align: center; padding: 20px; background-color: #282c34; color: #61dafb; font-family: Arial, sans-serif; }";
        snapshotPage += "h1 { font-size: 2em; }";
        snapshotPage += "img { border-radius: 15px; }";
        snapshotPage += "button { padding: 10px 20px; font-size: 1em; border-radius: 5px; color: #282c34; background-color: #61dafb; border: none; cursor: pointer; transition: background-color 0.3s; }";
        snapshotPage += "button:hover { background-color: #bbe1fa; }";
        snapshotPage += "</style>";
        snapshotPage += "</head>";
        snapshotPage += "<body>";
        snapshotPage += "<h1>ESP32 Snapshot</h1>";
        snapshotPage += "<img id='snapshot' src='" + snapshotServerString + "' alt='Snapshot not available' style='width:80%; max-width:600px; margin: 20px auto; display: block;'>";
        snapshotPage += "<button id='goBack'>Go Back</button>";
        snapshotPage += "<p>Click the above button to go back to the live stream.</p>";
        snapshotPage += "<script>";
        snapshotPage += "document.getElementById('goBack').onclick = function () {";
        snapshotPage += "window.location.href = '/';"; // This goes back to the root URL
        snapshotPage += "}";
        snapshotPage += "</script>";
        snapshotPage += "</body>";
        snapshotPage += "</html>";




    _server->on("/", HTTP_GET, [html](AsyncWebServerRequest *request) {     // This is the route for the root path.
        request->send(200, "text/html", html);                              // It sends the HTML to the client.
        // Serial.println("Someone visited the main");                      // And it prints a message to the serial monitor. (used for debugging)
    });

     _server->on("/snapshot", HTTP_GET, [snapshotPage](AsyncWebServerRequest *request) {
      request->send(200, "text/html", snapshotPage);
    });

  _server->begin();                                                         // This starts the web server.
}
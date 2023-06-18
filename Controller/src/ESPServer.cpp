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

void ESPServer::begin(char* streamServer, char* snapshotServer, char* adminServer) {                    // This is the begin function.
  
        String streamServerString = streamServer;
        String snapshotServerString = snapshotServer;
        String adminServerString = adminServer;
        String snapshotPath = "/snapshot";

        String html = "<!DOCTYPE html>";
        html += "<html>";
        html += "<head>";
        html += "<title>My Lock Web Server</title>";
        html += "<style>";
        html += "body { font-family: Arial, sans-serif; text-align: center; padding: 20px; background-color: #333; color: #fff; }";
        html += ".blue-button { padding: 10px 20px; font-size: 16px; border-radius: 5px; background-color: #007BFF; color: #fff; border: none; margin-top: 30px; }";
        html += ".red-button { padding: 10px 20px; font-size: 16px; border-radius: 5px; background-color: #FF4136; color: #fff; border: none; margin-top: 30px; }"; // Red button
        html += ".loader { border: 16px solid #f3f3f3; border-top: 16px solid #3498db; border-radius: 50%; width: 70px; height: 70px; animation: spin 2s linear infinite; margin: 30px auto; }"; // Smaller loader with more margin
        html += "@keyframes spin { 0% { transform: rotate(0deg); } 100% { transform: rotate(360deg); } }";
        html += "</style>";
        html += "</head>";
        html += "<body>";
        html += "<h1>ESP32 Stream</h1>";
        html += "<div id='loader' class='loader'></div>"; // Add loader div
        html += "<img id='stream' src='" + streamServerString + "' onload='document.getElementById(\"loader\").style.display=\"none\"; this.style.display=\"block\";' alt='Stream not available' style='width:80%; max-width:600px; margin: 20px auto; display: none;'>";
        html += "<button class='blue-button' id='snapshot'>Download Snapshot</button>";
        html += "<p>Click the above button to download a snapshot.</p>";
        html += "<button class='red-button' id='admin'>Admin Page</button>"; // New 'Admin Page' button
        html += "<p>Click the above button to navigate to the admin page.</p>";
        html += "<script>";
        html += "document.getElementById('snapshot').onclick = function () {";
        html += "window.location.assign('" + snapshotPath + "');";
        html += "};";
        html += "document.getElementById('admin').onclick = function () {"; // New event for 'Admin Page' button
        html += "window.location.assign('" + adminServerString + "');";
        html += "};";
        html += "</script>";
        html += "</body>";
        html += "</html>";

        // The snapshot page with a 'Go Back' button
        String snapshotPage = "<!DOCTYPE html>";
        snapshotPage += "<html>";
        snapshotPage += "<head>";
        snapshotPage += "<title>Snapshot</title>";
        snapshotPage += "<style>";
        snapshotPage += "body { font-family: Arial, sans-serif; text-align: center; padding: 20px; background-color: #333; color: #fff; }";
        snapshotPage += ".blue-button { padding: 10px 20px; font-size: 16px; border-radius: 5px; background-color: #007BFF; color: #fff; border: none; margin-top: 30px; }"; // Update button class to blue-button
        snapshotPage += ".loader { border: 16px solid #f3f3f3; border-top: 16px solid #3498db; border-radius: 50%; width: 70px; height: 70px; animation: spin 2s linear infinite; margin: 30px auto; }"; // Smaller loader with more margin
        snapshotPage += "@keyframes spin { 0% { transform: rotate(0deg); } 100% { transform: rotate(360deg); } }";
        snapshotPage += "</style>";
        snapshotPage += "</head>";
        snapshotPage += "<body>";
        snapshotPage += "<h1>ESP32 Snapshot</h1>";
        snapshotPage += "<div id='loader' class='loader'></div>"; // Add loader div
        snapshotPage += "<img id='snapshot' src='" + snapshotServerString + "' onload='document.getElementById(\"loader\").style.display=\"none\"; this.style.display=\"block\";' alt='Snapshot not available' style='width:80%; max-width:600px; margin: 20px auto; display: none;'>";
        snapshotPage += "<button class='blue-button' id='goBack'>Go Back</button>"; // Update button id to 'goBack' and class to 'blue-button'
        snapshotPage += "<p>Click the above button to go back to the stream.</p>";
        snapshotPage += "<script>";
        snapshotPage += "document.getElementById('goBack').onclick = function () {";
        snapshotPage += "window.location.assign('/');"; // This goes back to the root URL
        snapshotPage += "};";
        snapshotPage += "</script>";
        snapshotPage += "</body>";
        snapshotPage += "</html>";

        _server->on("/", HTTP_GET, [html](AsyncWebServerRequest *request) {     // This is the route for the root path.
            request->send(200, "text/html", html.c_str());                              // It sends the HTML to the client.
        });

        _server->on("/snapshot", HTTP_GET, [snapshotPage](AsyncWebServerRequest *request) {
          request->send(200, "text/html", snapshotPage.c_str());
        });

  _server->begin();                                                         // This starts the web server.
}
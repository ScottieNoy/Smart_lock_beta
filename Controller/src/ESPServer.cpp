// Liberies included:
#include "ESPServer.h"

// This is the constructor for the ESPServer class.
// It takes a port number.
// It creates a new AsyncWebServer object and stores it in the _server field.

extern int unlockTimer; // Unlock Timer

// This constructor is defined in src/ESPServer.cpp
// This constructor is declared in src/ESPServer.h
// This constructor is called in src/main.cpp

ESPServer::ESPServer(int port)                                                      // Constructor
  : _server(new AsyncWebServer(port)), _passcodes({}) {                              // Initializer list
}

void ESPServer::begin(const char* streamServer, const char* snapshotServer, const char* adminServer, int *unlockPin) {
  pinMode(*unlockPin, OUTPUT); // Set the mode of the unlockPin
  
        String streamServerString = streamServer;
        String snapshotServerString = snapshotServer;
        String adminServerString = adminServer;
        String snapshotPath = "/snapshot";

        String html = "<!DOCTYPE html>";
        html += "<html>";
        html += "<head>";
        html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"; 
        html += "<title>My Lock Web Server</title>";
        html += "<link href='https://fonts.googleapis.com/icon?family=Material+Icons' rel='stylesheet'>"; // Link to Google Material Icons
        html += "<style>";
        html += "@media (max-width: 600px) { body { font-size: 18px; } }"; 
        html += "body { font-family: Arial, sans-serif; text-align: center; padding: 20px; background-color: #333; color: #fff; }";
        html += ".blue-button, .red-button { padding: 12px 24px; font-size: 24px; border-radius: 5px; color: #fff; border: none; margin-top: 30px; display: block; width: 100%; }"; 
        html += ".blue-button { background-color: #007BFF; }";
        html += ".red-button { background-color: #FF4136; }";
        html += ".loader { border: 16px solid #f3f3f3; border-top: 16px solid #3498db; border-radius: 50%; width: 70px; height: 70px; animation: spin 2s linear infinite; margin: 30px auto; }";
        html += ".modal { display: none; position: fixed; z-index: 1; left: 0; top: 0; width: 100%; height: 100%; padding: 0px; background-color: rgba(255, 255, 255, 0.9); overflow-y: auto; }"; // Adjusted width and height, added overflow-y for scrolling if necessary
        html += ".modal-content { background-color: transparent; text-align: center; margin: 0 auto; max-width: 400px; width:95%; padding: 20px; display: flex; flex-direction: column; justify-content: center; align-items: center; color: #000; }"; // Adjusted max-width and padding
        html += ".close { color: #aaaaaa; font-size: 28px; font-weight: bold; position: absolute; top: 20px; right: 30px; }"; // Position the close button at top right
        html += "h2 { font-size: 1.5em; }";  // Maintain h2 font-size
        html += "@keyframes spin { 0% { transform: rotate(0deg); } 100% { transform: rotate(360deg); } }";
        html += "</style>";
        html += "</head>";
        html += "<body>";
        html += "<div id='myModal' class='modal'>";
        html += "<div class='modal-content'>";
        html += "<h2 id='modalText'>Someone is ringing on the door</h2>"; // Added an h2 tag for larger text
        html += "<button class='blue-button' id='unlockModal'>Unlock Door</button>"; // Added an Unlock button
        html += "<span class='close'>&times;</span>";
        html += "</div>";
        html += "</div>";
        html += "<h1>DoorCam Live</h1>";
        html += "<div id='loader' class='loader'></div>";
        html += "<img id='stream' src='" + streamServerString + "' onload='document.getElementById(\"loader\").style.display=\"none\"; this.style.display=\"block\";' alt='Stream not available' style='width:100%; margin: 20px auto; display: none;'>"; 
        html += "<button class='blue-button' id='unlock'><i class='material-icons'>lock_open</i>Unlock Door</button>";
        html += "<div id='unlockStatus' style='margin-top: 10px;'></div>";
        html += "<h2>Manage Passcode</h2>";
        html += "<label for='passcodeInput'>Enter a 4-digit passcode:</label>";
        html += "<input type='text' inputmode='numeric' id='passcodeInput' min='0' max='9999' maxlength='4' placeholder='1234' style='width: 90%; padding: 10px; font-size: 20px; border: 2px solid #007BFF; border-radius: 5px; background-color: #f3f3f3;'>"; 
        html += "<div id='addPasscodeStatus' style='margin-top: 10px;'></div>";
        html += "<div id='removePasscodeStatus' style='margin-top: 10px;'></div>";
        html += "<button class='blue-button' id='addPasscode'><i class='material-icons'>add_circle</i>Add Passcode</button>";
        html += "<button class='red-button' id='removePasscode'><i class='material-icons'>remove_circle</i>Remove Passcode</button>";
        html += "<h2>Other Actions</h2>";
        html += "<button class='blue-button' id='snapshot'><i class='material-icons'>download</i>Download Current Image</button>";
        html += "<button class='red-button' id='admin'><i class='material-icons'>settings</i>Camera Page</button>";
        html += "<script>";
        html += "document.getElementById('snapshot').onclick = function () {";
        html += "window.location.assign('" + snapshotPath + "');";
        html += "};";
        html += "document.getElementById('unlock').onclick = function () {";
        html += "fetch('/unlock-notification', { method: 'POST', headers: { 'Content-Type': 'application/x-www-form-urlencoded' }, body: 'unlock=true' });";
        html += "};";
        html += "document.getElementById('admin').onclick = function () {";
        html += "window.location.assign('" + adminServerString + "');";
        html += "};";
        html += "document.getElementById('addPasscode').onclick = function () {";
        html += "let passcode = document.getElementById('passcodeInput').value;";
        html += "if(passcode.length === 4) { fetch('/new-passcode', { method: 'POST', headers: { 'Content-Type': 'application/x-www-form-urlencoded' }, body: 'passcode=' + passcode }); } else { alert('Please enter a 4-digit passcode.'); }"; // Check if the input is 4 digits
        html += "};";
        html += "document.getElementById('removePasscode').onclick = function () {";
        html += "let passcode = document.getElementById('passcodeInput').value;";
        html += "if(passcode.length === 4) { fetch('/remove-passcode', { method: 'POST', headers: { 'Content-Type': 'application/x-www-form-urlencoded' }, body: 'passcode=' + passcode }); } else { alert('Please enter a 4-digit passcode.'); }"; // Check if the input is 4 digits
        html += "};";
        html += "var modal = document.getElementById('myModal');";
        html += "var span = document.getElementsByClassName('close')[0];";
        html += "span.onclick = function() {";
        html += "modal.style.display = 'none';";
        html += "};";
        html += "window.onclick = function(event) {";
        html += "if (event.target == modal) {";
        html += "modal.style.display = 'none';";
        html += "}";
        html += "};";
        html += "function checkForRinging() {";
        html += "fetch('/ring-notification-get').then(function(response) {";
        html += "if (response.status === 200) {";
        html += "modal.style.display = 'block';";
        html += "}";
        html += "});";
        html += "}";
        html += "setInterval(checkForRinging, 5000);"; // checks every 5 seconds
        html += "var unlockModal = document.getElementById('unlockModal');"; // Get the Unlock button
        html += "unlockModal.onclick = function() {";
        html += "fetch('/unlock-notification', { method: 'POST', headers: { 'Content-Type': 'application/x-www-form-urlencoded' }, body: 'unlock=true' }).then(function(response) {";
        html += "if (response.status === 200) {";
        html += "modal.style.display = 'none';";
        html += "}";
        html += "});";
        html += "};";
        html += "unlockModal.onclick = function() {";
        html += "fetch('/unlock-notification', { method: 'POST', headers: { 'Content-Type': 'application/x-www-form-urlencoded' }, body: 'unlock=true' }).then(function(response) {";
        html += "if (response.status === 200) {";
        html += "modal.style.display = 'none';";
        html += "document.getElementById('unlockStatus').textContent = 'Unlock successful';"; // Display success message
        html += "} else {";
        html += "document.getElementById('unlockStatus').textContent = 'Unlock failed';"; // Display failure message
        html += "}";
        html += "setTimeout(function() {";
        html += "document.getElementById('unlockStatus').textContent = '';"; // Remove the status message after 5 seconds
        html += "}, 5000);"; // 5 seconds delay
        html += "});";
        html += "};";
        html += "document.getElementById('unlock').onclick = function() {";
        html += "fetch('/unlock-notification', { method: 'POST', headers: { 'Content-Type': 'application/x-www-form-urlencoded' }, body: 'unlock=true' }).then(function(response) {";
        html += "if (response.status === 200) {";
        html += "document.getElementById('unlockStatus').textContent = 'Unlock successful';"; // Display success message
        html += "} else {";
        html += "document.getElementById('unlockStatus').textContent = 'Unlock failed';"; // Display failure message
        html += "}";
        html += "setTimeout(function() {";
        html += "document.getElementById('unlockStatus').textContent = '';"; // Remove the status message after 5 seconds
        html += "}, 5000);"; // 5 seconds delay
        html += "});";
        html += "};";
        html += "document.getElementById('addPasscode').onclick = function() {";
html += "  let passcode = document.getElementById('passcodeInput').value;";
html += "  if (passcode.length === 4) {";
html += "    fetch('/new-passcode', {";
html += "      method: 'POST',";
html += "      headers: { 'Content-Type': 'application/x-www-form-urlencoded' },";
html += "      body: 'passcode=' + passcode";
html += "    }).then(function(response) {";
html += "      if (response.status === 200) {";
html += "        document.getElementById('addPasscodeStatus').textContent = 'Passcode added successfully';";
html += "      } else {";
html += "        document.getElementById('addPasscodeStatus').textContent = 'Failed to add passcode';";
html += "      }";
html += "      setTimeout(function() {";
html += "        document.getElementById('addPasscodeStatus').textContent = '';";
html += "      }, 5000);";
html += "    });";
html += "  } else {";
html += "    alert('Please enter a 4-digit passcode.');";
html += "  }";
html += "};";

html += "document.getElementById('removePasscode').onclick = function() {";
html += "  let passcode = document.getElementById('passcodeInput').value;";
html += "  if (passcode.length === 4) {";
html += "    fetch('/remove-passcode', {";
html += "      method: 'POST',";
html += "      headers: { 'Content-Type': 'application/x-www-form-urlencoded' },";
html += "      body: 'passcode=' + passcode";
html += "    }).then(function(response) {";
html += "      if (response.status === 200) {";
html += "        document.getElementById('removePasscodeStatus').textContent = 'Passcode removed successfully';";
html += "      } else {";
html += "        document.getElementById('removePasscodeStatus').textContent = 'Failed to remove passcode';";
html += "      }";
html += "      setTimeout(function() {";
html += "        document.getElementById('removePasscodeStatus').textContent = '';";
html += "      }, 5000);";
html += "    });";
html += "  } else {";
html += "    alert('Please enter a 4-digit passcode.');";
html += "  }";
html += "};";
        html += "</script>";
        html += "</body>";
        html += "</html>";




        // The snapshot page with a 'Go Back' button
        String snapshotPage = "<!DOCTYPE html>";
        snapshotPage += "<html>";
        snapshotPage += "<head>";
        snapshotPage += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"; // Viewport meta tag for responsive design
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

        // sent a notification to the remote that someone is ringing on the door
      _server->on("/ring-notification-get", HTTP_GET, [this](AsyncWebServerRequest *request) {
        if(this->_sendNotification) {
          request->send(200, "text/plain", "Someone is ringing on the door");
          this->_sendNotification = false;
        } else {
          request->send(400, "text/plain", "No one is ringing on the door");
        }
      });

        //Add a new passcode
      _server->on("/new-passcode", HTTP_POST, [this](AsyncWebServerRequest *request) {
        if (request->hasParam("passcode", true)) {
          String newPasscode = request->getParam("passcode", true)->value();
          this->addPasscode(newPasscode);
          request->send(200, "text/plain", "New passcode added");
        } else {
          request->send(400, "text/plain", "No passcode found in the request");
        }
      });

      //Remove a passcode
      _server->on("/remove-passcode", HTTP_POST, [this](AsyncWebServerRequest *request) {
        if (request->hasParam("passcode", true)) {
          String passcodeToRemove = request->getParam("passcode", true)->value();
          this->removePasscode(passcodeToRemove);
          request->send(200, "text/plain", "Passcode removed");
        } else {
          request->send(400, "text/plain", "No passcode found in the request");
        }
      });
      //Try a passcode to unlock
      _server->on("/try-passcode", HTTP_POST, [this, unlockPin](AsyncWebServerRequest *request) {
        if (request->hasParam("passcode", true)) {
          String incomingPasscode = request->getParam("passcode", true)->value();
          if (this->isPasscodeCorrect(incomingPasscode)) {
            unlockTimer = millis();
            digitalWrite(*unlockPin, HIGH);
            request->send(200, "text/plain", "Passcode is correct");
          } else {
            request->send(403, "text/plain", "Passcode is incorrect");
          }
        } else {
          request->send(400, "text/plain", "No passcode found in the request");
        }
      });

      // Post a endnote signal notification that someone rings on the door
    _server->on("/ring-notification-post", HTTP_POST, [this](AsyncWebServerRequest *request) {
      if(request->hasParam("ring", true)) {
        String ring = request->getParam("ring", true)->value();
        if(ring == "true") {
          this->_sendNotification = true;
          request->send(200, "text/plain", "Someone is ringing on the door");
        } else {
          request->send(403, "text/plain", "No one is ringing on the door");
        }
      } else {
        request->send(400, "text/plain", "No ring found in the request");
      }
    });

    // Post a endnote signal notification that the remotes unlock the door
    _server->on("/unlock-notification", HTTP_POST, [this, unlockPin](AsyncWebServerRequest *request) {
      if (request->hasParam("unlock", true)) {
        String unlock = request->getParam("unlock", true)->value();
        if (unlock == "true") {
          unlockTimer = millis();
          digitalWrite(*unlockPin, HIGH);
          request->send(200, "text/plain", "Door unlocked");
        } else {
          request->send(403, "text/plain", "Door not unlocked");
        }
      } else {
        request->send(400, "text/plain", "No unlock found in the request");
      }
    });

      //Start the server
      _server->begin();
      Serial.println("Web server started");
      Serial.println("Stream server: " + String(streamServer));
      Serial.println("Snapshot server: " + String(snapshotServer));
      Serial.println("Admin server: " + String(adminServer));
} 
// This function adds a passcode to the passcodes vector.
void ESPServer::addPasscode(String passcode) {
  for (int i = 0; i < MAX_PASSCODES; i++) {
    if (_passcodes[i].isEmpty()) {
      _passcodes[i] = passcode;
      Serial.println("New passcode added: " + passcode);
      break;
    }
  }
}

// This function removes a passcode from the passcodes vector.
void ESPServer::removePasscode(String passcode) {
  for (int i = 0; i < MAX_PASSCODES; i++) {
    if (_passcodes[i] == passcode) {
      _passcodes[i] = "";
      Serial.println("Passcode removed: " + passcode);
      break;
    }
  }
}
// This function checks if a passcode is in the passcodes vector.
bool ESPServer::isPasscodeCorrect(String passcode) {
  for (int i = 0; i < MAX_PASSCODES; i++) {
    if (_passcodes[i] == passcode) {
      Serial.println("Passcode is correct: " + passcode + " - door unlocked");
      return true;
    }
  }
  return false;
}


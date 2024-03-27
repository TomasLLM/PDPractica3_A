// P3.1
// Autor: Tomàs Lloret
#include <WiFi.h>
#include <WebServer.h>
#include <Arduino.h>
void handle_root();

// SSID & Password
const char* ssid = "Xiaomi_11T_Pro"; 
const char* password = "12345678"; 
WebServer server(80);

void setup() {
    Serial.begin(115200);
    Serial.println("Try Connecting to ");
    Serial.println(ssid);
    // Connecta al teu modem
    WiFi.begin(ssid, password);
    // Mira si la wifi te connexió a internet
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected successfully");
    Serial.print("Got IP: ");
    Serial.println(WiFi.localIP()); 
    server.on("/", handle_root);
    server.begin();
    Serial.println("HTTP server started");
    delay(100);
}

void loop() {
    server.handleClient();
}

// Contingut HTML & CSS a mostrar
String HTML = "<!DOCTYPE html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>La meva primera pàgina feta amb l'ESP32</title>
</head>
<body>
    <h1>La meva primera pàgina feta amb l'ESP32</h1>
    <p>Aquest és el meu primer intent de crear una pàgina web utilitzant l'ESP32. :)</p>
</body>
</html>
";
// Root url (/)
void handle_root() {
    server.send(200, "text/html", HTML);
}
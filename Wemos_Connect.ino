#include <ESP8266WiFi.h>

#define LED 2

const char* ssid = "YOUR_WIFI_SSID(name)";
const char* password = "YOUT_WIFI_PASSWORD";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");  
  }

  Serial.println("");
  Serial.println("Connected");
  
  server.begin();
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  Serial.println("new client");
  while(!client.available()) delay(1);

  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  String message;

  if (req.indexOf("/sayhello") != -1) {
    message = "Hi!";
  } else 
  if (req.indexOf("/led/on") != -1) {
    digitalWrite(LED, HIGH);
    message = "LED is ON";
  } else
  if (req.indexOf("/led/off") != -1) {
    digitalWrite(LED, LOW);
    message = "LED is OFF";
  } else {
    Serial.println("invalid request");
    client.stop();
    return;
  }

  client.print(Header() + message + Footer());
}

String Header() {
  return "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r";
}
String Footer() {
  return "</html>\n";
}

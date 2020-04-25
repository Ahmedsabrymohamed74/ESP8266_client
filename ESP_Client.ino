/*
    This sketch sends a string to a TCP server, and prints a one-line response.
    You must run a TCP server in your local network.
    For example, on Linux you can use this command: nc -v -l 3000
*/

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#ifndef STASSID
#define STASSID "your-ssid"
#define STAPSK  "your-password"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

//Enter host IP and java's open port
const char* host = "";
const uint16_t port = ;
int outputpin= A0;
ESP8266WiFiMulti WiFiMulti;
WiFiClient client;

void setup() {
  Serial.begin(115200);

  // We start by connecting to a WiFi network
  WiFi.mode(WIFI_STA);
  //Enter you own WiFi credentials
  WiFiMulti.addAP("", "");
  
  
  
  Serial.println();
  Serial.println();
  Serial.print("Wait for WiFi... ");

  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  delay(500);


if (!client.connect(host, port)) {
    Serial.println("connection failed");
    Serial.println("wait 5 sec...");
    delay(5000);
    return;
  }

}
void loop() {
  


Serial.print("connecting to ");
  Serial.print(host);
  Serial.print(':');
  Serial.println(port);
    

  //read back one line from server
  Serial.println("receiving from remote server");
  delay(1000);
  String line = client.readStringUntil('\r');
  Serial.println(line);
   int analogValue = analogRead(outputpin);
float millivolts = (analogValue/1024.0) * 3300; //3300 is the voltage provided by NodeMCU
float celsius = millivolts/10;

client.println("One: in DegreeC = " + String(celsius) + '\n');
delay(2000);
Serial.println("One: in DegreeC = " + String(celsius));
//delay(2000);
 //  Serial.println("closing connection");
//  client.stop();

  Serial.println("wait 5 sec...");
  delay(5000);
}
  

#include "ESP8266.h"
const char *SSID     = "SkyrockProjects2";
const char *PASSWORD = "rememberable";

SoftwareSerial mySerial(10, 11); //SoftwareSerial pins for MEGA/Uno. For other boards see: https://www.arduino.cc/en/Reference/SoftwareSerial

ESP8266 wifi(mySerial); 

float beats;

void setup() {
  // put your setup code here, to run once:
  //Start Serial Monitor at any BaudRate
  Serial.begin(57600);
  Serial.println("Begin");
  if (!wifi.init(SSID, PASSWORD))
  {
    Serial.println("Wifi Init failed. Check configuration.");
    while (true) ; // loop eternally
  }

}

void loop() {
  // put your main code here, to run repeatedly:
    beats= analogRead(0);
    char result_a[5] = "";
    char result_b[5] = "";
    Serial.println("Sending Request");
    //send request httpGet(char* temp) -- temp will be sensor variable    
    wifi.httpGet(dtostrf(beats, 3, 2, result_a));// you can add second parameter into function

    delay(1000);
}

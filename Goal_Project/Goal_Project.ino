#include<WiFiClient.h>
#include<ESP8266WebServer.h>
#include<ESP8266WiFi.h>
#include <Ultrasonic.h>

/*
 * Pass as a parameter the trigger and echo pin, respectively,
 * or only the signal pin (for sensors 3 pins), like:
 * Ultrasonic ultrasonic(13);
 */
 const char* ssid="manak";
 const char* password="11223344";
 ESP8266WebServer server(80);    //assign the port to the web server to be generated

 WiFiClient client;
Ultrasonic ultrasonic(D1,D2);
Ultrasonic ultrasonic1(D3,D4);
Ultrasonic ultrasonic2(D6,D7);
int distance;
int distance1;
int distance2;
int count;
unsigned long time1;

void setup() {
  Serial.begin(115200);
  Serial.println("Start");
  connectWiFi();
  
}

void loop() {
  // Pass INC as a parameter to get the distance in inches
  distance = ultrasonic.read();
  distance1 = ultrasonic1.read();
  distance2 = ultrasonic2.read();
  time1 =millis();
  if(time1<10000){
    if(distance||distance1||distance2!=357){
    Serial.println(goal);
    count++;
    }
  }else {
    Serial.println("No of goals= "+String(count));
    }
  delay(1000);
}

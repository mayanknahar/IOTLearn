#include <ThingSpeak.h>
#include<ESP8266WiFi.h>
const char* ssid ="manak";
const char* password ="11223344";
char thingSpeakAddress[] ="api.thingspeak.com";
unsigned long channelID=797855;
char* readAPIKey ="83IBL55XXSFOTANI";
unsigned int dataFieldOne =1;


WiFiClient client;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Start");
  connectWiFi();
  pinMode(D1,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  delay(1000);
}

void loop() {

float data1= readTSData(channelID, dataFieldOne);
if(data1==1.0){
  digitalWrite(D1,0);
}else if(data1==2.0){
  digitalWrite(D1,0);
  digitalWrite(D2,0);
}else if(data1==3.0){
  digitalWrite(D1,0);
  digitalWrite(D2,0);
  digitalWrite(D3,0);
}else if(data1==4.0){
  digitalWrite(D1,0);
  digitalWrite(D2,0);
  digitalWrite(D3,0);
  digitalWrite(D5,0);
}else{
  Serial.print("Data more than required");
  }
delay(1000);
}

int connectWiFi(){
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.println("*");
  }
  Serial.println("Connected to ThingSpeak");
  ThingSpeak.begin(client);
}


float readTSData(long TSChannel, unsigned int TSField){
    float data=ThingSpeak.readFloatField(TSChannel, TSField, readAPIKey);
    Serial.println("Data read from ThingSpeak: "+String(data,9));
   
    return data;
  }

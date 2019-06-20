#include <ThingSpeak.h>
#include<ESP8266WiFi.h>
const char* ssid ="manak";
const char* password ="12345678";

//Think speak info
char thingSpeakAddress[] ="api.thingspeak.com";
//unsigned long channelID=800918;
unsigned long channelID=797855;

//char* writeAPIKey ="CL9Y9KEDVOIIPS8U";
//char* readAPIKey ="7LOUVWHEW6IG84G6";

char* readAPIKey ="83IBL55XXSFOTANI";
unsigned int dataFieldOne =1;
//unsigned int dataFieldTwo =1;       //field to write the data on thingspeak
WiFiClient client;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Start");
  connectWiFi();
  pinMode(D4,OUTPUT);
  //pinMode(D3,INPUT);
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
//float readValue=digitalRead(D2);
//float a=digitalRead(D3);
//Serial.println("IR Sensor value =" + String(a));
//Serial.println(" value of D2 =" + String(readValue));

//write2TSData(channelID, dataFieldOne, readValue, dataFieldTwo, a);


float data1= readTSData(channelID, dataFieldOne);


//writeTSData(channelID1, dataFieldTwo, data1);

 if(data1<=150){
  digitalWrite(D4,LOW);
 }else{
      digitalWrite(D4,HIGH);
    }
delay(2000);
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

/*int writeTSData(long TSChannel1, unsigned int TSField1, float data){
  int writeSuccess=ThingSpeak.writeField(TSChannel1,TSField1,data,writeAPIKey);
  if(writeSuccess){
    Serial.println(String(data) + "  written to the thingSpeak of Mayank");
  }
  return writeSuccess;
}

/*int write2TSData(long TSChannel, unsigned int TSField, float data, unsigned int TSField2, float data2){
  ThingSpeak.setField(TSField,data);
  ThingSpeak.setField(TSField2,data2);
  int writeSuccess=ThingSpeak.writeFields(TSChannel,writeAPIKey);
  return writeSuccess;
  }*/
  float readTSData(long TSChannel, unsigned int TSField){
    float data=ThingSpeak.readFloatField(TSChannel, TSField, readAPIKey);
    Serial.println("Data read from ThingSpeak: "+String(data,9));
   
    return data;
  }

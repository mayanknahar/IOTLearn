#include <Adafruit_Sensor.h>

#include <DHT.h>
//#include <Adafruit_Sensor.h>


//#include <DHT.h>
//#include <DHT_U.h>
#define dhtPin D1
DHT dht(dhtPin,DHT11);

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(D1,INPUT);
pinMode(D4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
float temp=dht.readTemperature();
float hum=dht.readHumidity();

/*if(isnan(temp)||isnan(hum)){
  Serial.println("failed to read from sensor");
  delay(2000);
}else{*/

if(temp<15){
  digitalWrite(D2,0);
}else{
  digitalWrite(D2,1);
  }
Serial.println("Room temperature is "+String(temp));
Serial.println("Room humidity is "+String(hum));
delay(15000);
//}
}

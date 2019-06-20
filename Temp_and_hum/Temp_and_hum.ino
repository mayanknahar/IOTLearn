#include <Adafruit_Sensor.h>

#include <DHT.h>
//#include <Adafruit_Sensor.h>


//#include <DHT.h>
//#include <DHT_U.h>
#define dhtPin D2
DHT dht(dhtPin,DHT11);

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(D2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
float temp=dht.readTemperature();
float hum=dht.readHumidity();

/*if(isnan(temp)||isnan(hum)){
  Serial.println("failed to read from sensor");
  delay(2000);
}else{*/
Serial.println("Room temperature is "+String(temp));
Serial.println("Room humidity is "+String(hum));
delay(10000);
//}
}

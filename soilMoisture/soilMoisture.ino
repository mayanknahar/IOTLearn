void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);              //A0 pin works 
pinMode(D4,OUTPUT);
Serial.begin(9600);              //baud rate for connection... serial output on the serial monitor
}

void loop() {
  // put your main code here, to run repeatedly:
float sensor=analogRead(A0);      //value is read from the soil moisture sensor
Serial.print("soil moisture content is :");
Serial.println(sensor);         //prints the value retrieeved from the sensor
delay(500);
float percent=100-((sensor/1023)*100);
Serial.println(percent);
if(sensor<500){                 //if the value decreases below 500 the led will be on and if the value is above it it is off
  digitalWrite(D4,0);
  }else{
    digitalWrite(D4,1);
    }

}

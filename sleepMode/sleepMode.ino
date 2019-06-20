void setup() {
  pinMode(D4,OUTPUT);
  // put your setup code here, to run once:
Serial.begin(115200);
Serial.setTimeout(2000);
//wait for serial to initialize
while(!Serial){}
//deep sleep mode for 30 sec, 
Serial.println("I'm awake but going into deep sleep for 30 sec");
digitalWrite(D4,0);
ESP.deepSleep(30e6);//values in deep sleep are in micro sec therefore e6 means 10 to the power 6
}

void loop() {
  // put your main code here, to run repeatedly:

}

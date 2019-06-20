void setup() {
  // put your setup code here, to run once:
pinMode(D4,OUTPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(D4,0);
delay(100);
digitalWrite(D4,1);
delay(100);
Serial.println("Hello Blink");
delay(100);
}

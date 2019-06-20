void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(D4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D4, 0);
  delay(10);
  digitalWrite(D4, 1);
  delay(10);

}

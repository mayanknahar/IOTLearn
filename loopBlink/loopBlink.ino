void setup() {
  // put your setup code here, to run once:
pinMode(D4,OUTPUT);
}

void loop() {
 
  // put your main code here, to run repeatedly:
  int i=100;
  for(int a=0;a<10;a++)
  {
    digitalWrite(D4,0);
    delay(i);
    digitalWrite(D4,1);
    delay(i);
    i=i+100;
    }
}

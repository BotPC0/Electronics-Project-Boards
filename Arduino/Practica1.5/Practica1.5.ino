int Led1 = 7;
int Led2 = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(Led1,HIGH);
digitalWrite(Led2,LOW);
delay(500);
digitalWrite(Led1,LOW);
digitalWrite(Led2,HIGH);
delay(500);
}

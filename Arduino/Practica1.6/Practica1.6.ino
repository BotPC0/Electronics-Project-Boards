int Led1=4;
int Led2=7;
int Led3=2;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  
digitalWrite(Led3,LOW);
digitalWrite(Led2,LOW);
digitalWrite(Led1,HIGH);

delay(5000);

digitalWrite(Led1,LOW);
digitalWrite(Led2,HIGH);

delay(2000);

digitalWrite(Led2,LOW);
digitalWrite(Led3,HIGH);

delay(5000);

}

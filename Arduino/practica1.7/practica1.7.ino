int Led1 = 7;


void setup() {
  // put your setup code here, to run once:
  pinMode(Led1, OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:

for (int i=0; i < 3; i++){ //S.
     
digitalWrite(Led1,HIGH);
delay(100);
digitalWrite(Led1,LOW);
delay(100);
}

delay(500);

for (int i=0; i < 3; i++){ //O.
     
digitalWrite(Led1,HIGH);
delay(300);
digitalWrite(Led1,LOW);
delay(100);
}

delay(500);

for (int i=0; i < 3; i++){ //S.
     
digitalWrite(Led1,HIGH);
delay(100);
digitalWrite(Led1,LOW);
delay(100);
}

delay(2000); //S.O.S.
}

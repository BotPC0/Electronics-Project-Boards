

void setup() {
  // put your setup code here, to run once:
pinMode(13, OUTPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

for (int i=0; i < 20; i++){
  
      digitalWrite(13,HIGH);
delay(200);
      digitalWrite(13,LOW);
delay(200);

    Serial.println(i);
    
    while(i==19){
   digitalWrite(13,HIGH);
}
   }

}

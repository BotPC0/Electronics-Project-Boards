
int led = 9;           
int i = 0;    
int Pulsador1 = 2;
int Pulsador2 = 3;


void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  


 digitalRead(Pulsador1);
 digitalRead(Pulsador2);



if (digitalRead(Pulsador1)==HIGH)
{
  

i++;
      analogWrite(led, i);
      delay(50);
   


}

if (digitalRead(Pulsador2)==HIGH)
{
  

i--;
analogWrite(led, i);
delay(50);


}

Serial.print(i);

 
}


int LedR = 7;     
int Pulsador = 8;
int x = 0;     
int y = 0; 

void setup() {
  // put your setup code here, to run once:
  pinMode(LedR, OUTPUT);
  pinMode(Pulsador, INPUT); 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
y = digitalRead(Pulsador);    




while((y==LOW) && (x < 5)){
x=x+1;
delay(500);
y = digitalRead(Pulsador);
Serial.print(x);
}

while ((y==HIGH) && (x == 5)){
digitalWrite(LedR, HIGH);
delay(4000);
y = digitalRead(Pulsador);
Serial.print(x);

if(y==LOW){
  x=1;
  }
}

digitalWrite(LedR, LOW);
delay(300);

}

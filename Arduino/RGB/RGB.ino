int Azul=6;
int Verde=7;
int Rojo=8;
int t=500;
void setup() {
  // put your setup code here, to run once:
  
pinMode(Azul, OUTPUT);
pinMode(Verde, OUTPUT);
pinMode(Rojo, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

 
  
analogWrite(Rojo,50);
analogWrite(Verde,0);
analogWrite(Azul,45);
delay(t);
analogWrite(Rojo,0);
analogWrite(Verde,0);
analogWrite(Azul,0);
delay(t);
  
analogWrite(Rojo,50);
analogWrite(Verde,0);
analogWrite(Azul,100);
delay(t);


}

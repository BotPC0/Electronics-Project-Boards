  int leds[] = {5, 6, 7, 8, 9};
int tiempo=200;
int Pulsador1 = 2;
int n=0;


void setup(){
  
  Serial.begin(9600); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT); 

}

void comprobar(){

if ((digitalRead(Pulsador1)==HIGH) && (tiempo >= 20) && (n==2))
{

tiempo=tiempo-20;

      delay(10);

}

if(tiempo < 20){

tiempo = 200;
Serial.print("Ganaste :)");

  
  }



}

void loop () {
for( n=0;n<5;n++) {
  
Serial.print(tiempo);

digitalWrite(leds[n],HIGH);
delay(tiempo);
comprobar();
digitalWrite(leds[n],LOW);
delay(tiempo);
}
}

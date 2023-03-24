

#include <Servo.h>


Servo LEGL; //Crear 4 objetos servo que nos servirán para acceder a las funciones de la librería.
Servo LEGR;
Servo FOOTR;
Servo FOOTL;

const int EchoPin= 2;
const int TriggerPin= 3;

int pos = 0;    // tiempo


int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;
}

void setup() {
  LEGR.attach(6);   //LegR hacia la derecha (+);
  FOOTL.attach(5);  //FootL hacia arriba (+);
  LEGL.attach(11);  //LegL hacia la derecha (+);
  FOOTR.attach(10); //FootR hacia arriba (-);
  
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  
  Serial.begin(9600);
  
  
}

void loop() {
  
 int t =800;
 
 int distancia = ping(TriggerPin, EchoPin);
 Serial.println(distancia);
 delay(300);
 
while(distancia >= 20){
  

//primer paso

delay(t);

FOOTL.write(85+15);
LEGR.write(90+60);

delay(t);

LEGL.write(85+60);
FOOTL.write(85);
FOOTR.write(90-15);

delay(t);

LEGR.write(90+0);
LEGL.write(85+0);
FOOTL.write(85+15);
FOOTR.write(100-0);

delay(t);

FOOTL.write(85+0);

delay(t);

//segundo paso

FOOTR.write(90-15);
LEGR.write(90+60);

delay(t);


LEGL.write(85+60);
FOOTL.write(75+0);
FOOTR.write(90-15);

delay(t);

LEGR.write(90+0);
LEGL.write(75+0);
FOOTL.write(85+0);
FOOTR.write(90-15);

delay(t);

FOOTR.write(90);

distancia = ping(TriggerPin, EchoPin);

}

//Giro fuera del while

FOOTR.write(90-15);
LEGL.write(85+80);
delay(t);
FOOTL.write(90-15);
LEGL.write(85+0);
delay(t);
FOOTL.write(90-0);
FOOTR.write(90-0);
delay(t);

FOOTR.write(90-15);
LEGL.write(85+80);
delay(t);
FOOTL.write(90-15);
LEGL.write(85+0);
delay(t);
FOOTL.write(90-0);
FOOTR.write(90-0);
delay(t);
}



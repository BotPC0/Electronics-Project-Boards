/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position


void chop(){
  int DeltaX =0;
  int absolute =0;
  int Result=0;
  int Posicion =0;
  int Multiplier1=2;
  int AnguloInicial=0;
  int AnguloFinal=0;

  
myservo.read()=AnguloInicial
=AnguloFinal
  DeltaX = AnguloInicial - AnguloFinal;

absolute=abs(DeltaX);

  if ((15 < absolute) && (absolute > 30)){

  Result=DeltaX/Multiplier1;

if (AnguloInicial < AnguloFinal){

 for (int i=1; i <= Multiplier1; i++){
    
    Posicion = absolute*i + AnguloInicial;
      myservo.write(Posicion);
      delay(10);
   }
     
    }

else {
   for (int i=1; i <= Multiplier1; i++){
    
    Posicion = AnguloInicial - absolute*i;
      myservo.write(Posicion);
      delay(10);
  }
  }

  
}

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {


}


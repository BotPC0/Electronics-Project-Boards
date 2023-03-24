#include <Servo.h> //Añade librería servo

Servo PiernaIzq; //Crear 4 objetos servo que nos servirán para acceder a las funciones de la librería.
Servo PiernaDer;
Servo PataDer;
Servo PataIzq;
 int PiD, PiZ = 90; //Establece el valor inicial de las piernas
 int PaD, PaZ = 90; //Establece el valor de los pies/patas.
int tiempo = 1500; 
int giroPiernas = 30;
//Inicializa los 4 servos a la posición inicial, 90 grados.
void Inicio (){
	PataDer.write(90);
  	PiernaDer.write(PiD);
  	PataIzq.write(90);
  	PiernaIzq.write(PiZ);
}

void movimientoSuave (String p, int a, int t){

  if()
  }
//Secuencia que da para dar un paso con la pierna derecha y acaba centrado.
void PasoD (){
      //Se eleva sobre el pie derecho
	    PataIzq.write(45 + 90);
     delay(1000);
	    PataDer.write(40+90);
      
      delay(tiempo);

      //Gira ambas piernas, la derecha para avanzar,
      //y la izquierda en dirección contraria para preparar el siguiente paso.
  	  PiernaDer.write(-giroPiernas+90);
  	  //PiernaIzq.write(-giroPiernas+90);
      delay(tiempo);

      //Baja del pie derecho y se posa sobre ambos pies (Posición actual: diagonal, con la pierna y pie izquierdo adelantado)
  		PataDer.write(90);
      PataIzq.write(100);
  		delay(tiempo);
      
      PiernaDer.write(90);
     //Se eleva sobre el pie izquierdo
  		
  		
  		//PataIzq.write(30+90);
  		delay(tiempo);

     //Gira ambas pierdas, justo al contrario que se han girado antes, así
     //se quedan alineadas las dos al frente
  		//PiernaIzq.write(90);
  		//PiernaDer.write(90);
  		delay(tiempo);

     //Baja del pie izquierdo, y se posa sobre ambos pies.(Posición actual: de frente)
  		//PataIzq.write(90);
  		delay(tiempo);
}


//Secuencia que da para dar un paso con la pierna izquierda y acaba centrado.  
void PasoI(){

     //Se eleva sobre el pie izquierdo
      PataIzq.write(30+90);
      delay(tiempo);

      //Gira ambas piernas, la izquierda para avanzar,
      //y la derecha en dirección contraria para preparar el siguiente paso.
      PiernaIzq.write(giroPiernas+90);
      PiernaDer.write(-giroPiernas+90);
      delay(tiempo);

      //Baja del pie izquierdo y se posa sobre ambos pies (Posición actual: diagonal, con la pierna y pie derecho adelantado)
      PataIzq.write(-30+90);
      delay(tiempo);

     //Se eleva sobre el pie derecho
      PataDer.write(30+90);
      delay(tiempo);

     //Gira ambas pierdas, justo al contrario que se han girado antes, así
     //se quedan alineadas las dos al frente
      PiernaDer.write(giroPiernas+90);
      PiernaIzq.write(-giroPiernas+90);
      delay(tiempo);

     //Baja del pie derecho, y se posa sobre ambos pies.(Posición actual: de frente)
      PataDer.write(-30+90);
      delay(tiempo);

  
  }

void setup()
{
  //Une los 4 servos con sus pines correspondientes
  PiernaDer.attach(6);
  PataDer.attach(5);
  PiernaIzq.attach(11);
  PataIzq.attach(10);
  
  Serial.begin(9600);
}

void loop()
{
  //Llamada a la función de inicialización
  //Inicio();
  //delay(300);

  //Da 5 pasos, empezando por el paso derecho y terminando por el paso izquierdo.
  for(int i=0; i<5; i++){
   //Llamada a la función que inicia el paso derecho.
    PasoD();
    delay(100);
    //Llamada a la función que inicia el paso izquierdo.
   // PasoI();
    delay(100);
  }
}

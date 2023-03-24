
const int PIRPin= 7;

const int LDRPin = A1;

const int LED1 = 10;
const int LED2 = 11;

const int Azul=4;
const int Verde=5;
const int Rojo=6;


const int Pintrigger = 2;
const int Pinecho = 3;

const int pulsador=9;

int R=0;
int V=0;
int A=0;

float Dt = 0;
float r = 0;

float Dx=0;

int Pulsar=0;

float Distancia(){ //Funcion distancia
  
digitalWrite(Pintrigger,HIGH);

delayMicroseconds(10);

digitalWrite(Pintrigger,LOW);

Dt = pulseIn(Pinecho, HIGH, 60000.0);

r = (Dt*34.0)/2000.0; //cm

Serial.println(r);

delay(1000);

return(r);

  }

void setup()
{
 
  pinMode(PIRPin, INPUT);
  pinMode(LED1, OUTPUT); 
  pinMode(LED2, OUTPUT); 

  
pinMode(Azul, OUTPUT);
pinMode(Verde, OUTPUT);
pinMode(Rojo, OUTPUT);

pinMode(pulsador, INPUT);
 
pinMode(Pintrigger, OUTPUT);
pinMode(Pinecho, INPUT);

Serial.begin(9600);
}



 
void loop()
{
  
  int Movimiento = digitalRead(PIRPin); //vemos el valor del movimiento

  
  
 
  if (Movimiento == HIGH)
  {

  Serial.println("Movimiento ");
    
  int value = analogRead(LDRPin);

  int Luz = map(value, 0, 1023, 255, 0);
  
  Serial.print("Luz: ");
  Serial.println(Luz);
  
  delay(300);

  if (Luz<=20) // dia
{
 delay(2000); 
 Serial.println("Dia ");
}

else if ((Luz>20)&&(Luz<=60)) // tarde
{
  
  Serial.println("Tarde ");
  
  randomSeed(millis());    // genera una semilla para aleatorio a partir de la función millis()

R = random(255);   
V = random(255); 
A = random(255); 

analogWrite(Rojo,R);
analogWrite(Verde,V);
analogWrite(Azul,A); 

delay(5000);

analogWrite(Rojo,0);
analogWrite(Verde,0);
analogWrite(Azul,0); 
}

else // noche
{
  
Serial.println("Noche ");
  
Dx = Distancia(); 

delay(300);

  Serial.println(Dx);

if (Dx>30)
{
  
Serial.println(">30 ");
  
  analogWrite(LED1,50); // enciende Led1 intensidad media
    
  for (int i=1; i <= 50; i++){
    
Pulsar = digitalRead(pulsador); //comprueba pulsador

      if (Pulsar==HIGH){
        
      analogWrite(LED1, 0);

      break;

      }
      
      delay(200);
       
   }

   analogWrite(LED1, 0);
   analogWrite(LED2, 0);
   
    
    
 
 
    
}
else if ((Dx<=30)&&(Dx>=15))
{
 Serial.println("15<x<30 ");
 analogWrite(LED1,50);
 analogWrite(LED2,50);// enciende Led1 y 2 intensidad media

 for (int i=1; i <= 50; i++){
  
Pulsar = digitalRead(pulsador);

      if (Pulsar==HIGH){
        
      analogWrite(LED1, 0);
      analogWrite(LED2, 0);

      break;

      }
      
      delay(200);
       
   }

   analogWrite(LED1, 0);
   analogWrite(LED2, 0);
   
}
else
{
  
  Serial.println("x<15");
  
  analogWrite(LED1,255);
  analogWrite(LED2,255);// enciende Led1 y 2 intensidad maxima

for (int i=1; i <= 50; i++){
  
Pulsar = digitalRead(pulsador);

      if (Pulsar==HIGH){
        
      analogWrite(LED1, 0);
      analogWrite(LED2, 0);

      break;

      }
      
      delay(200);
       
   }
   
   analogWrite(LED1, 0);
   analogWrite(LED2, 0);
  
}

}
  
  }
  
  
}

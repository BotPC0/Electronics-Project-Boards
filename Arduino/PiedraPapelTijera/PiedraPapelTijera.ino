//5; Piedra1
//6; Papel1
//7; Tijera1

//2; Piedra2
//3; Papel2
//4; Tijera2

int Herramienta[] = {5, 6, 7, 2, 3, 4};
int Led1 = 9;
int Led2 = 10;

int Pulsador[6];


void setup() {
  // put your setup code here, to run once:

  for (int i = 0; i <= 5; i++) {
    pinMode(Herramienta[i], INPUT);
  }


  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i <= 5; i++) {
    Pulsador[i] = digitalRead(Herramienta[i]);
  }



  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);

  delay(200);

  if (((Pulsador[0] == Pulsador[3]) && Pulsador[0]==1) || ((Pulsador[1] == Pulsador[4]) && Pulsador[1]==1 ) || ((Pulsador[2] == Pulsador[5]) && Pulsador[2]==1)) {

Serial.println("EMPATE");
      
      digitalWrite(Led1, HIGH);
      digitalWrite(Led2, HIGH);
        delay(2000);
        digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
    }


  else if ((Pulsador[0] > Pulsador[5]) || (Pulsador[1] > Pulsador[3]) || (Pulsador[2] > Pulsador[4]))
  {

Serial.println("Gana Jugador 1");

    digitalWrite(Led1, HIGH);
delay(2000);
        digitalWrite(Led1, LOW);
  }

  else if ((Pulsador[4] > Pulsador[0]) || (Pulsador[5] > Pulsador[1]) || (Pulsador[3] > Pulsador[2]))
  {
    
Serial.println("Gana Jugador 2");

    digitalWrite(Led2, HIGH);
    delay(2000);
        digitalWrite(Led2, LOW);

  }

  else
  {
   delay(200); 
    }



 


}


const byte PinesMotor[6] = {13, 12, 11, 10, 9, 8};
//EN1,EN2,IN1,IN2,IN3,IN4

// Configuracion de las direcciones:
byte VAdelante[6] = {0, 0, 1, 0, 1, 0};
byte VIzquierda[6] = {0, 0, 0, 1, 0, 0};
byte VDerecha[6] = {0, 0, 0, 0, 0, 1};
byte VAtras[6] = {0, 0, 0, 1, 0, 1};
byte VStop[6] = {0, 0, 0, 0, 0, 0};

int Velocidad;  // Variable para guardar el valor de la velocidad

const byte Pulsador[4] = {7, 6, 5, 4}; // Adelante, Izquierda, Derecha, Atras
const byte PinPotenciometro = A1;
byte ValorPulsador[4]; // Variable para guardor el estado del pulsador


void setup() {

  for (int i = 0; i < 6; i++) {
    pinMode(PinesMotor[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(Pulsador[i], INPUT);
  }

  pinMode(PinPotenciometro, INPUT);

  Serial.begin(9600);
}

void loop() {


  for (int i = 0; i < 4; i++) { //lectura de los estados del potenciometro
    ValorPulsador[i] = digitalRead(Pulsador[i]);
  }

  int ValorPot = analogRead(PinPotenciometro);  //realizar la lectura analógica
  Velocidad = map(ValorPot, 0, 1023, 0, 255);  //convertir a porcentaje



  if (ValorPulsador[0] == 1) { //Adelante
    Adelante(Velocidad);
  }
  else if (ValorPulsador[1] == 1) { //Izquierda
    Izquierda(Velocidad);
  }
  else if (ValorPulsador[2] == 1) { //Derecha
    Derecha(Velocidad);
  }
  else if (ValorPulsador[3] == 1) { //Atras
    Atras(Velocidad);
  }
  else { //Ninguna accion
    Serial.print("No pasa nada");
    Stop();
  }

}

// Funciones de movimiento del motor:

void Adelante(int Velocidad) {
  for (int i = 0; i < 6; i++) {
    digitalWrite(PinesMotor[i], VAdelante[i]);
  }
  analogWrite(PinesMotor[0], Velocidad);
  analogWrite(PinesMotor[1], Velocidad);
}

void Atras(int Velocidad) {
  for (int i = 0; i < 6; i++) {
    digitalWrite(PinesMotor[i], VAtras[i]);
  }
  analogWrite(PinesMotor[0], Velocidad);
  analogWrite(PinesMotor[1], Velocidad);
}

void Derecha(int Velocidad) {
  for (int i = 0; i < 6; i++) {
    digitalWrite(PinesMotor[i], VDerecha[i]);
  }
  analogWrite(PinesMotor[1], Velocidad);
}

void Izquierda(int Velocidad) {
  for (int i = 0; i < 6; i++) {
    digitalWrite(PinesMotor[i], VIzquierda[i]);
  }
  analogWrite(PinesMotor[0], Velocidad);
}

void Stop() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(PinesMotor[i], VStop[i]);
  }
}

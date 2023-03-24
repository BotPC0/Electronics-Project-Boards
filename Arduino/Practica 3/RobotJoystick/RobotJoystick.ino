
const byte PinesMotor[6] = {13, 12, 11, 10, 9, 8};
//EN1,EN2,IN1,IN2,IN3,IN4

// Configuracion de las direcciones:
byte VAdelante[6] = {0, 0, 0, 1, 0, 1};
byte VAtras[6] = {0, 0, 1, 0, 1, 0};
byte VStop[6] = {0, 0, 0, 0, 0, 0};

int Velocidad[4]; //Velocidad para cada direccion

const int Joystick[2] = {A0, A1}; //Joystick eje x, Joystick eje y
int ValorJoystick[2]; //Variables que guardan el valor del Joystick

int error = 30; //Valor de error que incluimos en los potenciometros
int OrigenX = 515; //Valor de origen del eje x
int OrigenY = 503; //Valor de origen del eje y


void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 6; i++) {
    pinMode(PinesMotor[i], OUTPUT);
  }
}

void loop() {


  for (int i = 0; i < 2; i++) {
    ValorJoystick[i] = analogRead(Joystick[i]); //[0] eje x; [1] eje y
  }

  Velocidad[0] = map(ValorJoystick[0], OrigenX, 1023, 0, 255); //Velocidad Eje X Adelante
  Velocidad[1] = map(ValorJoystick[0], OrigenX, 0, 0, 255); //Velocidad Eje X Atras

  Velocidad[2] = map(ValorJoystick[1], OrigenY, 1023, 0, 255); //Velocidad Eje Y Derecha
  Velocidad[3] = map(ValorJoystick[1], OrigenY, 0, 0, 255); //Velocidad Eje Y Izquierda


  Serial.print("  X:" );
  Serial.print(ValorJoystick[0]);
  Serial.print(" | Y: ");
  Serial.print(ValorJoystick[1]);

  if (ValorJoystick[0] > (OrigenX + error) and ValorJoystick[1] < (OrigenY - error) ) { //Adelante Izquierda
    Adelante(Velocidad[0], Velocidad[3]);
    Serial.print(" |  Adelante Izquierda");
  }
  else if (ValorJoystick[0] > (OrigenX + error) and ValorJoystick[1] > (OrigenY + error)) { //Adelante Derecha
    Adelante(Velocidad[2], Velocidad[0]);
    Serial.print(" |  Adelante Derecha");
  }
  else if (ValorJoystick[0] > (OrigenX + error)) { //Adelante
    Adelante(Velocidad[0], Velocidad[0]);
    Serial.print(" |  Adelante");
  }
  else if (ValorJoystick[0] < (OrigenX - error) and ValorJoystick[1] < (OrigenY - error)) { //Atras Izquierda
    Atras(Velocidad[1], Velocidad[3]);
    Serial.print(" |  Atras Izquierda");
  }
  else if (ValorJoystick[0] < (OrigenX - error) and ValorJoystick[1] > (OrigenY + error)) { //Atras Derecha
    Atras(Velocidad[2], Velocidad[1]);
    Serial.print(" |  Atras Derecha");
  }
  else if (ValorJoystick[0] < (OrigenX - error)) { //Atras
    Atras(Velocidad[1], Velocidad[1]);
    Serial.print(" |  Atras");
  }
  else if ( ValorJoystick[1] > (OrigenY + error) ) { // Derecha
    Adelante(Velocidad[2], 0);
    Serial.print(" | Derecha");
  }

  else if ( ValorJoystick[1] < (OrigenY - error) ) { // Izquierda
    Adelante(0, Velocidad[3]);
    Serial.print(" | Izquierda");
  }

  else { //Ninguna accion
    Serial.print(" |  Stop");
    Stop();
  }

  delay(100);

}

// Funciones de movimiento del motor:

void Adelante(int Velocidad1, int Velocidad2) {
  for (int i = 0; i < 6; i++) {
    digitalWrite(PinesMotor[i], VAdelante[i]);
  }
  analogWrite(PinesMotor[0], Velocidad1);
  analogWrite(PinesMotor[1], Velocidad2);
}

void Atras(int Velocidad1, int Velocidad2) {
  for (int i = 0; i < 6; i++) {
    digitalWrite(PinesMotor[i], VAtras[i]);
  }
  analogWrite(PinesMotor[0], Velocidad1);
  analogWrite(PinesMotor[1], Velocidad2);
}

void Stop() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(PinesMotor[i], VStop[i]);
  }
}

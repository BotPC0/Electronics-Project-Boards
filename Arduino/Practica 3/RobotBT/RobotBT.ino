const byte PinesMotor[6] = {13, 12, 11, 10, 9, 8};
//EN1,EN2,IN1,IN2,IN3,IN4

// Configuracion de las direcciones:
byte VAdelante[6] = {0, 0, 1, 0, 1, 0};
byte VDerecha[6] = {0, 0, 1, 0, 0, 0};
byte VIzquierda[6] = {0, 0, 0, 0, 1, 0};
byte VAtras[6] = {0, 0, 0, 1, 0, 1};
byte VStop[6] = {0, 0, 0, 0, 0, 0};

int Velocidad = 255; // Variable para guardar el valor de la velocidad
int V; // Variable de control de la recepcion de velocidad
String str; // Variable String para recibir la velocidad

char val; // Variable para recibir data del modulo


void setup() {

  for (int i = 0; i < 6; i++) {
    pinMode(PinesMotor[i], OUTPUT);
  }

  Serial.begin(9600);
  Serial2.begin(9600); // Comunicacion Serie para el modulo HC-06 a 9600bps
}

void loop() {


  if ( Serial2.available() )      // Si tenemos data dsiponible para leer se lee
  {
    val = Serial2.read();         // Se lee y se guarda en val
    Serial.println(val);

    if  (val == 'N') { // Si recibimos una N actua como trigger para leer la velocidad

      str = Serial2.readString(); // Leemos la velocidad
      Serial.println(str);
      Velocidad = str.toInt(); // Se transforma a entero
      delay(300);
      Serial.println(Velocidad);

    }

  }


  if (val == 'A') { //Adelante
    Adelante(Velocidad);
    Serial.println("Adelante");
  }
  else if (val == 'I') { //Izquierda
    Izquierda(Velocidad);
    Serial.println("Izquierda");
  }
  else if (val == 'D') { //Derecha
    Derecha(Velocidad);
    Serial.println("Derecha");
  }
  else if (val == 'B') { //Atras
    Atras(Velocidad);
    Serial.println("Atras");
  }
  else if (val == 'S') { //Stop
    Stop();
    Serial.println("Stop");
  }
  else { //Ninguna accion
    delay(10);
  }
  delay(10);
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
  analogWrite(PinesMotor[1], 0);
  analogWrite(PinesMotor[0], Velocidad);
}

void Izquierda(int Velocidad) {
  for (int i = 0; i < 6; i++) {
    digitalWrite(PinesMotor[i], VIzquierda[i]);
  }
  analogWrite(PinesMotor[0], 0);
  analogWrite(PinesMotor[1], Velocidad);
}

void Stop() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(PinesMotor[i], VStop[i]);
  }
}


#include <IRremote.h>

int RECV_PIN = 5; // Pin del receptor

IRrecv irrecv(RECV_PIN); // Definimos el pin al que va a ir conectado el receptor IR

decode_results results; // Valores decodificados

const byte PinesMotor[6] = {13, 12, 11, 10, 9, 8};
//EN1,EN2,IN1,IN2,IN3,IN4

// Configuracion de las direcciones:
byte VAdelante[6] = {0, 0, 1, 0, 1, 0};
byte VDerecha[6] = {0, 0, 1, 0, 0, 0};
byte VIzquierda[6] = {0, 0, 0, 0, 1, 0};
byte VAtras[6] = {0, 0, 0, 1, 0, 1};
byte VStop[6] = {0, 0, 0, 0, 0, 0};

// Configuracion de los botones:
const int KEY_UP = 0xE0E006F9;
const int KEY_LEFT = 0xE0E0A659;
const int KEY_OK = 0xE0E016E9;
const int KEY_RIGHT = 0xE0E046B9;
const int KEY_DOWN = 0xE0E08679;
const int KEY_VOLUMEUP = 0xE0E0E01F;
const int KEY_VOLUMEDOWN = 0xE0E0D02F;

int Velocidad = 160; // Variable de velocidad, por defecto 160
int AV = 20; // Incremento de velocidad
int valor; // Valor en el que guardamos el numero recibido por el receptor

void setup() {

  for (int i = 0; i < 6; i++) {
    pinMode(PinesMotor[i], OUTPUT);
  }

  Serial.begin(9600);

  irrecv.enableIRIn(); // Iniciamos el receptor
  Serial.println("Enabled IRin");

}

void loop() {


  if (irrecv.decode(&results)) { // Si le llega algo al receptor lo decodifica y nos da el resultado

// Serial.println(results.value, HEX);
// Lo anterior sirve para ver por pantalla lo que le llega al receptor

    valor = results.value; // Guardamos los resultados decodificados 

    switch (valor) // Comprobamos si se ha pulsado algun boton conocido y configurado en el mando
    { // Ejecutamos en cada caso la funcion correspondiente
      case KEY_UP:
        Adelante(Velocidad);
        Serial.println("Adelante");
        break;
      case KEY_LEFT:
        Izquierda(Velocidad);
        Serial.println("Izquierda");
        break;
      case KEY_RIGHT:
        Derecha(Velocidad);
        Serial.println("Derecha");
        break;
      case KEY_DOWN:
        Atras(Velocidad);
        Serial.println("Atras");
        break;
      case KEY_OK:
        Stop();
        Serial.println("Stop");
        break;
      case KEY_VOLUMEUP:
        Serial.println("+ Velocidad");
        Velocidad = Velocidad + AV;
        if (Velocidad >= 255) {
          Velocidad = 255;
        }
        break;
      case KEY_VOLUMEDOWN:
        Serial.println("- Velocidad");
        Velocidad = Velocidad - AV;
        if (Velocidad <= 0) {
          Velocidad = 0;
        }
        break;
    }
    Serial.print("Velocidad: ");
    Serial.println(Velocidad);

    irrecv.resume(); // Reanudamos el receptor para la recepcion del siguiente valor

  }
  delay(100);
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

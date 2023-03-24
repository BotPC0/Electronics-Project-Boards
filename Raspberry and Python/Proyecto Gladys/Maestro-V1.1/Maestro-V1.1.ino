//include button.h
//PINES MOTORES

const int ENDer = 8;
const int ENIzq = 9;
const int EN3 = 10;

const int INIzq1 = 24;
const int INIzq2 = 26;

const int INDer1 = 30;
const int INDer2 = 28;

const int IN32 = 32;
const int IN34 = 34;

int velocidad;
int velocidadD = 180; //178
int velocidadI = 150; //120
int velocidad3 = 255;
//Para 45º -- 250
//Para 90º -- 500
//Para 180º-- 1000

//PINES OJITOS del 31 al 49 impares
//ECHO
int OJe[] = {47, 43, 39, 35, 31};
//Trigger
int OJt[] = {49, 45, 41, 37, 33};
boolean colisiones[] = {0, 0, 0, 0, 0};

//PINES final de carrera
int finc1 = 44;
int finc2 = 42;

//pines leds y arranque
int pulsador = 40;
int ledRojo = 46;
int ledAzul = 50;

// Variables extra
unsigned long TiempoLectura = 5000; // Variable de espera en tiempo de lectura de la bateria
unsigned long TiempoLecturaT = 0; // Variable para guardar tiempo total de la lectura de la bateria
unsigned long counter1 = 1; // Contandor para la lectura de la bateria

//Encoders
//ENCODERS
/* Programa que cuenta los pulsos y las revoluciones del encoder foto eléctrico HC-020K con un Arduino MEGA O UNO.
*//// Variables ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int encoder_pin = 36;
int encoder_pin2 = 38;  // Pin 2, donde se conecta el encoder
unsigned int N;         // [RPM] Revoluciones por minuto calculadas.
volatile byte n;        //  [pulses]Número de pulsos leídos por el Arduino
unsigned long timeold;  // Tiempo almacenado
unsigned int S = 20;    // Número de muescas que tiene el disco del encoder.
const int wheel_diameter = 64;   // Diámetro de la rueda pequeña[mm]
float velocity = 0;              // Velocity // Velocidad en [Km/h]
/////////////////////////// Función que cuenta los pulsos del encoder ///////////////////////////////////////////////////////
void counter() {
  n++;     // Incrementa los impulsos
}

void setup() {

  //WIFI
  pinMode(50, OUTPUT); //LED
  // Habilitamos los puertos serial
  Serial.begin(9600);
  Serial1.begin(9600); // Para el modulo WiFi

  Serial.begin(9600);
  //pines MOTORES
  pinMode(ENDer, OUTPUT);
  pinMode(ENIzq, OUTPUT);
  pinMode(EN3, OUTPUT);
  pinMode(INDer1, OUTPUT);
  pinMode(INDer2, OUTPUT);
  pinMode(INIzq1, OUTPUT);
  pinMode(INIzq2, OUTPUT);
  pinMode(IN32, OUTPUT);
  pinMode(IN34, OUTPUT);

  //Pulsador y leds
  pinMode(pulsador, INPUT_PULLUP);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAzul, OUTPUT);

  //Final carrera
  pinMode(finc1, INPUT_PULLUP);
  pinMode(finc2, INPUT_PULLUP);

  //pines ojitos
  for (int i = 0; i < 5; i++) {
    pinMode (OJe[i], INPUT);
    pinMode (OJt[i], OUTPUT);
  }
  //ENCODERS
  pinMode(encoder_pin, INPUT);
  pinMode(encoder_pin2, INPUT);// Configuración del pin nº2
  attachInterrupt(0, counter, FALLING); // Configuración de la interrupción 0, donde esta conectado el encoder HC-020K. FALLING = la interrupción actua cuando la señal del pin cae : pasa de HIGH a LOW.
  // Inicialización de los parametros
  n = 0;
  N = 0;
  timeold = 0;
  /*
    Serial.println("");
    Serial.print("           Wheel  "); Serial.print("Wheel    "); Serial.println("Wheel");
    Serial.print(" Seconds   "); Serial.print("RPM    "); Serial.print("Pulses   "); Serial.println("Velocity [Km/h]");
  */

}
void loop() {
  //wifi();
  // put your main code here, to run repeatedly:
  //MotorD(178); //140 mA integrado 1 //180 vel
  //MotorI(120); //140 mA integrado 1 //120 vel
  //Motor3 (255);

  String modo = wifi();
  if (find(modo, "E")) {
    while (find(modo, "A") == false) {
      ModoRapido();
      modo = wifi();
    }
    Apaga();
    // Serial.print("Entra en modo E");
  }
  else if (find(modo, "A")) {
    // Serial.print("Entra en modo A");

  }
  else {
    Serial.print(modo);
  }
  //Escobillas(100); //180 mA integrado 2 //Ventilador(100); //300 mA integrado 3 //Tubo(100); // 210 mA integrado 2*/
  //Lectura colisiones
  //encoders();
  //FinalDeCarrera();
  //testMode();
  //ledsPulsador();
  //FinalesCarrera();
  //Avanti();
  //ModoRapido();

  bateria();

}
String wifi() {
  //delay(100); //lo necesita para leer el string.
  String message;
  if (Serial1.available() > 0) { // Si esta disponible el puerto serie del WiFi

    message = readWifiSerialMessage(); //Leemos el mensaje del WiFi
  }
  //Serial.print("serial no avalible");
  return message;
}
void ModoRapido() {
  Ojitos (OJt, OJe);
  MostrarColisiones();
  casos ();
}
void MotorI (int velocidad) {
  digitalWrite (INIzq1, LOW);
  digitalWrite (INIzq2, HIGH);
  analogWrite (ENIzq, velocidad);
  //Serial.println("Entra a motor I");
}
void MotorIAtras (int velocidad) {
  digitalWrite (INIzq1, HIGH);
  digitalWrite (INIzq2, LOW);
  analogWrite (ENIzq, velocidad);
}
void MotorD (int velocidad) {
  digitalWrite (INDer1, LOW);
  digitalWrite (INDer2, HIGH);
  analogWrite (ENDer, velocidad);
}
void MotorDAtras (int velocidad) {
  digitalWrite (INDer1, HIGH);
  digitalWrite (INDer2, LOW);
  analogWrite (ENDer, velocidad);
}
void Motor3 (int velocidad) {

  digitalWrite (IN32, LOW);
  digitalWrite (IN34, HIGH);
  analogWrite (EN3, velocidad);

}
void Apaga() {
  digitalWrite (IN32, LOW);
  digitalWrite(IN34, LOW);
  analogWrite (EN3, 0);
  digitalWrite (INDer1, LOW);
  digitalWrite (INDer2, LOW);
  analogWrite (ENDer, 0);
  digitalWrite (INIzq1, LOW);
  digitalWrite (INIzq2, LOW);
  analogWrite (ENIzq, 0);

}
int Distancia(int TriggerPin, int EchoPin) {
  double tiempo, distanciaCm;
  double relacion = 340.00 / 10000.00;

  digitalWrite(TriggerPin, LOW);
  delayMicroseconds(4);
  digitalWrite(TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);

  tiempo = pulseIn(EchoPin, HIGH);

  distanciaCm = tiempo * relacion / 2;


  return distanciaCm;
}
//Este método activa cada sensor de distancia y comprueba si tiene algo más cerca de 30 cm, si es así,
//activa
void Ojitos (int Trig[], int Echo[]) {
  for (int i = 0; i < 5; i++) {
    Serial.println(" ");
    if (Distancia(Trig[i], Echo[i]) <= 30) {
      colisiones[i] = 1;
    }
    else
      colisiones[i] = 0;
  }
  delay(15);
  Serial.println("-----------------");
}
void GiraDer (int tiempogrados) {
  MotorI (velocidadI);
  MotorDAtras (velocidadD);
  delay(tiempogrados);
  velocidad = 0;
  MotorI (velocidad);
  MotorDAtras (velocidad);
  delay(50);
}
void GiraIzq (int tiempogrados) {
  MotorIAtras (velocidadI);
  MotorD (velocidadD);
  delay(tiempogrados);
  velocidad = 0;
  MotorIAtras (velocidad);
  MotorD (velocidad);
  delay(50);
}
void Avanti () {
  Serial.println("Entra en Avanti");
  MotorI(velocidadI);
  MotorD(velocidadD);
}
void MostrarColisiones () {
  Serial.print ("Colisiones: ");
  for (int i = 0; i < 5; i++) {
    Serial.print(" - ");
    Serial.print(colisiones[i]);
  }
}
void casos () {
  FinalDeCarrera();
  Serial.println("Entra en casos");
  // 0 0 0 0 0
  if ((colisiones[0] == 0) && (colisiones[1] == 0) && (colisiones[2] == 0) && (colisiones[3] == 0) && (colisiones[4] == 0)) {
    Serial.println("Entra en 00000");
    Avanti();
    limpia();
  }
  //  0 0 1 0 0
  else if ((colisiones[0] == 0) && (colisiones[1] == 0) && (colisiones[2] == 1) && (colisiones[3] == 0) && (colisiones[4] == 0)) {
    int randomNumber = random(0, 1);
    if (randomNumber == 0) {
      GiraDer(500);
      Avanti();
    }
    else {
      GiraIzq(500);
      Avanti();
    }
  }
  //0 1 0 0 0
  else if ((colisiones[0] == 0) && (colisiones[1] == 1) && (colisiones[2] == 0) && (colisiones[3] == 0) && (colisiones[4] == 0)) {
    GiraDer(375);
    Avanti();
  }
  //0 0 0 1 0
  else if ((colisiones[0] == 0) && (colisiones[1] == 0) && (colisiones[2] == 0) && (colisiones[3] == 1) && (colisiones[4] == 0)) {
    Serial.println("00010");
    GiraIzq(375);
    Avanti();
  }
  // X 1 1 0 X
  else if ((colisiones[1] == 1) && (colisiones[2] == 1) && (colisiones[3] == 0)) {
    Serial.println("01100");
    GiraDer(400);
    Avanti();
  }
  // X 0 1 1 X
  else if ((colisiones[1] == 0) && (colisiones[2] == 1) && (colisiones[3] == 1)) {
    Serial.println("00110");
    GiraIzq(400);
    Avanti();
  }/*
  // X 1 1 1 X
  else if ((colisiones[1] == 1) && (colisiones[2] == 1) && (colisiones[3] == 1)) {
    Serial.println("01110");
    GiraIzq(1000);
    delay(300);
    Avanti();
  }*/
  //10101
  /*else if ((colisiones[0] == 1) && (colisiones[1] == 0) && (colisiones[2] == 1) && (colisiones[3] == 0) && (colisiones[4] == 1)) {
    Serial.println("10101");
    GiraDer(1000);
    delay(300);
    Avanti();
    }*/
  //10100
  else if ((colisiones[0] == 1) && (colisiones[1] == 0) && (colisiones[2] == 1) && (colisiones[3] == 0) && (colisiones[4] == 0)) {
    Serial.println("10100");
    GiraDer(500);
    Avanti();
  }
  //00101
  else if ((colisiones[0] == 0) && (colisiones[1] == 0) && (colisiones[2] == 1) && (colisiones[3] == 0) && (colisiones[4] == 1)) {
    Serial.println("00101");
    GiraIzq(500);
    Avanti();
  }
  //10000
  else if ((colisiones[0] == 1) && (colisiones[1] == 0) && (colisiones[2] == 0) && (colisiones[3] == 0) && (colisiones[4] == 0)) {
    Serial.println("10000");
    GiraDer(167);
    Avanti();
  }
  //00001
  else if ((colisiones[0] == 0) && (colisiones[1] == 0) && (colisiones[2] == 0) && (colisiones[3] == 0) && (colisiones[4] == 1)) {
    Serial.println("00001");
    GiraIzq(167);
    Avanti();
  }
  //11000
  else if ((colisiones[0] == 1) && (colisiones[1] == 1) && (colisiones[2] == 0) && (colisiones[3] == 0) && (colisiones[4] == 0)) {
    Serial.println("11000");
    GiraDer(167);
    Avanti();
  }
  //00011
  else if ((colisiones[0] == 0) && (colisiones[1] == 0) && (colisiones[2] == 0) && (colisiones[3] == 1) && (colisiones[4] == 1)) {
    Serial.println("00011");
    GiraIzq(167);
    Avanti();
  }
  else {
    /*digitalWrite (INIzq1, LOW);
    digitalWrite (INIzq2, LOW);

    digitalWrite (INDer1, LOW);
    digitalWrite (INDer2, LOW);
    delay(100);*/
    int randomNumber = random(0, 1);
    if (randomNumber == 0) {
      GiraDer(167);
      //Avanti();
    }
    else {
      GiraIzq(167);
      //Avanti();
    }
  }
}
void FinalDeCarrera() {
  Serial.println(digitalRead(finc1));
  Serial.println(digitalRead(finc2));
  if ((digitalRead(finc1) == 0) && (digitalRead(finc2) == 0)) {

    GiraIzq(500);
    //Avanti();
  }
  else if ((digitalRead(finc1) == 0) && (digitalRead(finc2) == 1)) {
    GiraDer(500);
    //Avanti();
  }
  else if ((digitalRead(finc1) == 1) && (digitalRead(finc2) == 0)) {
    int randomNumber = random(0, 1);
    if (randomNumber == 0) {
      GiraDer(500);
      //Avanti();
    }
    else {
    }
  }
}
void leds () {

}
void limpia() {
  Motor3(velocidad3);
}
void encoders () {
  if (millis() - timeold >= 1000) {  //  Se actualiza cada segundo, [t] es el tiempo de muestreo igual a 1000 milisegundos, 1 segundo.
    detachInterrupt(0);               // Desconectamos la interrupción para que no actué en esta parte del programa.
    N = ( n * 60 ) / (( millis() - timeold ) / 1000 * S );  //  N = n x 60 / (t x S) Calculamos las revoluciones por minuto [RPM]. El valor 1000 es para pasar los milisegundos a segundos
    velocity = N * 3.1416 * wheel_diameter * 60 / 1000000;  // Cálculo de la velocidad en [Km/h]
    Serial.print("   ");
    Serial.print(millis() / 1000); Serial.print("       ");
    Serial.print(N, DEC); Serial.print("      ");
    Serial.print(n, DEC); Serial.print("      ");
    Serial.println(velocity, 2);
    n = 0;               // Inicializamos los pulsos.
    timeold = millis();  // Almacenamos el tiempo actual.
    attachInterrupt(0, counter, FALLING); // Reiniciamos la interrupción
  }
}
void testMode () {
  MostrarColisiones ();
  if ((colisiones[0] == 1) && (colisiones[1] == 0) && (colisiones[2] == 0) && (colisiones[3] == 0) && (colisiones[4] == 0)) {
    MotorI(150);
    encoders ();
  }
  else if ((colisiones[0] == 0) && (colisiones[1] == 1) && (colisiones[2] == 0) && (colisiones[3] == 0) && (colisiones[4] == 0)) {
    MotorD(150);
    encoders ();
  }
  else if ((colisiones[0] == 0) && (colisiones[1] == 0) && (colisiones[2] == 1) && (colisiones[3] == 0) && (colisiones[4] == 0)) {
    Motor3(150);
  }
}
void ledsPulsador () {
  Serial.println(digitalRead(pulsador));
  if (digitalRead(pulsador) == 1) {
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledAzul, HIGH);
  }
  else {
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledAzul, LOW);
  }
}
//Conversión del analog de la batería con los equivalentes
//1024 -- 5V
//847 -- 4.14V
//711 -- 3.47V
//El indicador de batería activará los leds del botón power en función de la batería que le quede , <70%, <30%
void bateria () {
  int  voltios;

  voltios = map (analogRead(A15), 711, 847, 0, 100);

  if (millis() > TiempoLecturaT) {
    Serial1.println("a");
    Serial1.println(voltios); //manda cada x segundos el nivel de la bateria al modulo wifi
    counter1++;
    TiempoLecturaT = counter1 * TiempoLectura;
  }

  if (voltios >= 70) {
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledRojo, HIGH);
  }
  if ((voltios < 70) && (voltios > 30 )) {
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledRojo, LOW);
  }
  if (voltios <= 30) {
    digitalWrite(ledAzul, HIGH);
    digitalWrite(ledRojo, LOW);
  }
}
/*
  Nombre: find
  Descripcion: Funcion usada para comparar dos string
  Parametros: string = mensaje recibido, value = valor con el que comparar
  Devolucion: true si coincide, de lo contrario false
*/
boolean find(String string, String value) {
  if (string.indexOf(value) >= 0)
    return true;
  return false;
}
/*
  Nombre: readSerialMessage
  Descripcion: Funcion usada para leer data del Serial del Arduino.
  Parametros:
  Devolucion: Lectura de el data del Arduino (si es que existe)
*/
String  readSerialMessage() {
  char value[100];
  int index_count = 0;
  while (Serial.available() > 0) {
    value[index_count] = Serial.read();
    index_count++;
    value[index_count] = '\0'; // 0 termina el String
  }
  String str(value);
  str.trim();
  return str;
}
/*
  Nombre: readWifiSerialMessage
  Descripcion: Funcion usada para leer data del Serial del WiFi.
  Parametros:
  Devolucion: Lectura de el data del WiFi (si es que existe)
*/
String  readWifiSerialMessage() {
  char value[100];
  int index_count = 0;
  while (Serial1.available() > 0) {
    value[index_count] = Serial1.read();
    index_count++;
    value[index_count] = '\0'; // 0 termina el String
  }
  String str(value);
  str.trim();
  return str;
}
/*
  Nombre: sendToWifi
  Descripcion: Funcion usada para enviar data al WiFi y esperar respuesta
  Parametros: command - el data o comando a enviar; timeout - el tiempo de espera a respuesta; debug - imprime en la pantalla de Serial?(true = si, false = no)
  Devolucion: La respuesta del WiFi (si es que existe)
*/
String sendToWifi(String command, const int timeout, boolean debug) {
  String response = "";
  Serial1.println(command); // Envia el data al esp8266
  long int time = millis();
  while ( (time + timeout) > millis())
  { //Espera a respuesta
    while (Serial1.available())
    {
      // Lee la respuesta
      char c = Serial1.read();// Lee el siguiente caracter.
      response += c;
    }
  }
  if (debug)
  { // Imprime la respuesta
    Serial.println(response);
  }
  return response;// Devuelve la respuesta
}

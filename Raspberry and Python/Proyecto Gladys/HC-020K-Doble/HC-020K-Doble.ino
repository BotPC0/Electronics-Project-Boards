/* Programa que cuenta los pulsos y las revoluciones del encoder foto eléctrico HC-020K con un Arduino MEGA O UNO.
*//// Variables ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int encoder_pinI = 2;    // Pin 2, donde se conecta el encoder
int encoder_pinD = 3;    // Pin 2, donde se conecta el encoder


unsigned int NI;         // [RPM] Revoluciones por minuto calculadas.
unsigned int ND;         // [RPM] Revoluciones por minuto calculadas.

volatile byte nI;        //  [pulses]Número de pulsos leídos por el Arduino
volatile byte nD;        //  [pulses]Número de pulsos leídos por el Arduino

unsigned long timeold;  // Tiempo almacenado
unsigned int S = 20;    // Número de muescas que tiene el disco del encoder.
const int wheel_diameter = 64;   // Diámetro de la rueda pequeña[mm]

float velocityI = 0;              // Velocity // Velocidad en [Km/h]
float velocityD = 0;              // Velocity // Velocidad en [Km/h]

/////////////////////////// Función que cuenta los pulsos del encoder ///////////////////////////////////////////////////////
void counterI() {
  nI++;     // Incrementa los impulsos
}
void counterD() {
  nD++;     // Incrementa los impulsos
}
//// Configuración del Arduino ////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);           // Configuración del puerto serie
  pinMode(encoder_pinI, INPUT);  // Configuración del pin nº2
  attachInterrupt(0, counterI, FALLING); // Configuración de la interrupción 0, donde esta conectado el encoder HC-020K. FALLING = la interrupción actua cuando la señal del pin cae : pasa de HIGH a LOW.
  pinMode(encoder_pinD, INPUT);  // Configuración del pin nº2
  attachInterrupt(1, counterD, FALLING); // Configuración de la interrupción 0, donde esta conectado el encoder HC-020K. FALLING = la interrupción actua cuando la señal del pin cae : pasa de HIGH a LOW.
  // Inicialización de los parametros
  nI = 0;
  nD = 0;
  NI = 0;
  ND = 0;
  timeold = 0;
  Serial.println("");
  Serial.print("           Wheel  "); Serial.print("Wheel    "); Serial.println("Wheel");
  Serial.print(" Seconds   "); Serial.print("RPM    "); Serial.print("Pulses   "); Serial.println("Velocity [Km/h]");
}
//// Programa principal /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  if (millis() - timeold >= 1000) {  //  Se actualiza cada segundo, [t] es el tiempo de muestreo igual a 1000 milisegundos, 1 segundo.
    detachInterrupt(0);               // Desconectamos la interrupción para que no actué en esta parte del programa.
    detachInterrupt(1);               // Desconectamos la interrupción para que no actué en esta parte del programa.

    NI = ( nI * 60 ) / (( millis() - timeold ) / 1000 * S );  //  N = n x 60 / (t x S) Calculamos las revoluciones por minuto [RPM]. El valor 1000 es para pasar los milisegundos a segundos
    ND = ( nD * 60 ) / (( millis() - timeold ) / 1000 * S );  //  N = n x 60 / (t x S) Calculamos las revoluciones por minuto [RPM]. El valor 1000 es para pasar los milisegundos a segundos
    velocityI = NI * 3.1416 * wheel_diameter * 60 / 1000000;  // Cálculo de la velocidad en [Km/h]
    velocityD = ND * 3.1416 * wheel_diameter * 60 / 1000000;  // Cálculo de la velocidad en [Km/h]
    Serial.print("   ");
    Serial.print(millis() / 1000); Serial.print("       ");
    Serial.print(NI, DEC); Serial.print("      ");
    Serial.print(nI, DEC); Serial.print("      ");
    Serial.println(velocityI, 2);
    Serial.print("   ");
    Serial.print(millis() / 1000); Serial.print("       ");
    Serial.print(ND, DEC); Serial.print("      ");
    Serial.print(nD, DEC); Serial.print("      ");
    Serial.println(velocityD, 2);
    nI = 0;               // Inicializamos los pulsos.
    nD = 0;               // Inicializamos los pulsos.

    timeold = millis();  // Almacenamos el tiempo actual.

    attachInterrupt(0, counterI, FALLING); // Reiniciamos la interrupción
    attachInterrupt(1, counterD, FALLING); // Reiniciamos la interrupción

  }
}
//// Final del programa principal ////////////////////////////////////////////////////////////////////////////////////////////////////

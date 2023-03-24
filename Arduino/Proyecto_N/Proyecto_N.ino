// Librerias I2C para controlar el mpu6050
// la libreria MPU6050.h necesita I2Cdev.h, I2Cdev.h necesita Wire.h
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

// La dirección del MPU6050 puede ser 0x68 o 0x69, dependiendo
// del estado de AD0. Si no se especifica, 0x68 estará implicito
MPU6050 sensor;

// Valores RAW (sin procesar) del acelerometro y giroscopio en los ejes x,y,z
int ax, ay, az;
int gx, gy, gz;

// array de valores convertidos en las unidades predeterminadas
float a[3]; //[m/s^2]
float g[3]; //[grados/s]

float at[3]; //suma de aceleraciones en intervalo x
float gt[3]; //suma de grados totales para calcular orientacion aplicado a intervalo x

float aa[3]; //valor absoluto para simplificar el if y servir de filtro
float DistanciaRecorrida[3]; //sirve para calcular DistanciaRecorridaT
float DistanciaRecorridaT; //distancia recorrida en linea recta

float Distancia[3]; //distancia recorrida en todos los ejes
float Angulo[3]; //Angulo que ha girado
float dt = 0.1;

const float pi = 3.14; //valor del numero pi
float alfa; //angulo que sirve para calcular la funcion inversa del contador

float errorAx = 0.38; // Filtro para el eje x
float errorAy = 0.3;  // Filtro para el eje y
float errorAz = 0.1;  // Filtro para el eje z

float ang_x_prev, ang_y_prev; //sirven para guardar el anguno del giroscopio anterior para calcular el siguiente y haya continuidad

byte estado = 0; //bit de estado para saber si restablecer el contador
byte estado1 = 0; //bit de estado para saberi si iniciar el
float f1, f2; //sirven para dimensionar las unidades, f1 para "a" y f2 para "g"
int contador = 0; //cuenta los ciclos para calcular Vo
float contadorT = 0; //sirve para dimensionar contador
float Vo; //velocidad incial
long tiempo_prev, dt1; //sirve para la funcion millis() y calcular dt

// pines del dector de distancia
const int EchoPin = 50;
const int TriggerPin = 52;

// pines del LED
const int LedPin = 8;

float Objeto[20][3]; //matriz de objetos
byte ObjetosGuardados = -1; //cantidad de objetos guardados

String Ejes[3] = {"eje x= ", "eje y= ", "eje z= "}; //sirve para imprimir por pantalla

void setup() {
  Serial.begin(57600);    //Iniciando puerto serial para valores del sensor MPU
  Wire.begin();           //Iniciando I2C
  sensor.initialize();    //Iniciando el sensor
  calibracion(); //Calibracion del MPU

  if (sensor.testConnection()) Serial.println("Sensor iniciado correctamente");
  else Serial.println("Error al iniciar el sensor");

  pinMode(TriggerPin, OUTPUT); //Conexiones del sensor de proximidad
  pinMode(EchoPin, INPUT);

  pinMode(LedPin, OUTPUT);//Conexion del LED

}

void loop() {
  tiempo_prev = millis();

  // Leer las aceleraciones y velocidades angulares
  sensor.getAcceleration(&ax, &ay, &az);
  sensor.getRotation(&gx, &gy, &gz);



  f1 = 9.81 / 16384.0;
  f2 = 250.0 / 32768.0;



  a[0] = ax * (f1); // 9.81/16384.0
  a[1] = ay * (f1);
  a[2] = az / 16384.0 - 1;
  g[0] = gx * (f2); // 250.0/32768.0
  g[1] = gy * (f2);
  g[2] = gz * (f2);


 /* 
 //Sirve para imprimir los valores que recibe el sensor
  Serial.print("a[x y z](m/s2) g[x y z](deg/s):\t");
  Serial.print(a[0]); Serial.print("\t");
  Serial.print(a[1]); Serial.print("\t");
  Serial.print(a[2]); Serial.print("\t");
  Serial.print(g[0]); Serial.print("\t");
  Serial.print(g[1]); Serial.print("\t");
  Serial.println(g[2]); 
  */

  for (int i = 0; i <= 2; i++) {
    aa[i] = abs(a[i]); //Calcula el valor absoluto para el error, se puede llamar low pass filter, ya que high pass filter no tenemos en el calculo de la aceleracion
  }


  if (aa[0] > errorAx) {
    at[0] = a[0] + at[0];
    //Serial.print("ax = ");
    //Serial.print(at[0]); Serial.print("\t");
    estado = 1;
  }

  if (aa[1] > errorAy) {
    at[1] = a[1] + at[1];
    //Serial.print("ay = ");
    //Serial.print(at[1]); Serial.print("\t");
    estado = 1;
  }

  if (aa[2] > errorAz) {
    at[2] = a[2] + at[2];
    //Serial.print("az = ");
    //Serial.print(at[2]); Serial.print("\t");
    estado = 1;
  }


  if ((aa[0] < errorAx) && (aa[1] < errorAy) && (aa[2] < errorAz)) { //Realizar suma total en metros

    delay(45);

    if (estado == 1) { //situa el contador a 0 para que empieze a contar y cambia el valor de estado a 0
      estado = 0;
      contador = 0;
      for (int i = 0; i <= 2; i++) {
        DistanciaRecorrida[i] = sq(Distancia[i] - (at[i] * dt * dt));
      }
      DistanciaRecorridaT = sqrt(DistanciaRecorrida[0] + DistanciaRecorrida[1] + DistanciaRecorrida[2]); //Distancia recorrida en linea recta

    }


    contador = contador + 1;
    contadorT = contador * 0.25;
    alfa = (pi * contadorT) / 2; //sirve para sacar la funcion inversa del contador

    if ((contadorT > 0) && (contadorT < 1)) {
      // si el contador no llega a x segundos considera la velocidad inicial en el calculo de la distancia, como forma aproximada
      for (int i = 0; i <= 2; i++) {
        Distancia[i] = at[i] * dt * (dt +  cos(alfa)); //distancia en metros
      }
    }

    if (contadorT > 1) {
      // el contador supera el tiempo del contador y se reinicia el calculo de la distancia y aceleracion considerando que el objeto se ha parado
      Vo = 0;
      for (int i = 0; i <= 2; i++) {
        at[i] = 0; //distancia en metros
      }
    }


  }

  //Calcular los ángulos con acelerometro
  float accel_ang_x = atan(ay / sqrt(pow(ax, 2) + pow(az, 2))) * (180.0 / pi);
  float accel_ang_y = atan(-ax / sqrt(pow(ay, 2) + pow(az, 2))) * (180.0 / pi);

  //Calcular angulo de rotación con giroscopio y filtro complemento
  Angulo[0] = 0.98 * (ang_x_prev + g[0] * dt) + 0.02 * accel_ang_x;
  Angulo[1] = 0.98 * (ang_y_prev + g[1] * dt) + 0.02 * accel_ang_y;

  //Guarda el valor del angulo para sumarlo al siguiente y tener continuidad
  ang_x_prev = Angulo[0];
  ang_y_prev = Angulo[1];

  //Para calcular el tiempo dt
  dt = (millis() - tiempo_prev) / 1000.0;
  tiempo_prev = millis();
  // Serial.print(dt); se puede imprimir para ver el tiempo que se utiliza si se desea, esta alrededor de 0.05



  int cm = ping(TriggerPin, EchoPin); //funcion que llama al sensor de proximidad



  while (cm < 5) {

    if ((Objeto[ObjetosGuardados][0] == Distancia[0]) && (Objeto[ObjetosGuardados][1] == Distancia[1]) && (Objeto[ObjetosGuardados][2] == Distancia[2])) {
//Sirve para ver si se ha guardado este objeto antes o no. Si es el mismo de antes omite la impresion de resultados
      break;
    }

    Serial.print("Obejeto delante, Peligro, Objeto Nº:");

    digitalWrite(LedPin, HIGH);

    if (ObjetosGuardados == 20) { //si llega a la capacidad maxima de memoria que en nuestro caso son 21 obejetos, se reinicia para sobreescribir la primera linea
      ObjetosGuardados = -1;
    }

    ObjetosGuardados = ObjetosGuardados + 1;
    for (int j = 0; j < 3; j++) {
      Objeto[ObjetosGuardados][j] = Distancia[j];
    }
    Serial.println(ObjetosGuardados);
    Serial.println("      ANGULO...DISTANCIA...DISTANCIA RECORRIDA  ");
    for (int i = 0; i <= 2; i++) { //Imprime por pantalla los valores
      Serial.print(Ejes[i]); Serial.print("\t");
      Serial.print(Angulo[i]); Serial.print("\t");
      Serial.print(Distancia[i]); Serial.print("\t");
      Serial.print(DistanciaRecorridaT); Serial.println("\t");
    }

    delay(1000);
    digitalWrite(LedPin, LOW);
    cm = ping(TriggerPin, EchoPin);
  }




  /*
    //Mostrar las lecturas separadas por un [tab]
    Serial.print("a[x y z](m/s2) g[x y z](deg/s):\t");
    Serial.print(a[0]); Serial.print("\t");
    Serial.print(a[1]); Serial.print("\t");
    Serial.print(a[2]); Serial.print("\t");
    Serial.print(g[0]); Serial.print("\t");
    Serial.print(g[1]); Serial.print("\t");
    Serial.println(g[2]);

    delay(100);

  */

}


int ping(int TriggerPin, int EchoPin) { //Funcion del detector de distancia
  long duration, distanceCm;

  digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
  delayMicroseconds(4);
  digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);

  duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos

  distanceCm = duration * 10 / 292 / 2;  //convertimos a distancia, en cm
  return distanceCm;
}

void calibracion() {

  sensor.setXAccelOffset(198);
  sensor.setYAccelOffset(-1270);
  sensor.setZAccelOffset(808);

  sensor.setXGyroOffset(-214);
  sensor.setYGyroOffset(-7);
  sensor.setZGyroOffset(-25);

}



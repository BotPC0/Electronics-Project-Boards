/*   Ejemplo de control de motor DC usando  L293D con entrada analógica   */

const int IN1 = 5;    // Input1 conectada al pin 5
const int IN2 = 4;    // Input2 conectada al pin 4
const int ENA = 11;    // ENA conectada al pin 11 de Arduino señal PWM const
int VELOCIDAD = A1;

int velocidad = 0;

void setup() {
  pinMode (ENA, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  Serial.begin(9600);
}

void loop() { //Preparamos la salida para que el motor gire en un sentido
  digitalWrite (IN1, 0);
  digitalWrite (IN2, 1);
  /* Aplicamos PWM al pin ENA, mediante el valor del potenciometro
    (entrada analogica 10bits- salida digital 8 bits por eso dividir 4*/
  velocidad = analogRead(VELOCIDAD);
  velocidad = velocidad / 4;
  Serial.println("la velocidad del motor es:");
  Serial.print(velocidad);
  analogWrite(ENA, velocidad);
  delay(3000);
}

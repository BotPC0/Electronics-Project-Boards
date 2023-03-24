/*   Ejemplo de control de motor DC usando  L293D con entrada analógica   */

const int IN1 = 5;    // Input1 conectada al pin 5
const int IN2 = 4;    // Input2 conectada al pin 4
const int ENA = 11;    // Enable A conectada al pin 11 
int VELOCIDAD = A1; // Salida del Potenciometro conectado al pin A1

const int IN3 = 6;   // Input 3
const int IN4 = 7;   // Input 4 
const int ENB = 12;  // Enable B

int velocidad = 0;

void setup() {
  pinMode (ENA, OUTPUT);
  // pinMode (IN1, OUTPUT);
  // pinMode (IN2, OUTPUT);
  Serial.begin(9600);
}

void loop() { //Preparamos la salida para que el motor gire en un sentido
  // digitalWrite (IN1, HIGH);
  // digitalWrite (IN2, LOW);
  /* Aplicamos PWM al pin ENA, mediante el valor del potenciometro
    (entrada analogica 10bits- salida digital 8 bits por eso dividir 4*/
  velocidad = analogRead(VELOCIDAD);
  velocidad = velocidad / 4;
  Serial.println("la velocidad de los motores son:");
  Serial.print(velocidad);
  analogWrite(ENA, velocidad);
  analogWrite(ENB, velocidad);
  delay(3000);
}

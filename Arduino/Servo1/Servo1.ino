#include <Servo.h>

Servo yeah;

const int Pulsador = 2;
const int LED = 3;

int value = 0;
int pos = 1;
int x = 0;
int p = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Pulsador, INPUT);
  pinMode(LED, OUTPUT);
  yeah.attach(9);
}

void inicio() {
  pos = 0;
  yeah.write(pos);
}



void loop() {


  if (p == 0) {
    inicio();
  }

  value = digitalRead(Pulsador);
  pos = yeah.read();


  if (pos == 0) {
    x = 15;
    pos = 1;
    digitalWrite(LED, HIGH);
    Serial.print("Alerta");
    delay(200);
  }

  if (pos == 180) {
    x = -15;
    pos = 179;
    digitalWrite(LED, HIGH);
    delay(200);
  }

  digitalWrite(LED, LOW);

  Serial.print(pos);

  if ((value == HIGH) && (pos < 180) && (pos > 0)) {
    Serial.println("Encendido");
    yeah.write(pos + x);
    pos = yeah.read();

    delay(500);
    Serial.println(pos);

  }

  p++;

  delay(150);


}

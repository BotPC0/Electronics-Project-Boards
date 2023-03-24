
#include <Servo.h>

Servo servo1;


void setup() {
  servo1.attach(2);
  Serial.begin(9600);
}

void loop() {
  int numero = random(0, 181);
  servo1.write(numero);
  Serial.println(numero);
  delay(1000);
}

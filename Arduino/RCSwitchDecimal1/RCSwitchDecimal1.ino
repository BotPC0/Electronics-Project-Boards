
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

const int EchoPin = 2;
const int TriggerPin = 3;

void setup() {
  mySwitch.enableTransmit(9);
  Serial.begin(9600);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() {
  int cm = ping(TriggerPin, EchoPin);
  Serial.print("Distancia: ");
  Serial.println(cm);
  if (cm <= 30 and cm > 15) {
    mySwitch.send(11, 24);
  }
  else if (cm <= 15) {
    mySwitch.send(22, 24);
  }
  else {
    mySwitch.send(33, 24);
    delay(500);
  }
  delay(500);
}

int ping(int TriggerPin, int EchoPin) {
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

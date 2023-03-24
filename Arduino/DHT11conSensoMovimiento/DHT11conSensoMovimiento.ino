#include <DHT11.h>

const int DHTPin = 9;
DHT11 dht11(DHTPin);

const int PIRPin = 2;

const int R = 3;
const int G = 4;
const int B = 5;

const int EchoPin = 7;
const int TriggerPin = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(PIRPin, INPUT);

  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int value = digitalRead(PIRPin);

  if (value == HIGH)
  {
    float h, t;
    int err;
    err = dht11.read(h, t);

    if (err != 0) {
      Serial.print("Error Num :");
      Serial.print(err);
    }

    int cm = ping(TriggerPin, EchoPin);

    int R1 = cm;
    int G1 = t;
    int Bb = h;

    analogWrite(R, R1);
    delay(500);
    Serial.print("Distancia: ");
    Serial.println(R1);

    analogWrite(G, G1);
    delay(500);
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" *C ");

    analogWrite(B, Bb);
    delay(500);
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.println(" %\t");
  }
  
delay(2000);

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

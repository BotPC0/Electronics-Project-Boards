#include <DHT11.h>

int PinSensor = 8;
float humedad, temperatura;
int LED = 9;

DHT11 sensor(PinSensor);

void setup() {
  // put your setup code here, to run once:
  pinMode(PinSensor, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  sensor.read(humedad, temperatura);

  Serial.println(temperatura);
  Serial.println(humedad);

  if ((temperatura > 27) || (humedad > 40)) {
    digitalWrite(LED, HIGH);
  }
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);

}

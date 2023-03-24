int PinEcho = 2;
int PinTrigger = 3;
int PinMovimiento = 4;
long Dist;

long Distance() {
  long tiempo, distancia;
  digitalWrite(PinTrigger, LOW);
  delayMicroseconds(4);
  digitalWrite(PinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(PinTrigger, LOW);
  tiempo = pulseIn(PinEcho, HIGH);
  distancia = tiempo * 10 / 292 / 2;
  return distancia;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(PinEcho, INPUT);
  pinMode(PinTrigger, OUTPUT);
  pinMode(PinMovimiento, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(PinMovimiento) == HIGH) {
    Dist = Distance();
    Serial.print("Distancia:");
    Serial.println(Dist);
  }
  delay(500);

}

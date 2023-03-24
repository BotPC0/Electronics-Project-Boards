int LDR = A0;
int LUZ = 0;
int LED = 9;
int INTENSIDAD = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LDR, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  LUZ = analogRead(LDR);

  INTENSIDAD = map(LUZ, 0, 1023, 0, 255);

  analogWrite(LED, 255-INTENSIDAD);

  Serial.println(255-INTENSIDAD);
  delay(200);
}

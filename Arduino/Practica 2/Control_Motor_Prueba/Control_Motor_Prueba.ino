
const int MotorDAdelante = 13;
const int MotorLAdelante = 12;
const int MotorDAtras = 11;
const int MotorLAtras = 10;
int x = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(MotorDAdelante, OUTPUT);
  pinMode(MotorLAdelante, OUTPUT);
  pinMode(MotorDAtras, OUTPUT);
  pinMode(MotorLAtras, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(MotorLAdelante, 60);
  digitalWrite(MotorDAdelante, LOW);
  digitalWrite(MotorLAtras, LOW);
  digitalWrite(MotorDAtras, LOW);
  Serial.write("Adelante");
  delay(2000);
  digitalWrite(MotorLAdelante, LOW);
  delay(5000);
  analogWrite(MotorLAtras, 120);
  Serial.write("Atras");
  delay(2000);
  digitalWrite(MotorLAtras, LOW);
  delay(5000);

}

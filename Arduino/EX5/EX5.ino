void setup() {
  // put your setup code here, to run once:

pinMode(13, OUTPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


int numero = random(0,255);

analogWrite(13,numero);

Serial.println(numero);

delay(200);



}

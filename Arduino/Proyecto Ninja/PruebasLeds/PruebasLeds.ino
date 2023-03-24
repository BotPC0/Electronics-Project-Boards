int leds[18] =   {39, 40, 41, 44, 3, 2, 10, 9, 8, 36, 37, 38, 7, 6, 5, 13, 12, 11};

void setup() {
  // put your setup code here, to run once:
  for (int i = 13; i < 2; i--) {
    pinMode(i, OUTPUT);
  }
  for (int i = 36; i < 41; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(12, 255);
  delay(1000);
}
//39=R 40=G 41=B HABITACION
//44=R 3=G 2=B  BAÑO
//10=R 9=G 8=B COCINA
//36=R 37=G 38=B SALON
//7=R 6=G 5=B PASILLO
//13=R

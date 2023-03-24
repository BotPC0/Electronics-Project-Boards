byte numeros[10][7] = {
// a  b  c  d  e  f  g
  {1, 1, 1, 1, 1, 1, 0}, //0
  {0, 1, 1, 0, 0, 0, 0}, //1
  {1, 1, 0, 1, 1, 0, 1}, //2
  {1, 1, 1, 1, 0, 0, 1}, //3
  {0, 1, 1, 0, 0, 1, 1}, //4
  {1, 0, 1, 1, 0, 1, 1}, //5
  {0, 0, 1, 1, 1, 1, 1}, //6
  {1, 1, 1, 0, 0, 0, 0}, //7
  {1, 1, 1, 1, 1, 1, 1}, //8
  {1, 1, 1, 1, 0, 1, 1} //9
};

byte led[7] = {22, 24, 26, 28, 30, 32, 34};


void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i <= 6; i++) {
    pinMode(led[i], OUTPUT);
  }
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int j = 0; j <= 9; j++) {
Serial.print(" Numero:");
    for (int i = 0; i <= 6; i++) {
      digitalWrite(led[i], numeros[j][i]);
      delay(10);
      
      Serial.print(numeros[j][i]);
    }
    delay(1000);
  }

}

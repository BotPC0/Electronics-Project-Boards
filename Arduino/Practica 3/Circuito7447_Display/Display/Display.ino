byte numeros[17][7] = {
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
  {1, 1, 1, 1, 0, 1, 1}, //9
  {0, 0, 0, 1, 1, 0, 1}, //10(c)
  {0, 0, 1, 1, 0, 0, 1}, //11(c inversa)
  {0, 1, 0, 0, 0, 1, 1}, //12(u)
  {1, 0, 0, 1, 0, 1, 1}, //13
  {0, 0, 0, 1, 1, 1, 1}, //14
  {0, 0, 0, 0, 0, 0, 0}, //15(blanco)
  {1, 1, 1, 1, 1, 1, 1} //16 LT
};
//1, 2, 4, 8, LT, BI, RBI
const int Pulsador_IN[7] = {2, 3, 4, 5, 6, 22, 23};
int estado[7];
int j = 0;
byte pinRBO = 24;

byte led[7] = {13, 12, 11, 10, 9, 8, 7};


void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i <= 6; i++) {
    pinMode(led[i], OUTPUT);
  }
  for (int i = 0; i < 4; i = i + 1) {
    pinMode(Pulsador_IN[i], INPUT);
  }
  pinMode(pinRBO, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < 7; i = i + 1) {
    estado[i] = digitalRead(Pulsador_IN[i]);
  }

  j = BinarioDecimal(estado[0], estado[1], estado[2], estado[3]);

  if (estado[5] == 0) {
      digitalWrite(pinRBO, HIGH);
    for (int i = 0; i <= 6; i++) {
      digitalWrite(led[i], numeros[15][i]);
      delay(10);
    }

  }
  else if (estado[6] == 0 and j == 0 and estado[4] == 1) {

    digitalWrite(pinRBO, LOW);

    for (int i = 0; i <= 6; i++) {
      digitalWrite(led[i], numeros[15][i]);
      delay(10);
    }

  }

  else if (estado[4] == 0 and estado[5] == 1) {

    for (int i = 0; i <= 6; i++) {
      digitalWrite(led[i], numeros[16][i]);
      delay(10);
    }
    digitalWrite(pinRBO, HIGH);
  }

  else {
    for (int i = 0; i <= 6; i++) {
      digitalWrite(led[i], numeros[j][i]);
      delay(10);
    }
    digitalWrite(pinRBO, HIGH);
  }
}


int BinarioDecimal(int x1, int x2, int x3, int x4) {
  int z = x1 + 2 * x2 + 4 * x3 + 8 * x4;
  return z;
}


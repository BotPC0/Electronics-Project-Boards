const int Pulsador_IN[6] = {2, 3, 4, 5, 6, 7};
const int XOR_OUT = 11;
const int NOR_OUT = 9;
const int NAND_OUT = 10;
int estado[6];

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 6; i = i + 1) {
    pinMode(Pulsador_IN[i], INPUT);
  }
  pinMode(XOR_OUT, OUTPUT);
  pinMode(NAND_OUT, OUTPUT);
  pinMode(NOR_OUT, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 6; i = i + 1) {
    estado[i] = digitalRead(Pulsador_IN[i]);
  }

  NOR(estado[0], estado[1]);
  NAND(estado[2], estado[3]);
  XOR(estado[4], estado[5]);

}

void XOR(int x1, int x2) {
  if (x1 == 0 && x2 == 0) {
    digitalWrite(XOR_OUT, LOW);
  }
  else if (x1 == 1 && x2 == 1) {
    digitalWrite(XOR_OUT, LOW);
  }
  else {
    digitalWrite(XOR_OUT, HIGH);
  }
}

void NAND(int x1, int x2) {
  if (x1 == 1 && x2 == 1 ) {
    digitalWrite(NAND_OUT, LOW);
  }
  else {
    digitalWrite(NAND_OUT, HIGH);
  }
}

void NOR(int x1, int x2) {
  if (x1 == 0 && x2 == 0 ) {
    digitalWrite(NOR_OUT, HIGH);
  }
  else {
    digitalWrite(NOR_OUT, LOW);
  }
}

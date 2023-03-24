byte salidas[16][5] = {
  //A1 D0 C0 B0 A0
  { 0, 0, 0, 0, 0}, //0
  { 0, 0, 0, 0, 1}, //1
  { 0, 0, 0, 1, 0}, //2
  { 0, 0, 0, 1, 1}, //3
  { 0, 0, 1, 0, 0}, //4
  { 0, 0, 1, 0, 1}, //5
  { 0, 0, 1, 1, 0}, //6
  { 0, 0, 1, 1, 1}, //7
  { 0, 1, 0, 0, 0}, //8
  { 0, 1, 0, 0, 1}, //9
  { 1, 0, 0, 0, 0}, //10
  { 1, 0, 0, 0, 1}, //11
  { 1, 0, 0, 1, 0}, //12
  { 1, 0, 0, 1, 1}, //13
  { 1, 0, 1, 0, 0}, //14
  { 1, 0, 1, 0, 1}  //15
};

const byte PinSalida[6] =
//A1 D0  C0  B0  A0 BI
{13, 12, 11, 10, 9, 8}; //salidas

const int Pulsador_IN[6] = {2, 3, 4, 5, 6, 7};
int estado[6];


void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 6; i = i + 1) {
    pinMode(Pulsador_IN[i], INPUT);
  }
  for (int i = 0; i < 6; i++) {
    pinMode(PinSalida[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < 6; i = i + 1) {
    estado[i] = digitalRead(Pulsador_IN[i]);
  }

  int j = BinarioDecimal(estado[0], estado[1], estado[2], estado[3]);

if (j<10){
  digitalWrite(PinSalida[5], LOW);
  
  for (int i = 0; i < 5; i++) {
    digitalWrite(PinSalida[i], salidas[j][i]);
  }
}
else{
  digitalWrite(PinSalida[5], HIGH);
   for (int i = 0; i < 5; i++) {
    digitalWrite(PinSalida[i], salidas[j][i]);
  }
  }
  delay(50);
  
}


int BinarioDecimal(int x1, int x2, int x3, int x4) {
  int j = x1 + 2 * x2 + 4 * x3 + 8 * x4;
  return j;
}


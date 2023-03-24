byte led[7] = {52, 50, 48, 46, 44, 42, 40};
byte numeros[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1},
  {1, 1, 1, 1, 0, 0, 1},
  {0, 1, 1, 0, 0, 1, 1},
  {1, 0, 1, 1, 0, 1, 1},
  {1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1}
};
int x = 0;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i <= 6; i++) {
    pinMode(led[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int numero = random(0, 10);

  while (numero > 0) {
    numero = numero - 2;
  }

  numero = numero + 2;

  if (numero == 0) {


    for (int j = 0; j <= 4; j++) {

      for (int i = 0; i <= 6; i++) {


        digitalWrite(led[i], numeros[x][i]);
        delay(10);
      }

    }



    if (numero == 1) {

    }




    delay(1000);
  }

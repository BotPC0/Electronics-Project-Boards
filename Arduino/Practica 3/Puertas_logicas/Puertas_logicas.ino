const int Pulsador_IN[6]={2,3,4,5,6,7};
const int OR_OUT=11;
const int INVERSOR_OUT=9;
const int AND_OUT=10;
int estado[6];

void setup() {
  // put your setup code here, to run once:
for (int i = 0; i < 6; i = i + 1) {
  pinMode(Pulsador_IN[i], INPUT); 
}
pinMode(OR_OUT, OUTPUT);
pinMode(AND_OUT, OUTPUT);
pinMode(INVERSOR_OUT, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for (int i = 0; i < 6; i = i + 1) {
  estado[i]=digitalRead(Pulsador_IN[i]); 
}

INVERSOR(estado[0]);
AND(estado[1], estado[2]);
OR(estado[3], estado[4]);

}

void OR(int x1,int x2){
   if (x1 ==1 || x2 ==1 ){
    digitalWrite(OR_OUT,HIGH);
  }
else{
  digitalWrite(OR_OUT,LOW);
  }
}

void AND(int x1,int x2){
   if (x1 ==1 && x2 ==1 ){
    digitalWrite(AND_OUT,HIGH);
  }
else{
  digitalWrite(AND_OUT,LOW);
  }
}

void INVERSOR(int x1){
   if (x1 ==1){
    digitalWrite(INVERSOR_OUT,LOW);
  }
else{
  digitalWrite(INVERSOR_OUT,HIGH);
  }
}

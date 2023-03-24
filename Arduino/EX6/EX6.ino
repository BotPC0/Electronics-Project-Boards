int s=0;
int r=0;
int m=0;

int suma(int a,int b){ 
int x=0;
x=a+b;
 Serial.print("suma= ");
Serial.println(x);
return x;
}

int resta(int a,int b){
  int x=0;
  x=a-b;
   Serial.print("resta= ");
Serial.println(x);
  return x;
  }
  
int multiplicacion(int a,int b){
  int x=0;
  x=a*b;
  Serial.print("multiplicacion= ");
  Serial.println(x);
  return x;
}

void setup() {

int Pines[] = {10, 11, 3}; //Pin 10 = Led Rojo ; Pin 11 = Led Verde ; Pin 3 = Pin de Zumbador 

Serial.begin(9600);

for (int i=0; i <= 2; i++){
  
      pinMode(Pines[i], OUTPUT);
   }
   
}

void loop() {
int R=0;

int a = random(0,5);
int b = random(0,5);

s=suma(a, b);
delay(500);

r=resta(a,b);
delay(500);

m=multiplicacion(a,b);
delay(500);

R = r % 2;  //Resto


if ((a==b)&&(s!=8))
{
   digitalWrite(10, HIGH);
   delay(500);
    digitalWrite(10, LOW);
}

else if (s>7)
{
digitalWrite(11, HIGH);
delay(500);
digitalWrite(11, LOW);
 }
 
else if (R==0)
{
  analogWrite(3, 50);
  delay(2000);
  analogWrite(3, 0);
}

else
{
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
   analogWrite(3, 0);
}


}

int x=0;

void setup() {
  // put your setup code here, to run once:

pinMode(7, OUTPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


int numero = random(0,10);

x = numero % 2;

Serial.println(numero);
delay(500);

if(x==0){
  digitalWrite(7,HIGH);
  }

  else{
    digitalWrite(7,LOW);
    
    }

}

int Pintrigger = 2;
int Pinecho = 3;
float Dt = 0;
float r = 0;
float Dx = 0;

void setup() {
  // put your setup code here, to run once:
  
pinMode(Pintrigger, OUTPUT);
pinMode(Pinecho, INPUT);

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  

Dx=Distancia();


}

float Distancia(){
  
digitalWrite(Pintrigger,HIGH);

delayMicroseconds(10);

digitalWrite(Pintrigger,LOW);

Dt = pulseIn(Pinecho, HIGH, 60000.0);

r = (Dt*34.0)/2000.0; //cm

Serial.println(r);

delay(1000);

return(r);

  }


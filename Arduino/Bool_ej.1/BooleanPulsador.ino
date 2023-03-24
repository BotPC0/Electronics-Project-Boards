bool a=false;
bool b=false;
bool x=false;
int Pulsador1=9;
int Pulsador2=8;
int LED=7;

bool stat(bool a,bool b) {
  
bool c = a^b;

return c;
  
  }

void setup() {
  // put your setup code here, to run once:
    pinMode(Pulsador1, INPUT);
    pinMode(Pulsador2, INPUT);
    pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  a=digitalRead(Pulsador1);
  b=digitalRead(Pulsador2);
  
x = stat(a,b);
digitalWrite(LED,x);
delay(100);

}



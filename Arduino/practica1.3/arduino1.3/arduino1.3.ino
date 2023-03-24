int LedV = 13;   
int LedR = 7;     
int Pulsador = 2;
int x = 0;      
int y=0;
void setup()
{
Serial.begin(9600);

  
  pinMode(LedV, OUTPUT);
  pinMode(LedR, OUTPUT);
  pinMode(Pulsador, INPUT);       
}

void loop(){

x = digitalRead(Pulsador);

 if (x==HIGH){
  
  digitalWrite(LedV, LOW);
  digitalWrite(LedR, HIGH);
   x = digitalRead(Pulsador); 
  }    

else{
    
    digitalWrite(LedR, LOW);
    digitalWrite(LedV, HIGH);
  x = digitalRead(Pulsador); 
    
    }
}

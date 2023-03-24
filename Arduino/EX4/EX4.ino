int Pines[] = {10, 11, 12};
int x=0;
int pulsador=3;


void setup() {
  // put your setup code here, to run once:

for (int i=0; i <= 2; i++){
  
      pinMode(Pines[i], OUTPUT);
   }

pinMode(pulsador, INPUT);

}

void loop() {

  

for (int i=0; i <= 2; i++){
  
      digitalWrite(Pines[i],HIGH);
      
delay(50);
  
   }


x = digitalRead(pulsador);

if(x==HIGH){

   for (int i=2; i>=0 ; i--){
  
      digitalWrite(Pines[i],LOW);
  
    delay(50);         
   }
   
   delay(500); 
}

}

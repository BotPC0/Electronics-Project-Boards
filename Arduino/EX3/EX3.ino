int Pines[] = {7, 8, 9, 10, 11};

void setup() {
  // put your setup code here, to run once:

for (int i=0; i <= 4; i++){
  
      pinMode(Pines[i], OUTPUT);
   }



}

void loop() {

  

for (int i=0; i <= 4; i++){
  
      digitalWrite(Pines[i],HIGH);
      
delay(500);
  
   }

   for (int i=4; i>=0 ; i--){
  
      digitalWrite(Pines[i],LOW);
      
delay(500);
  
   }


}

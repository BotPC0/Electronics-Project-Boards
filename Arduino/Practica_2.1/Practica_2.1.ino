void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
int x=0;
}

void loop() {
  // put your main code here, to run repeatedly:


for (int i = 2; i <=300 ; i = i + 2){
     
           Serial.print(i);
           Serial.print("__");
   
      delay(150);
   }

}

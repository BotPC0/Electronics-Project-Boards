void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int x = 11;

while((1 < x) && (x <= 11)){
  
  x=x-1;
  
 Serial.println(x);
 
 delay(2000);
 
}
  Serial.println("Terminado");
}

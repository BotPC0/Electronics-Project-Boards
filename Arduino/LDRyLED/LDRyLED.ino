const int LEDPin = 10;
const int LDRPin = A1;


 
void setup()
{
  
pinMode(LEDPin, OUTPUT); 

Serial.begin(9600);

} 
 
void loop()

{

  
  int value = analogRead(LDRPin);

  int val = map(value, 0, 1023, 255, 0);
  
  analogWrite(10, val);

  Serial.println(val);
  
  delay(300);

  while(val<35){
    
    analogWrite(10, 0);
    
    value = analogRead(LDRPin);

    val = map(value, 0, 1023, 255, 0);
    
delay(300);
    
    }

}

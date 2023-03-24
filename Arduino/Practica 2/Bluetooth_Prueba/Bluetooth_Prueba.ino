char val; // variable to receive data from the serial port


void setup() {

  pinMode(LED_BUILTIN, OUTPUT);  // pin 48 (on-board LED) as OUTPUT
  Serial.begin(9600);       // start serial communication at 9600bps
  Serial2.begin(9600);
}

void loop() {


  if( Serial2.available() )       // if data is available to read
  {
    val = Serial2.read();         // read it and store it in 'val'
    Serial.print(val);
  }
  if( val == 'H' )               // if 'H' was received
  {
    digitalWrite(LED_BUILTIN, HIGH);  // turn ON the LED
  } else { 
    digitalWrite(LED_BUILTIN, LOW);   // otherwise turn it OFF
  }
  delay(10);                    // wait 100ms for next reading


  
} 


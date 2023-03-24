char val; // Variable para recibir data del modulo

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);  // Pin 48 (LED Interno)
  pinMode(6, OUTPUT);  // Pin 6 (LED Externo)
  Serial.begin(9600);       
  Serial2.begin(9600); // Comunicacion Serie para el modulo HC-06 a 9600bps

}

void loop() {

  if( Serial2.available() )       // Si tenemos data para leer se lee
  {
    val = Serial2.read();         // Se lee y se guarda en val
    Serial.print(val);
  }
  if( val == 'B' )               // Si se ha recibido B
  {
    digitalWrite(LED_BUILTIN, HIGH);  // Se enciende el LED
    digitalWrite(6, HIGH);
  } else { 
    digitalWrite(LED_BUILTIN, LOW);   // Se apaga el LED
    digitalWrite(6, LOW);
  }
  delay(1000);                    // Esperamos 1s hasta la siguiente lectura
  
} 


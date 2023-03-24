#include <DHT11.h>

DHT11 sensor(9);
float humedad;
float temperatura;
int var = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  var = sensor.read(humedad, temperatura);

  if (var == 0) {
    
   Serial.print("temperatura: ");
    Serial.println(temperatura);
    Serial.print("humedad: ");
    Serial.println(humedad);

  }
  
  delay(500);

}

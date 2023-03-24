const int pinSensor = A1;
int valorSensor = 0;
float voltaje = 0;
float temperatura = 0;

void setup() {
  // inicializamos el puerto serie
  Serial.begin(9600);
}
void loop() {
  valorSensor = analogRead(pinSensor); //leemos el valor del sensor y lo almacenamos en una variable
  Serial.print("valor del sensor: "); // enviamos el valor del sensor al puerto serie
  Serial.print(valorSensor);
  voltaje = (valorSensor / 1024.0) * 5.0; // convertimos el valor del ADC en voltaje
  Serial.print(", Voltaje: "); // enviamos el valor de voltaje al puerto serie
  Serial.print(voltaje);
  Serial.print(", grados C:"); // convertir voltaje a temperatura, teniendo en cuenta el offset del sensor
  temperatura = (voltaje - .5) * 100;
  Serial.println(temperatura);
}

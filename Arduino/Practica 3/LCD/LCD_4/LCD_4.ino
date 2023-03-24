#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
/* lcd--> Nombre del objeto LiquidCrystal pin arduino 7 --> RS (pin 4 LCD)
  pin arduino 8 --> EN (pin 6 LCD)
  pin arduino 9 --> D4 (pin 11 LCD)
  pin arduino 10 --> D5 (pin 12 LCD)
  pin arduino 11 --> D6 (pin 13 LCD)
  pin arduino 12 --> D7 (pin 14 LCD)
  RW --> GND (PIN 5 LCD)*/

const int pinSensor = A1;
int valorSensor = 0;
float voltaje = 0;
float temperatura = 0;

void setup() {
  Serial.begin(9600); // inicializamos el puerto serie
  lcd.begin(16, 2); // inicializamos el LCD
  lcd.print("Hola a todos");
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

  lcd.setCursor(0, 0);
  lcd.write("Temp(Celsius)=");
  lcd.setCursor(7, 1);
  lcd.print(temperatura);
  delay(100);
  lcd.clear();

}

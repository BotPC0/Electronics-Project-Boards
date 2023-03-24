#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
/* lcd--> Nombre del objeto LiquidCrystal pin arduino 7 --> RS (pin 4 LCD)
  pin arduino 8 --> EN (pin 6 LCD)
  pin arduino 9 --> D4 (pin 11 LCD)
  pin arduino 10 --> D5 (pin 12 LCD)
  pin arduino 11 --> D6 (pin 13 LCD)
  pin arduino 12 --> D7 (pin 14 LCD)
  RW --> GND (PIN 5 LCD)*/
int valorSensor = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Hola a todos");
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.write("Entrada (A0)=");
  valorSensor = analogRead(A0);
  valorSensor = map(valorSensor, 0, 1023, 0, 255);
  lcd.setCursor(13, 0);
  lcd.print(valorSensor);
  delay(100);
  lcd.clear();
}

#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
/* lcd--> Nombre del objeto LiquidCrystal pin arduino 7 --> RS (pin 4 LCD)
  pin arduino 8 --> EN (pin 6 LCD)
  pin arduino 9 --> D4 (pin 11 LCD)
  pin arduino 10 --> D5 (pin 12 LCD)
  pin arduino 11 --> D6 (pin 13 LCD)
  pin arduino 12 --> D7 (pin 14 LCD)
  RW --> GND (PIN 5 LCD)*/
void setup() {
  lcd.begin(16, 2);
  lcd.print("Hola a todos");
  Serial.begin(9600);
}
void loop() {
  if (Serial.available()) { // comprobamos si han llegado caracteres por el puerto serie
    delay(100); // esperamos un rato hasta que llegue el mensaje completo
    lcd.clear(); // limpiar pantalla
    while (Serial.available() > 0) {// leer todos los caracteres
      lcd.write(Serial.read());// escribir los caracteres por pantalla
    }
  }
}

#include <LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12);
/* lcd--> Nombre del objeto LiquidCrystal pin arduino 7 --> RS (pin 4 LCD)
pin arduino 8 --> EN (pin 6 LCD)
pin arduino 9 --> D4 (pin 11 LCD)
pin arduino 10 --> D5 (pin 12 LCD)
pin arduino 11 --> D6 (pin 13 LCD)
pin arduino 12 --> D7 (pin 14 LCD)
RW --> GND (PIN 5 LCD)*/
void setup() {
lcd.begin(16,2);
lcd.print("Hola a todos");
}
void loop() {
// put your main code here, to run repeatedly:
lcd.setCursor(7, 1); /*lcd.setCursor(columna, fila) --> columna 7 desplazo el tiempo al centro de la pantalla, la fila 1 es la de abajo*/
lcd.print(millis() / 1000); /* millis es el Tiempo (ms) desde que arranca el arduino si lo divido entre mil consigo un contador de segundos */
}

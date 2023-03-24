bool a = false;
bool b = false;
bool c = false;
bool x = false;
bool y = false;
int Pulsador1 = 9;
int Pulsador2 = 8;
int Pulsador3 = 10;
int LED = 7;
int pos = 0;

#include <Servo.h>
Servo myservo;

bool motor(bool a, bool b, bool c) {

  bool d = (a && b) || (b && c) || (a && c);

  return d;

}

bool led(bool a, bool b, bool c) {

  bool d = ((!a) && c) || ((!c) && b) || (a && (!b));

  return d;

}

void setup() {
  // put your setup code here, to run once:
  pinMode(Pulsador1, INPUT);
  pinMode(Pulsador2, INPUT);
  pinMode(Pulsador3, INPUT);
  pinMode(LED, OUTPUT);
  myservo.attach(4);
}

void loop() {
  // put your main code here, to run repeatedly:

  a = digitalRead(Pulsador1);
  b = digitalRead(Pulsador2);
  c = digitalRead(Pulsador3);
  delay(100);
  x = motor(a, b, c);
  y = led(a, b, c);
  digitalWrite(LED, y);
  delay(100);

  if (pos == 180) {
    pos = 0;
  }

  if (x == true) {

    pos = pos + 15;
    myservo.write(pos);

    delay(15);

  }


}




#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  mySwitch.enableTransmit(9);
}

void loop() {
  mySwitch.send(123, 24);
  delay(1000);
}

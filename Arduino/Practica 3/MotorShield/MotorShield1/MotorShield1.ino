
#include <AFMotor.h>
AF_DCMotor Motor1(1);

void setup() {
  Motor1.run(RELEASE);
}

void loop() {
  Motor1.run(FORWARD);
  delay (2000);
  Motor1.setSpeed(120);
  Motor1.run(BACKWARD);
  delay (2000);
}

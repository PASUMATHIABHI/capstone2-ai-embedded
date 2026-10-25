// Task 4: Sweep a micro servo between 0 and 180 degrees.

#include <Servo.h>

const byte SERVO_PIN = 9;
Servo myServo;

void setup() {
  myServo.attach(SERVO_PIN);
  myServo.write(0);
  delay(500);
}

void loop() {
  for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);
    delay(15);
  }

  delay(300);

  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);
    delay(15);
  }

  delay(300);
}

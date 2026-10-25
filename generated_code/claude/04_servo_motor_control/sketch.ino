/*
 * Task 4: Servo Motor Angle and Sweep Control
 * Board: Arduino Uno
 * Actuator: SG90 / Standard Micro Servo
 *
 * Wiring:
 * - Servo Red (V+)     -> Arduino 5V
 * - Servo Brown (GND)  -> Arduino GND
 * - Servo Orange (PWM) -> Arduino Digital Pin 9 (~PWM)
 */

#include <Servo.h>

const int SERVO_PIN = 9;
Servo myServo;

void setup() {
  Serial.begin(9600);
  Serial.println(F("--- Task 4: Servo Motor Control Initialized ---"));

  // Attach the servo on pin 9 with standard pulse widths (544µs - 2400µs)
  myServo.attach(SERVO_PIN);
  
  // Center servo at 90 degrees on startup
  myServo.write(90);
  delay(1000);
}

void loop() {
  // Phase 1: Discrete target angles demonstration
  Serial.println(F("Moving to discrete target positions:"));
  int targetAngles[] = {0, 45, 90, 135, 180, 90};
  for (int i = 0; i < 6; i++) {
    int angle = targetAngles[i];
    Serial.print(F("  Target Angle: "));
    Serial.print(angle);
    Serial.println(F("°"));
    myServo.write(angle);
    delay(1000);
  }

  // Phase 2: Smooth sweep motion from 0° to 180° and back
  Serial.println(F("Starting smooth sweep 0° -> 180°..."));
  for (int pos = 0; pos <= 180; pos += 2) {
    myServo.write(pos);
    delay(20); // 20ms per 2-degree step
  }
  delay(500);

  Serial.println(F("Starting smooth sweep 180° -> 0°..."));
  for (int pos = 180; pos >= 0; pos -= 2) {
    myServo.write(pos);
    delay(20);
  }
  delay(1000);
}

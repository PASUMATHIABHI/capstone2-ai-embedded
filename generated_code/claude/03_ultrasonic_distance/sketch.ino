/*
 * Task 3: Ultrasonic Distance Measurement (HC-SR04)
 * Board: Arduino Uno
 * Sensor: HC-SR04 Ultrasonic Ranging Module
 *
 * Wiring:
 * - HC-SR04 VCC  -> Arduino 5V
 * - HC-SR04 GND  -> Arduino GND
 * - HC-SR04 TRIG -> Arduino Digital Pin 9
 * - HC-SR04 ECHO -> Arduino Digital Pin 10
 */

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Ensure trigger pin starts LOW
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  Serial.println(F("--- Task 3: HC-SR04 Ultrasonic Distance Sensor Initialized ---"));
}

void loop() {
  // Clear the trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond HIGH pulse to trigger ultrasonic burst
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the round-trip travel time of the echo pulse (in microseconds)
  // 30,000 microseconds timeout (~5 meters max range)
  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    Serial.println(F("[WARNING] Out of range or no echo pulse detected."));
  } else {
    // Speed of sound at 20°C: ~343 m/s = 0.0343 cm/µs
    // Distance = (Duration * 0.0343) / 2 = Duration / 58.2
    float distanceCm = (float)duration / 58.2;
    float distanceInch = (float)duration / 148.0;

    Serial.print(F("Distance: "));
    Serial.print(distanceCm, 1);
    Serial.print(F(" cm  |  "));
    Serial.print(distanceInch, 1);
    Serial.println(F(" inches"));
  }

  delay(500); // 2 Hz measurement rate
}

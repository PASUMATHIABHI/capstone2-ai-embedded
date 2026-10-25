// Task 3: Measure distance with an HC-SR04 ultrasonic sensor.

const byte TRIG_PIN = 9;
const byte ECHO_PIN = 10;
const unsigned long ECHO_TIMEOUT_US = 30000UL;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIG_PIN, LOW);
  Serial.begin(9600);
  Serial.println(F("HC-SR04 distance demo"));
}

void loop() {
  // Send a clean 10 microsecond trigger pulse.
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  const unsigned long duration = pulseIn(ECHO_PIN, HIGH, ECHO_TIMEOUT_US);

  if (duration == 0) {
    Serial.println(F("No echo received (out of range or no target)."));
  } else {
    // Speed of sound is approximately 0.0343 cm per microsecond.
    const float distanceCm = (duration * 0.0343f) / 2.0f;
    Serial.print(F("Distance: "));
    Serial.print(distanceCm, 1);
    Serial.println(F(" cm"));
  }

  delay(500);
}

/*
 * Task 1: LED Blink with External Current-Limiting Resistor
 * Board: Arduino Uno
 *
 * Wiring:
 * - Arduino Digital Pin 8 -> 220 Ohm Resistor -> LED Anode (Long lead / A)
 * - LED Cathode (Short lead / C) -> Arduino GND
 */

const int LED_PIN = 8;
const unsigned long BLINK_INTERVAL_MS = 1000;

void setup() {
  // Initialize serial communication for diagnostic output
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for serial port to connect (needed for native USB)
  }
  
  // Set LED pin as digital output
  pinMode(LED_PIN, OUTPUT);
  Serial.println(F("--- Task 1: LED Blink Initialized ---"));
}

void loop() {
  // Turn LED ON (HIGH sends 5V)
  digitalWrite(LED_PIN, HIGH);
  Serial.println(F("LED Status: ON"));
  delay(BLINK_INTERVAL_MS);

  // Turn LED OFF (LOW connects to 0V)
  digitalWrite(LED_PIN, LOW);
  Serial.println(F("LED Status: OFF"));
  delay(BLINK_INTERVAL_MS);
}

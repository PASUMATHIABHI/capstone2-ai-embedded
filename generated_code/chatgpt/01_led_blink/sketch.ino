// Task 1: Blink an external LED once per second.
// Wiring: D8 -> 220 ohm resistor -> LED anode (A); LED cathode (C) -> GND.

const byte LED_PIN = 8;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // LED ON
  delay(1000);
  digitalWrite(LED_PIN, LOW);   // LED OFF
  delay(1000);
}

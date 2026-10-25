# Coding Guide: How to Prompt for Embedded Code

## 6-Part Prompt Template

Always include these six elements when asking an AI to generate embedded (Arduino/Wokwi) code:

1. **Role** — "You are an embedded systems engineer / instructor."
2. **Board** — e.g., "Arduino Uno"
3. **Task** — specific sensor/actuator, pins, behavior, interval
4. **Libraries** — exact library names or "built-in only"
5. **Constraints** — baud rate, error handling, simulation-safe Wokwi parts
6. **Output format** — `sketch.ino`, `diagram.json`, `libraries.txt`; list Wokwi part types and wiring

## Example: Strong Prompt for Ultrasonic Distance Task

> Role: Embedded systems engineer. Board: Arduino Uno. Task: Measure distance with an HC-SR04 ultrasonic sensor. Pins: TRIG = D9, ECHO = D10. Send a 10 µs trigger pulse, measure echo with pulseIn() with 30000 µs timeout. Compute distance in cm using speed of sound 0.0343 cm/µs (distance = duration × 0.0343 / 2). Handle duration == 0 as out-of-range. Print to Serial Monitor at 9600 baud every 500 ms. Output: sketch.ino and Wokwi diagram.json (wiring VCC→5V, GND→GND, TRIG→D9, ECHO→D10; use wokwi-hc-sr04 part). Include comments explaining the wiring and formula.

## Verification Checklist Before Running

- [ ] Board matches your hardware (Uno, ESP32, etc.)
- [ ] Pin numbers in sketch match `diagram.json` connections
- [ ] All `libraries.txt` entries are installed (including transitive deps like Adafruit Unified Sensor)
- [ ] Wokwi part types exist (e.g., `wokwi-dht22`, not `wokwi-dht11`)
- [ ] Serial baud in sketch matches Serial Monitor setting
- [ ] Sensor-read error checks present (`isnan`, `pulseIn` timeout)
- [ ] Simulation notes for parts that differ from physical hardware (DHT11 vs DHT22)

## Common AI Pitfalls to Watch For

- Missing library dependencies (e.g., DHT needs Adafruit Unified Sensor)
- Using Arduino built-in pins (D13 LED) while adding redundant external parts
- Simulation-only parts that don't exist physically
- Inconsistent sensor model (DHT11 task using DHT22 code/diagram)
- Empty `loop()` or missing `pinMode`/`Serial.begin` calls

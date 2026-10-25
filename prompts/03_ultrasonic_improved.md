# Improved Prompt — Task 3: HC-SR04 Ultrasonic Distance

**Prompt:**
> Role: Embedded systems engineer. Board: Arduino Uno. Sensor: HC-SR04 ultrasonic. Pins: TRIG = D9, ECHO = D10. Send 10 µs trigger pulse, measure echo with `pulseIn()` with 30000 µs timeout. Compute distance in cm using speed of sound 0.0343 cm/µs (distance = duration × 0.0343 / 2). Handle `duration == 0` as out-of-range. Print to Serial Monitor at 9600 baud every 500 ms. Output: `sketch.ino` and Wokwi `diagram.json` (wiring VCC→5V, GND→GND, TRIG→D9, ECHO→D10; use `wokwi-hc-sr04` part).

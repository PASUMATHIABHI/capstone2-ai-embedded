# Prompt Library

This folder contains baseline (weak) and improved (strong) prompts for each of the 5 embedded tasks.

## 6-Part Prompt Template

Every improved prompt includes:
1. **Role** — embedded systems engineer / instructor
2. **Board** — Arduino Uno
3. **Task** — sensor/actuator, pins, behavior, interval
4. **Libraries** — exact names or built-in only
5. **Constraints** — baud rate, error handling, Wokwi parts
6. **Output format** — sketch.ino, diagram.json, libraries.txt

## Tasks & Prompts

| Task | Baseline Prompt | Improved Prompt |
|------|----------------|-----------------|
| 1. LED Blink | `01_led_blink_baseline.md` | `01_led_blink_improved.md` |
| 2. DHT11 Temp/Humidity | `02_dht11_baseline.md` | `02_dht11_improved.md` |
| 3. HC-SR04 Ultrasonic | `03_ultrasonic_baseline.md` | `03_ultrasonic_improved.md` |
| 4. Servo Control | `04_servo_baseline.md` | `04_servo_improved.md` |
| 5. I2C LCD Display | `05_lcd_baseline.md` | `05_lcd_improved.md` |

## Key Finding

Improved prompts significantly outperform baseline prompts across all AI tools. Baseline prompts cause the AI to guess pin numbers, omit libraries, and produce inconsistent wiring.

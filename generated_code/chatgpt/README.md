# Wokwi Beginner Embedded Tasks (Arduino Uno)

This bundle contains five **separate** Arduino Uno projects. Every project folder includes its own `sketch.ino` and `diagram.json`; projects that need third-party libraries also include `libraries.txt`.

## Use the files in Wokwi

1. Open a new Arduino Uno project: <https://wokwi.com/projects/new/arduino-uno>.
2. Open the matching task folder from this ZIP.
3. Copy that folder's `sketch.ino` and `diagram.json` into the same-named files in Wokwi.
4. For the DHT and I2C LCD tasks, add the library names shown in that folder's `libraries.txt` (or paste them into Wokwi's `libraries.txt` tab).
5. Click **Start Simulation**. Open the Serial Monitor for tasks 2 and 3.

Do the steps again in a separate Wokwi project for each of the five tasks. The ZIP itself is a collection of project files, not a pre-published Wokwi project URL.

## Projects

| Folder | Task | Output |
|---|---|---|
| `01_led_blink` | LED blink | External LED on D8 turns on/off once per second |
| `02_dht11_temperature_humidity` | Temperature and humidity | Readings printed to Serial Monitor every 2 seconds |
| `03_ultrasonic_distance` | Ultrasonic distance | Distance in cm printed to Serial Monitor |
| `04_servo_motor_control` | Servo control | Servo sweeps from 0° to 180° and back |
| `05_i2c_lcd_display` | I2C LCD | 16×2 LCD shows a message and running counter |

## Wiring summary

- **LED blink:** Uno D8 → 220 Ω resistor → LED anode (A); LED cathode (C) → GND.
- **DHT temperature/humidity:** VCC → 5V, SDA/data → D2, GND → GND.
- **HC-SR04:** VCC → 5V, TRIG → D9, ECHO → D10, GND → GND.
- **Servo:** PWM/signal → D9, V+ → 5V, GND → GND.
- **I2C LCD1602:** VCC → 5V, GND → GND, SDA → A4, SCL → A5. LCD address in the sketch is `0x27`.

## Note about DHT11 in Wokwi

Wokwi's documented humidity/temperature part is `wokwi-dht22`, so this simulator project uses that part and defines `DHTTYPE` as `DHT22` to match it. The wiring and reading logic are suitable as a beginner exercise for the DHT family. For a **physical DHT11 module**, change `#define DHTTYPE DHT22` to `#define DHTTYPE DHT11` in the sketch and use the actual DHT11 hardware.

# Task Selection — Step 1

## 5 Beginner-Level Embedded Tasks Selected

All five tasks appear in all three AI-generated bundles (ChatGPT, Claude, Gemini):

| # | Task | Components | Arduino Pins | External Library Needed? |
|---|------|-----------|--------------|--------------------------|
| 1 | LED Blink | External LED, 220 Ω resistor | D8 (ChatGPT/Claude) / D13 (Gemini) | No |
| 2 | DHT11/DHT22 Temp & Humidity | DHT22 sensor (Wokwi model) | D2 data | Yes: DHT sensor library + Adafruit Unified Sensor |
| 3 | HC-SR04 Ultrasonic Distance | Ultrasonic ranging module | D9 TRIG, D10 ECHO | No |
| 4 | Servo Motor Control | SG90 micro servo | D9 PWM | No (Servo.h built-in) |
| 5 | I2C 16×2 LCD Display | LCD1602 with PCF8574 I2C backpack | A4 SDA, A5 SCL | Yes: LiquidCrystal I2C |

**Why these are beginner-level:** each uses one sensor/actuator, basic digital/analog I/O, standard Arduino functions, and runs on Arduino Uno in Wokwi simulation.

**Source files:** `generated_code/chatgpt/`, `generated_code/claude/`, `generated_code/gemini/`

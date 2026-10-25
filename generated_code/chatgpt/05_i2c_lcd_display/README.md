# 5. I2C LCD Display

**Files:** `sketch.ino`, `diagram.json`, `libraries.txt`

The 16×2 LCD shows a heading and a counter that increments every second. The LCD is configured for I2C (address `0x27`): SDA → A4, SCL → A5, VCC → 5V, GND → GND. No extra wires are needed for the display's parallel data pins because the diagram uses its I2C configuration.

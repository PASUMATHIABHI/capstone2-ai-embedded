# Improved Prompt — Task 5: I2C LCD Display

**Prompt:**
> Role: Embedded display engineer. Board: Arduino Uno. Display: 16×2 character LCD with PCF8574 I2C backpack, address 0x27. Pins: SDA→A4, SCL→A5, VCC→5V, GND→GND. Library: "LiquidCrystal I2C" + built-in `Wire.h`. Behavior: initialize with backlight on, print a heading on row 0 and an incrementing counter on row 1 every second, clear leftover digits. Output: `sketch.ino`, `diagram.json` (use `wokwi-lcd1602` with `pins: i2c`, `i2cAddress: 0x27`), and `libraries.txt`.

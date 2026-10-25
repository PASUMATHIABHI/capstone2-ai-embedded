// Task 5: Display a message and counter on a 16x2 I2C LCD.

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Wokwi LCD1602 I2C default address is 0x27.
LiquidCrystal_I2C lcd(0x27, 16, 2);
unsigned long counter = 0;

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print(F("I2C LCD Display"));
  lcd.setCursor(0, 1);
  lcd.print(F("Counter: 0"));
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(F("Counter: "));
  lcd.print(counter++);
  lcd.print(F("    "));  // Clear leftover digits from the previous value.
  delay(1000);
}

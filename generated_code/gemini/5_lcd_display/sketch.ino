// Task 5: 16x2 I2C LCD (Arduino Uno) - SDA=A4, SCL=A5, address 0x27
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello, ECE!");
  lcd.setCursor(0, 1);
  lcd.print("Capstone 2");
}

void loop() {
}

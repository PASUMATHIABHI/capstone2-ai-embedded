/*
 * Task 5: I2C 16x2 Character LCD Display
 * Board: Arduino Uno
 * Display: LCD1602 with PCF8574 I2C Backpack
 *
 * Wiring:
 * - LCD VCC -> Arduino 5V
 * - LCD GND -> Arduino GND
 * - LCD SDA -> Arduino Analog Pin A4 (or dedicated SDA pin)
 * - LCD SCL -> Arduino Analog Pin A5 (or dedicated SCL pin)
 *
 * I2C Address: 0x27 (standard for PCF8574T backpacks)
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set LCD address to 0x27 with 16 columns and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Custom Heart character glyph (5x8 matrix)
byte customHeart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000
};

unsigned long previousMillis = 0;
int counter = 0;

void setup() {
  Serial.begin(9600);
  Serial.println(F("--- Task 5: I2C LCD Display Initialized ---"));

  // Initialize LCD hardware and turn on backlight
  lcd.init();
  lcd.backlight();

  // Create custom character at index 0
  lcd.createChar(0, customHeart);

  // Display initial greeting
  lcd.setCursor(0, 0);
  lcd.print("Embedded Systems");
  lcd.setCursor(0, 1);
  lcd.print("Wokwi Lab ");
  lcd.write(byte(0)); // Print custom heart icon
  
  delay(3000);
  lcd.clear();

  // Permanent header on row 0
  lcd.setCursor(0, 0);
  lcd.print("Status: RUNNING");
}

void loop() {
  unsigned long currentMillis = millis();

  // Update dynamic uptime counter once per second
  if (currentMillis - previousMillis >= 1000) {
    previousMillis = currentMillis;
    counter++;

    lcd.setCursor(0, 1);
    lcd.print("Uptime: ");
    lcd.print(counter);
    lcd.print("s   "); // Spaces clear leftover trailing digits

    Serial.print(F("Uptime counter updated: "));
    Serial.print(counter);
    Serial.println(F(" s"));
  }
}

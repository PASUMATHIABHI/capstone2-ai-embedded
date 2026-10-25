/*
 * Task 2: Digital Temperature & Humidity Reading
 * Board: Arduino Uno
 * Sensor: DHT11 / DHT22 (Wokwi uses wokwi-dht22 component)
 *
 * Wiring:
 * - DHT VCC -> Arduino 5V
 * - DHT GND -> Arduino GND
 * - DHT Data/SDA -> Arduino Digital Pin 2
 *
 * Note: If deploying on physical DHT11 hardware, set DHTTYPE to DHT11 below.
 */

#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // For Wokwi simulation use DHT22; change to DHT11 for physical DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("--- Task 2: DHT Temperature & Humidity Monitor ---"));

  dht.begin();
}

void loop() {
  // Sensor reading interval: DHT sensors require at least 1-2 seconds between samples
  delay(2000);

  // Read humidity and temperature
  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();
  float temperatureF = dht.readTemperature(true);

  // Verify that the reading was successful
  if (isnan(humidity) || isnan(temperatureC) || isnan(temperatureF)) {
    Serial.println(F("[ERROR] Failed to read from DHT sensor! Check connections."));
    return;
  }

  // Compute Heat Index in Celsius and Fahrenheit
  float heatIndexC = dht.computeHeatIndex(temperatureC, humidity, false);

  Serial.println(F("========================================"));
  Serial.print(F("Humidity:         "));
  Serial.print(humidity, 1);
  Serial.println(F(" %"));
  Serial.print(F("Temperature:      "));
  Serial.print(temperatureC, 1);
  Serial.print(F(" °C  ("));
  Serial.print(temperatureF, 1);
  Serial.println(F(" °F)"));
  Serial.print(F("Heat Index:       "));
  Serial.print(heatIndexC, 1);
  Serial.println(F(" °C"));
}

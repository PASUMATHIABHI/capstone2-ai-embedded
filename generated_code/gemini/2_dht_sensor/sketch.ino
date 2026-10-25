// Task 2: Temperature & humidity reading (Arduino Uno)
// Wokwi's built-in sensor is the DHT22, so DHTTYPE is DHT22 here.
// For a real DHT11, change DHTTYPE to DHT11 (wiring is identical).
#include "DHT.h"

const int DHT_PIN = 2;
#define DHTTYPE DHT22

DHT dht(DHT_PIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Sensor read failed");
    return;
  }
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" C  Humidity: ");
  Serial.print(h);
  Serial.println(" %");
}

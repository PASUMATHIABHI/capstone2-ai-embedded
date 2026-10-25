// Task 2: Read temperature and relative humidity from a DHT sensor.
// Wokwi component used in diagram.json: DHT22 model. For a physical DHT11,
// change DHTTYPE to DHT11.

#include <DHT.h>

const byte DHT_PIN = 2;
#define DHTTYPE DHT22

DHT dht(DHT_PIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println(F("DHT temperature and humidity demo"));
}

void loop() {
  // DHT sensors should not be polled too frequently.
  delay(2000);

  const float humidity = dht.readHumidity();
  const float temperatureC = dht.readTemperature();

  if (isnan(humidity) || isnan(temperatureC)) {
    Serial.println(F("Sensor read failed. Check wiring and sensor type."));
    return;
  }

  Serial.print(F("Temperature: "));
  Serial.print(temperatureC, 1);
  Serial.print(F(" C | Humidity: "));
  Serial.print(humidity, 1);
  Serial.println(F(" %"));
}

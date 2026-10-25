# 2. DHT Temperature and Humidity Reading

**Files:** `sketch.ino`, `diagram.json`, `libraries.txt`

Open the Serial Monitor at **9600 baud** to see temperature (°C) and relative humidity (%), refreshed every two seconds. Click the sensor during simulation to adjust its values.

**Wokwi model note:** this diagram uses Wokwi's `wokwi-dht22` component. The sketch defines `DHTTYPE DHT22` so it matches the simulator model. For a real DHT11 module, change that line to `#define DHTTYPE DHT11`.

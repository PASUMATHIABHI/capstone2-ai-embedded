# Verification Report

## Objective

Evaluate how reliable AI-generated embedded code is, and what verification process makes it safe to use.

## Methodology

1. Selected 5 beginner tasks: LED blink, DHT11 temp/humidity, HC-SR04 distance, servo sweep, I2C LCD
2. Wrote baseline vs improved prompts for each task
3. Generated code with 3 AI tools: ChatGPT, Claude, Gemini
4. Compiled and simulated each program in Wokwi (Arduino Uno)
5. Logged compile errors, wrong pins, missing libraries, logic errors
6. Applied human fixes and documented which fixes AI could/could not suggest
7. Scored tools with a weighted rubric

## Compilation & Simulation Status

| Task | ChatGPT | Claude | Gemini | Notes |
|------|---------|--------|--------|-------|
| 1 LED Blink | ✅ | ✅ | ⚠️ | Gemini: redundant D13 external LED |
| 2 DHT Temp/Humidity | ✅ | ✅ | ❌ | Gemini: missing Adafruit Unified Sensor dep |
| 3 Ultrasonic | ✅ | ✅ | ✅ | All correct |
| 4 Servo Control | ✅ | ✅ | ✅ | All correct |
| 5 I2C LCD | ✅ | ✅ | ✅ | Gemini: empty loop (static only) |

✅ = runs without modification | ⚠️ = runs but has wiring issue | ❌ = needs fix before compiling

## Errors Found (3 total)

| # | Task | AI Tool | Error Type | Details | Human Fix |
|---|------|---------|------------|---------|-----------|
| 1 | LED Blink | Gemini | Wrong wiring | Uses D13 (built-in LED) + redundant external LED + resistor | Rewired external LED to D8 |
| 2 | DHT Temp/Humidity | Gemini | Missing library | `libraries.txt` lists only "DHT sensor library"; needs Adafruit Unified Sensor too | Added Adafruit Unified Sensor |
| 3 | DHT (all tools) | All three | Sim vs hardware | Wokwi uses `wokwi-dht22` part; physical DHT11 needs `DHTTYPE DHT11` | Added explicit code/README note |

## Conclusion

AI is a strong code drafter but not a reliable verifier. Human debugging was required for missing libraries, wrong pins, and simulation/hardware mismatches. Claude produced the most reliable code; Gemini needed the most human fixes.

**Recommendation:** Use AI to generate starter code, then compile, simulate, review wiring, install all libraries, and test on real hardware before deployment.

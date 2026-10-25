# Human Debugging — Step 6

## Fixes Applied with Human Debugging

### Fix 1 — Gemini D13 external LED redundancy (Task 1)
- **Human fix:** Rewired LED to D8 with 220 Ω resistor to GND (matching ChatGPT/Claude), or removed external parts and used built-in D13 LED.
- **Could AI suggest it?** Partially — AI could suggest "use D8 instead of D13" if prompted, but generated the redundant wiring autonomously.

### Fix 2 — Gemini missing Adafruit Unified Sensor (Task 2)
- **Human fix:** Added "Adafruit Unified Sensor" to `libraries.txt`.
- **Could AI suggest it?** No — Gemini omitted it entirely and did not flag the dependency.

### Fix 3 — DHT11/DHT22 simulation-vs-hardware note (All three)
- **Human fix:** Added explicit comment: "Wokwi uses wokwi-dht22; set DHTTYPE DHT22 for simulation, change to DHT11 for physical DHT11 hardware."
- **Could AI suggest it?** Partially — ChatGPT and Claude included this note; Gemini only mentioned it in a passing comment.

## Summary

AI could suggest surface-level fixes (pin numbers, comments) when prompted, but could not reliably detect missing library dependencies or hardware/simulation mismatches on its own. Human domain knowledge was required for all three fixes.

# Safety & Licensing — Step 12

## Safety

AI-generated embedded code controls physical hardware, so correctness matters for safety:

- **Wrong pin assignments** can short circuits or damage components. Always review `sketch.ino` against `diagram.json` before powering real hardware.
- **Missing current-limiting** — Gemini's LED task wired an external LED on D13 (a pin that already has a built-in LED and resistor on Uno); redundant external parts can confuse behavior.
- **Sensor/hardware mismatch** — All three bundles used Wokwi's `wokwi-dht22` for a DHT11 task. Simulation works, but a physical DHT11 needs `DHTTYPE DHT11`. Blindly deploying simulation code to real hardware can produce wrong readings.
- **No current/thermal protection** in generated code; AI does not calculate power dissipation or safe operating limits.
- **Best practice:** treat AI output as a draft. Compile, simulate in Wokwi/Tinkercad, review wiring, then test on real hardware with a current-limited supply before any deployment.

## Licensing of AI-Generated Code

- **Copyright status is uncertain.** In many jurisdictions, code generated entirely by an AI without human authorship may not be copyrightable. The human who prompts, edits, and integrates the code may claim authorship of the final work, but this varies by country and is unsettled law.
- **Tool terms of service** govern what you may do with the output (e.g., whether you can use it commercially, whether the provider claims a license to your inputs/outputs). Review the terms of ChatGPT, Claude, and Gemini before using generated code in a commercial or published project.
- **Open-source libraries** used in the sketches (DHT sensor library, Adafruit Unified Sensor, LiquidCrystal I2C, Servo, Wire) carry their own licenses (typically MIT, BSD, or LGPL). The AI did not include license headers; you must add proper attribution and comply with each library's license when distributing the combined project.
- **Recommendation:** add a LICENSE file to your GitHub repo, document which parts are AI-generated vs. human-written, and include library attribution in `sketch.ino` comments.

## Limitations of AI Code Generation for Embedded Systems

| Limitation | Evidence from this project |
|------------|---------------------------|
| Missing dependencies | Gemini omitted "Adafruit Unified Sensor" from `libraries.txt` |
| Wrong/redundant hardware wiring | Gemini used D13 (built-in LED) with external LED+resistor |
| Simulation-only assumptions | All tools used Wokwi `wokwi-dht22` for a DHT11 task |
| No self-verification | AI did not detect its own missing library or wiring conflicts |
| Inconsistent quality across tools | Claude scored 4.85/5 vs Gemini 3.45/5 on the rubric |
| Limited documentation | Gemini's output had the fewest comments and no README |

**Bottom line:** AI is useful for generating starter embedded code, but it is **not a substitute for human verification**. Always compile, simulate, review wiring against the datasheet, install all libraries, and test on real hardware before considering the code safe to use.

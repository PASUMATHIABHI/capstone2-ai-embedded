# Automation Template — Step 10

## Task-to-Prompt Template (Sheets / Notion)

This template turns a plain task description into a standard improved prompt. It can be implemented as a Google Sheets form or a Notion database/template.

## Prompt Template

```
Role: {{role}}
Board: {{board}}
Task: {{task_description}}
Components/Pins: {{components_and_pins}}
Libraries: {{library_names_or_builtin_only}}
Constraints: {{constraints}}
Output: sketch.ino, diagram.json, libraries.txt (if needed)
Wokwi parts: {{wokwi_part_types}}
Wiring: {{wiring_description}}
```

## Example Filled-In Row (Task 3 — Ultrasonic)

| Field | Value |
|-------|-------|
| role | Embedded systems engineer |
| board | Arduino Uno |
| task_description | Measure distance with HC-SR04 ultrasonic sensor; print cm to Serial Monitor every 500 ms |
| components_and_pins | HC-SR04: TRIG=D9, ECHO=D10, VCC=5V, GND=GND |
| libraries | Built-in only (no external install) |
| constraints | 10 µs trigger pulse, pulseIn 30000 µs timeout, duration==0 = out-of-range, 9600 baud |
| output | sketch.ino, diagram.json |
| wokwi_parts | wokwi-arduino-uno, wokwi-hc-sr04 |
| wiring | VCC→5V, GND→GND, TRIG→D9, ECHO→D10 |

## Sheets / Notion Implementation

**Google Sheets:** Create columns for each field above. Use a formula column to assemble the full prompt from the row, then copy-paste into the AI chat.

**Notion:** Create a database with properties matching the template fields. Use a Notion formula or manual assembly to build the prompt, then paste into the AI tool.

**Benefit:** Standardizes prompts across tasks and team members, removes variability, and makes prompt versions easy to track.

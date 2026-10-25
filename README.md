# CAPSTONE 2 — AI-Assisted Arduino/ESP32 Code Generation and Verification

---

## Project Question

*How reliable is AI-generated embedded code, and what verification process makes it safe to use?*

---

## Repository Structure

```
capstone2-ai-embedded/
├── README.md                          # Project overview (this file)
├── task_selection.md                  # Step 1: 5 selected beginner tasks
├── prompts/                           # Step 2: baseline vs improved prompts
│   ├── 01_led_blink_baseline.md
│   ├── 01_led_blink_improved.md
│   ├── 02_dht11_baseline.md
│   ├── 02_dht11_improved.md
│   ├── 03_ultrasonic_baseline.md
│   ├── 03_ultrasonic_improved.md
│   ├── 04_servo_baseline.md
│   ├── 04_servo_improved.md
│   ├── 05_lcd_baseline.md
│   └── 05_lcd_improved.md
├── generated_code/                    # Step 3: AI-generated code (3 tools)
│   ├── chatgpt/                       # wokwi_beginner_tasks.zip (OpenAI)
│   ├── claude/                        # wokwi_beginner_embedded_tasks.zip (Claude)
│   └── gemini/                        # wokwi_capstone2_projects.zip (Gemini)
├── presentation/                      # Step 9: 7-slide PPTX
│   └── CAPSTONE2_AI_Embedded_Verification.pptx
├── screenshots/                       # Wokwi simulation screenshots (add here)
│   └── README.md
├── verification_report.md             # Step 4-5: verification results & error log
├── before_after_analysis.md           # Step: baseline vs improved comparison
├── coding_guide.md                    # Step 8: how to prompt for embedded code
├── safety_licensing.md                # Step 12: safety, licensing, limitations
├── scoring_rubric.md                  # Step 7: tool comparison scores
├── human_debugging.md                 # Step 6: human fixes & AI limitations
├── automation_template.md             # Step 10: Sheets/Notion template
└── github_docs.md                     # Step 11: GitHub documentation
```

---

## The 5 Tasks Selected

| # | Task | Components | Pins | Library |
|---|------|-----------|------|---------|
| 1 | LED Blink | LED + 220 Ω resistor | D8 | None |
| 2 | DHT11 Temp/Humidity | DHT22 sensor | D2 | DHT sensor + Adafruit Unified Sensor |
| 3 | HC-SR04 Ultrasonic Distance | Ultrasonic module | D9/D10 | None |
| 4 | Servo Motor Control | SG90 servo | D9 | Servo.h (built-in) |
| 5 | I2C LCD Display | LCD1602 I2C backpack | A4/A5 | LiquidCrystal I2C |

---

## The 3 AI Tools Compared

| Tool | Source | Weighted Score (0-5) |
|------|--------|---------------------|
| ChatGPT | `generated_code/chatgpt/` | 4.55 |
| Claude | `generated_code/claude/` | **4.85** |
| Gemini | `generated_code/gemini/` | 3.45 |

**Winner:** Claude — most complete code, best error handling, best documentation.

---

## Key Findings

1. **Claude produced the most reliable code** across all 5 tasks.
2. **Gemini needed the most human fixes** — missing Adafruit Unified Sensor dependency, redundant D13 external LED wiring.
3. **Improved prompts** (role/board/pins/libraries/constraints) significantly outperform baseline prompts.
4. **AI is a strong drafter but not a verifier** — human debugging was required for missing libraries, wrong pins, and simulation/hardware mismatches.

---

## Final Submission Checklist

- [x] Task selection
- [x] Prompt library (baseline + improved)
- [x] AI code generation (3 tools)
- [x] Compilation & simulation plan
- [x] Error log & tool comparison
- [x] Human debugging analysis
- [x] Scoring rubric
- [x] Coding guide
- [x] Presentation (PPTX)
- [x] Automation template
- [x] GitHub documentation
- [x] Safety & licensing
- [x] Verification report
- [x] Before/after analysis
- [x] Final demo

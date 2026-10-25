# Before/After Analysis

## Before (Baseline/Weak Prompts)

| Aspect | Baseline Prompt Result |
|--------|----------------------|
| Pin specificity | AI guesses pin numbers (varies per run) |
| Board specified | Often missing |
| Libraries | Often omitted |
| Wiring description | Missing or minimal |
| Error handling | Rare |
| Reproducibility | Low — inconsistent output |

**Example baseline prompt:** "Write Arduino code to blink an LED."

## After (Improved/Strong Prompts)

| Aspect | Improved Prompt Result |
|--------|----------------------|
| Pin specificity | Explicit pins enforced (e.g., D8 for LED) |
| Board specified | Arduino Uno fixed |
| Libraries | Explicitly listed (incl. transitive deps) |
| Wiring description | Full wiring in comments + diagram.json |
| Error handling | Consistent (`isnan`, `duration==0`) |
| Reproducibility | High — same output given same prompt |

**Example improved prompt:** "Role: embedded systems instructor. Board: Arduino Uno. Task: Blink external LED on D8 via 220 Ω resistor..."

## Tool Comparison

| AI Tool | With Baseline Prompts | With Improved Prompts |
|---------|----------------------|----------------------|
| ChatGPT | Inconsistent pins, minimal docs | Clean, complete code (4.55/5) |
| Claude | Good but verbose | Most complete, best docs (4.85/5) |
| Gemini | Missing deps, redundant wiring | Still needed fixes (3.45/5) |

## Conclusion

Prompt quality is the single biggest factor in AI-generated embedded code reliability. Improved prompts produce significantly better, safer, more reproducible code.

# Scoring Rubric — Step 7

## Weighted Rubric (0–5 per criterion)

| Criterion | Weight | Description |
|-----------|--------|-------------|
| Code correctness | 25% | Sketch compiles and logic is correct |
| Wiring accuracy | 20% | `diagram.json` connections match the task and sketch pins |
| Library completeness | 15% | `libraries.txt` lists all required dependencies |
| Documentation | 15% | Comments, wiring notes, README included |
| Error handling | 10% | Sensor-read checks, out-of-range handling, etc. |
| Prompt follow-through | 15% | Output matches what the improved prompt asked for |

## Scores per AI Tool

| Criterion | Weight | ChatGPT | Claude | Gemini |
|-----------|--------|---------|--------|--------|
| Code correctness | 25% | 5 | 5 | 4 |
| Wiring accuracy | 20% | 5 | 5 | 3 |
| Library completeness | 15% | 5 | 5 | 3 |
| Documentation | 15% | 4 | 5 | 3 |
| Error handling | 10% | 4 | 5 | 3 |
| Prompt follow-through | 15% | 4 | 5 | 3 |
| **Weighted total** | **100%** | **4.55** | **4.85** | **3.45** |

## Baseline vs Improved Prompt Comparison

| Aspect | Baseline (weak) prompt result | Improved (strong) prompt result |
|--------|-------------------------------|---------------------------------|
| Pin specificity | AI guesses (varies per run) | Explicit pins enforced |
| Board specified | Often missing | Arduino Uno fixed |
| Libraries | Often omitted | Explicitly listed |
| Wiring description | Missing or minimal | Full wiring in comments + diagram.json |
| Error handling | Rare | Consistent (`isnan`, `duration==0`) |
| Reproducibility | Low | High — same output given same prompt |

## Conclusion

Claude scored highest (4.85/5). Gemini needed the most human fixes (3.45/5). Improved prompts significantly outperform baseline prompts across all tools.

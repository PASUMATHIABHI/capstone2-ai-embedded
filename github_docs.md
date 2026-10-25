# GitHub Documentation — Step 11

## Repository Structure

```
capstone2-ai-embedded/
├── README.md
├── task_selection.md
├── prompts/
├── generated_code/
│   ├── chatgpt/
│   ├── claude/
│   └── gemini/
├── presentation/
│   └── CAPSTONE2_AI_Embedded_Verification.pptx
├── screenshots/
├── verification_report.md
├── before_after_analysis.md
├── coding_guide.md
├── safety_licensing.md
├── scoring_rubric.md
├── human_debugging.md
├── automation_template.md
└── github_docs.md
```

## Prompts & Versions

All baseline and improved prompts are stored under `prompts/`. Each prompt includes: role, board, pins, libraries, constraints, and output format.

AI tool versions used:
- ChatGPT (OpenAI GPT) — `generated_code/chatgpt/`
- Claude — `generated_code/claude/`
- Gemini — `generated_code/gemini/`

Generated source code is preserved under `generated_code/` for reference and re-verification.

## How to Reproduce

1. Clone this repo.
2. Open https://wokwi.com/projects/new/arduino-uno
3. For each task under `generated_code/<tool>/<task>/`, paste `sketch.ino`, `diagram.json` (and `libraries.txt` if present) into Wokwi editor tabs.
4. Press Start Simulation; open Serial Monitor at 9600 baud for tasks 2 and 3.
5. Compare results against `scoring_rubric.md`.

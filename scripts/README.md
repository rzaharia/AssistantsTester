# Scripts for Source Generation, Building, and Evaluation

This folder contains the framework for automating source generation, building, and evaluation of LLM responses for MITRE ATT&CK technique detection.  It is divided into two main components:

- **MitreSourceGenerator/** – Scripts for automatically generating source code for testing.
- **AssistantsTester/** – The main testing framework for evaluating LLM responses.

## 📁 MitreSourceGenerator/

This component handles the automated generation of source code based on the `MitreOperation.csv` file (located in the `MITRE` folder).  It processes instructions within this CSV to create test cases.

- **"src" instruction:** Indicates that a hand-made source code file (with the specified name) exists and should be copied to the `all-sources` folder.
- **"exec" instruction:** Triggers the generation of source code for various execution patterns.  It iterates through each pattern in the `patterns` folder (currently 13 different execution methods) and generates a source file for each.  The generated files are named according to the pattern (e.g., `E0` for execution with pattern index 0).

## 📁 AssistantsTester/

This component constitutes the core testing framework for evaluating LLM responses.  It manages the following processes:

1. **Building and Optimization:** Compiles the generated source code into binaries, potentially with optimizations.
2. **Evaluation:**
    - Iterates through every generated binary.
    - Queries the LLM to identify the appropriate MITRE ATT&CK technique for each binary.
    - Writes the LLM output to a file.
    - Extracts and validates the LLM responses.
    - Displays a summary of the results.

**GView Automation:**

The `gviewRunScripts` directory contains scripts for automating GView to facilitate the analysis process.  The process involves analyzing each binary across different contexts (Complete, Partial, and Limited) for multiple LLMs (currently Gemini 1.5 PRO and GPT 4o). This results in a large number of runs: 280 problems * 2 LLMs * 3 contexts = 1680 runs. Each run involves opening GView and querying the LLM.

To optimize this process, two GView automation scripts are provided.  Furthermore, the framework supports multi-threading, allowing for parallel execution of GView instances across different folders, significantly speeding up the analysis. The number of threads is configurable.

**Utilities:**

The `utils.py` script contains mappings for linker libraries used for obtaining minimal builds.
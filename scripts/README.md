# Scripts for Source Generation, Building, and Evaluation

This folder contains the framework for automating source generation, building, and evaluation of LLM responses for MITRE ATT&CK technique detection.  It is divided into two main components:

- **MitreSourceGenerator/** – Scripts for automatically generating source code for testing.
- **AssistantsTester/** – The main testing framework for evaluating LLM responses.

## 📁 MitreSourceGenerator/  

This component handles the automated generation of source code based on the `MitreOperations.csv` file (located in the `MITRE` folder). It processes instructions within this CSV to create test cases.  

### **Supported Instructions:**  

- **"src" instruction:** Indicates that a manually created source code file (with the specified name) exists and should be copied to the `all_sources` folder.  
- **"exec" instruction:** Triggers the generation of source code for various execution patterns. It iterates through each pattern in the `patterns` folder (currently **13 different execution methods**) and generates a source file for each. The generated files are named according to the pattern (e.g., `E0` for execution with pattern index 0).  
- **"clean" instruction (New Feature):** Similar to **"exec"**, this instruction generates source code using the same **13 execution methods**, but with a key difference:  
  - The **command chosen is specifically selected to resemble a MITRE-related technique** while **not actually being malicious**.  
  - This is done **to misguide the LLM**, testing whether it falsely detects an attack when none exists.  

### **Tricking the LLM with Small Modifications**  

In addition to generating sources, the script also:  
- **Searches for manually created sources that involve working with Windows registries**.  
- Uses these registry-based sources as a **starting point** to generate deceptive variations designed to trick the LLM.  
- Makes small but intentional modifications, including:  
  - **Changing a single letter** (e.g., "Windows" → "Wundows").  
  - **Altering words** (e.g., "Run" → "Fun").  
  - **Deleting or replacing words** while keeping core functionality intact.  
  - **Adding words commonly found in malicious scenarios** (e.g., explicitly adding `"Run"` to the code).  

#### **Example: Registry Path Alterations**  

To test the LLM's robustness against misleading inputs, the framework modifies the standard Windows registry path:  

**Original Path:**  
`Software\Microsoft\Windows\CurrentVersion\Run`  

**Generated Variations:**  
1. `Software\Microsoft\Windows\CurrentVersion\Fun`  
2. `Software\Microsoft\Windows\CurrentVersion\Tool`  
3. `Software\Demo`  
4. `Software\Run`  
5. `Windows\CurrentVersion\Run`  
6. `Software\Microsoft\Wundows\CurrentVersion\Run`  
7. `Software\Microsoft\CurrentVersion\Run`  

These modifications help assess whether an LLM can correctly identify real threats while ignoring misleading changes.  

### **Adversarial Impact on LLM Tokenization and Recognition**  

These modifications exploit how **LLMs tokenize and process text**, testing their **robustness against small adversarial changes**. Since LLMs do not analyze raw characters but rather **tokenized representations**, even a minor modification—such as changing `"Windows"` to `"Wundows"`—can alter how the model interprets the input. Some models may tokenize entire words, while others break them into subwords, meaning that **a single-letter change could completely disrupt recognition**. Conversely, adding misleading words like `"Run"`—which frequently appears in malicious contexts—can **increase the likelihood of a false positive**. By applying these adversarial alterations, we assess whether an LLM can **correctly differentiate between real and deceptive security-related patterns**, highlighting potential weaknesses in its **pattern-matching and contextual reasoning** capabilities.  


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
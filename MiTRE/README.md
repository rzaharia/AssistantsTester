# MITRE Evaluation

## 📌 Purpose  
This study evaluates how well large language models (LLMs) can **recognize and identify MITRE ATT&CK techniques** in compiled binaries. The primary goal is to assess their ability to detect security-related functions and commands within **x86/x64 disassembly**.

Beyond just testing detection accuracy, the study also examines **how well LLMs handle deceptive cases**, where some binaries are intentionally designed to **trick the model** into misidentifying or falsely detecting techniques. To achieve this, we have built a structured dataset containing three distinct categories of C++ source programs:  

1. **MITRE-related sources** – Programs that **explicitly contain** MITRE ATT&CK techniques.  
2. **Deceptive (trick) sources** – Programs that **do not contain MITRE techniques** but are crafted to potentially mislead an LLM.  
3. **Trivial benign sources** – Simple programs that **clearly do not contain** any MITRE techniques and serve as a baseline for correct negative classification.  

This structured dataset allows us to measure not only detection rates but also the LLMs' **robustness against false positives** and their **ability to distinguish real threats from misleading cases**.  

## 🧪 Methodology  

### ⚠️ Disclaimer  

Our primary goal is to **analyze compiled binaries** and evaluate how well LLMs can recognize MITRE ATT&CK techniques. However, some of these techniques are associated with **potentially malicious behavior**.  

To ensure compliance with ethical guidelines and security best practices, we do **not** distribute pre-compiled binaries that might be considered **malicious**. Instead, we provide **source code** that can be compiled into binaries for research purposes.  

Throughout this documentation, we refer to these files as **"sources"**, but our evaluation is conducted on **the compiled versions of these sources**. Users are responsible for ensuring that they handle and analyze these files in a **controlled and safe environment**.  

### 🔹 MITRE Technique Selection  
We analyzed **MITRE techniques** that are relevant for binary analysis using **GView**, a binary visualization tool. The study focuses on techniques that could be **automatically extracted and evaluated** in compiled binaries.  

### 🔹 Source Code Generation  

A total of **656 C++ programs** were created, forming a structured **evaluation database** consisting of both manually written and automatically generated samples. These samples are categorized as follows:  
   - **MITRE-related sources (280)** – Programs that explicitly implement various MITRE ATT&CK techniques, covering different tactics and execution patterns.  
   - **Deceptive (trick) sources (285)** – Programs that are designed to **look suspicious** to an LLM, testing its ability to differentiate real techniques from misleading patterns.  
   - **Trivial benign sources (91)** – Simple programs that have **no connection to MITRE techniques** and should be correctly identified as benign.  

To ensure diversity in structure and execution behavior:  
- **33 hand-crafted sources** were manually developed to cover edge cases and complex execution paths.  
- **623 sources** were automatically generated using **MitreSourceGenerator**, with controlled variations in structure and logic:
  - **280 auto-generated sources** that reflect a specific technique spread across various MITRE tactics;
  - **285 C++ benign samples** that do not imply any MITRE techniques, but are designed to trick a LLM;
  - **91 C++ benign (trivial) samples** that do not imply any MITRE techniques.

Each source that represents a **command execution**, and our automation framework can generate variations of each command in **13 different ways** (details available in the `MitreSourceGenerator` component).  

### 🔹 Compilation and Binary Optimization  
Each source is compiled into a **minimal binary** by optimizing the **default Visual Studio project settings**, ensuring that only the **necessary libraries** are linked. This minimizes unnecessary dependencies and focuses the evaluation on core functionality.  

### 🔹 LLM-Based Analysis  
Each compiled binary is **evaluated by multiple LLMs** to determine their ability to recognize MITRE techniques. The models are tested under **three levels of context**:  

1. **Complete Context** – Using both **imported libraries** and **recognized strings** from the binary.  
2. **Partial Context** – Using only **imported libraries**, ignoring recognized strings (`yes_imports_no_strings`).  
3. **Limited Context** – Using **neither imports nor strings** (`no_imports_no_strings`).  

For each binary, we collect **three responses per LLM**, corresponding to these context levels.  

### 🔹 Automated Result Evaluation  
Our testing framework automatically:  
- Extracts LLM-generated responses.  
- Checks if the predicted technique **matches the expected MITRE technique**.  
- Generates statistics summarizing LLM performance.  

## 📂 Folder Structure  

### 📁 `sources/`  
Contains all source code samples used in the evaluation. It has two subfolders:  
- **`manual/`** – Hand-written C++ source files.  
- **`all_sources/`** – Contains all **auto-generated** and **manual** sources, categorized into three folders based on their purpose:  
    - **`MITRE/`** – Sources that contain MITRE techniques.  
    - **`deceptive/`** – Sources designed to trick the LLM into false detection.  
    - **`trivial/`** – Simple sources that should not trigger MITRE detection.  

### 📁 `assistants_results/`  
Stores LLM-generated responses and evaluations. The results are also categorized into three folders:  
- **`MITRE/`** – Results for sources that contain MITRE techniques.  
- **`deceptive/`** – Results for sources designed to mislead the LLM.  
- **`trivial/`** – Results for sources that should be correctly identified as benign.  

Each corresponding results folder contains:  
- **`output.json`** – Extracted results from LLM responses, including a `"valid"` list for correct answers.  
- **LLM-specific response files** – Separate files storing **complete, partial, and limited context** evaluations for each model.  

### 📄 `MitreOperations.csv`  
The **core dataset** used for source generation and technique evaluation. It contains:  
- A list of **MITRE techniques**  
- The **command-line execution format** for each technique  

### 📄 `statistics.data`  
A summary of all experiments, including:  
- **Total binaries analyzed**  
- **Success rates** per LLM and per evaluation context  
- **MITRE techniques detected** by each model  

## 📊 Example of Collected Results (from `statistics.data`)

**Problems that contain MITRE:** 280

**Success rates:**

*   gemini (Complete Context): 65/280 (23.21%)
*   gemini\_yes\_imports\_no\_strings (Partial Context): 29/280 (10.35%)
*   gemini\_no\_imports\_no\_strings (Limited Context): 9/280 (3.21%)
*   gpt4o (Complete Context): 98/280 (35.0%)
*   gpt4o\_yes\_imports\_no\_strings (Partial Context): 24/280 (8.47%)
*   gpt4o\_no\_imports\_no\_strings (Limited Context): 11/280 (3.92%)

**MITRE techniques detected:**

**Total techniques:** 21

*   T1003: {gemini, gpt4o}
*   T1053: {gemini, gpt4o}
*   T1056: {gemini}
*   T1059: {gemini, gpt4o}
*   T1082: {gemini, gpt4o}
*   T1083: {gemini, gpt4o}
*   T1105: {gemini, gpt4o}
*   T1106: {gpt4o}
*   T1113: {gpt4o}
*   T1124: {gpt4o}
*   T1136: {gemini, gpt4o}
*   T1489: {gpt4o}
*   T1547: {gemini, gpt4o}
*   T1562: {gemini, gpt4o}
*   T1564: {gpt4o}

**Empty techniques:** T1010, T1091, T1132, T1216, T1561, T1614 (6 techniques)

**Techniques summary:**

*   At least one technique detected: 15
*   Both models detected: 9
*   gemini detected: 10
*   gpt4o detected: 14
  

For additional statistics see the file: `statistics.data`.

For more details about the framework for automating source generation, building, and evaluation, refer to the [scripts component](../scripts/README.md).
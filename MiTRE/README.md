# MITRE Evaluation

## 📌 Purpose  
This study evaluates how well large language models (LLMs) can **recognize and identify MITRE ATT&CK techniques** in compiled binaries. The primary goal is to assess their ability to detect security-related functions and commands within **x86/x64 disassembly**.

## 🧪 Methodology  

### 🔹 MITRE Technique Selection  
We analyzed **MITRE techniques** that are relevant for binary analysis using **GView**, a binary visualization tool. The study focuses on techniques that could be **automatically extracted and evaluated** in compiled binaries.  

### 🔹 Source Code Generation  
A total of **280 C++ programs** were created, consisting of:  
- **33 hand-crafted sources**, manually written to ensure a variety of execution patterns.  
- **247 auto-generated sources** using the **MitreSourceGenerator** component.  

Each source represents a **command execution**, and our automation framework can generate variations of each command in **13 different ways** (details available in the `MitreSourceGenerator` component).  

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
- **`all_sources/`** – Contains all **auto-generated** and **manual** sources combined.  

### 📁 `assistants_results/`  
Stores LLM-generated responses and evaluations. Each MITRE technique has its own folder, containing:  
- **`output.json`** – Extracted results from LLM responses, including a `"valid"` list for correct answers.  
- **LLM-specific responses** – Separate files storing complete, partial, and limited context evaluations for each model.  

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

**Total problems:** 280

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
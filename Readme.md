# Assistants Experiements

Welcome to the repository for, where we showcase our work on automated source code generation using MITRE techniques and various data needed for the LLM prompts. 

This repository contains everything needed to reproduce, analyze, and extend our research.

## Folder Structure
This repository is structured into several key components:

### 📂 MITRE/
This folder contains all the information required for testing and analyzing results. It includes:  
- **MitreOperation.csv** – The key dataset used for source generation.  
- **Sources/** – A collection of manually and automatically generated source files.  
- **Responses/** – All responses obtained from the LLM, alongside the corresponding input data.  

For more details, refer to the [MITRE/README.md](MITRE/README.md).

### 📂 problems/
This folder focuses on **LLM-Based Naming Problems**, including:  
- A collection of naming problems used when querying LLMs for renaming variables, functions, and other identifiers.  
- Insights into how LLMs interpret, suggest, and modify code through renaming.  

For a deeper dive, check out the [problems/README.md](problems/README.md).

### 📂 scripts/
This folder contains the framework for automating source generation, building, and evaluation. It is divided into two main components:  
- **Source Generation/** – Scripts for automatically generating source code for testing.  
- **AssistantsTester/** – The main testing framework for evaluating LLM responses.  

More details are available in the [scripts/README.md](scripts/README.md).

### 📂 build/
This folder contains the **Visual Studio project** used to build all source files in this repository.  
- The **AssistantsTester** component (found in the `scripts/AssistantsTester/` folder) is designed to optimize the build process to generate the minimal binary.  
- Ensures reproducibility and easy deployment of the generated and manual code.

For more information, refer to the [build/README.md](build/README.md).

## 📖 Getting Started  

To explore more details about each component, please visit the respective README files inside each folder.

---

🚀 **Feel free to explore the repository and reach out with any questions**
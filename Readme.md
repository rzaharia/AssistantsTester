# Assistants Experiments

Welcome to the repository where we showcase our work on automated source code generation using MITRE techniques and various data needed for the LLM prompts. 

This repository contains everything needed to reproduce, analyze, and extend our research.

## Folder Structure
This repository is structured into several key components:

### 📂 MITRE/
This folder contains all the information required for testing and analyzing results. It includes:  
- **MitreOperation.csv** – The key dataset used for source generation.  
- **sources/** – A collection of manually and automatically generated source files.  
- **assistants_results/** – All responses obtained from the LLM, alongside the corresponding input data (the source code).  

For more details, refer to the [MITRE/README.md](MiTRE/README.md).

### 📂 scripts/
This folder contains the framework for automating source generation, building, and evaluation. It is divided into two main components:  
- **MitreSourceGenerator/** – Scripts for automatically generating source code for testing.  
- **AssistantsTester/** – The main testing framework for evaluating LLM responses.  

More details are available in the [scripts/README.md](scripts/README.md).

### 📂 build/
This folder contains the **Visual Studio project** used to build all source files in this repository.  
- The **AssistantsTester** component (found in the `scripts/AssistantsTester/` folder) is designed to optimize the build process to generate the minimal binary.  
- This folder also contains the necessary configuration files and instructions for ⬇️ obtaining and configuring GView, the tool used for analyzing the generated binaries.  See the sections below for details.

For more information, refer to the [build/README.md](build/README.md).

### 📂 problems/
This folder focuses on **LLM-Based Naming Problems**, including:  
- **sources** - A collection of naming problems used when querying LLMs for renaming variables, functions, and other identifiers.  
- **assistants_results/** – All responses obtained from the LLM, alongside the corresponding input data (the source code).   

For a deeper dive, check out the [problems/README.md](problems/README.md).


## ⬇️ Obtaining and Using GView

To analyze the generated binaries, you will need GView. You can either download the pre-built binaries or build GView yourself by following the instructions provided in the [build/README.md](build/README.md).

For detailed guidance on configuring and using GView, refer to the [build/README.md](build/README.md).

## 📖 Getting Started  

To explore more details about each component, please visit the corresponding README files inside each folder.

---

🚀 **Feel free to explore the repository and reach out with any questions**

# Build System and Configuration

This folder contains the build system and configuration files necessary to compile all source code files used in this project. It ensures reproducibility and simplifies the deployment of both generated and manually written code.

## 📁 build_projects/

This directory houses the Visual Studio project files (`.vcxproj`) used for building all source code related to our experiments.

## ⚙️ Configuration Files

- **GView.ini:** This configuration file is essential for running GView and must be placed in the same directory as the GView executable.  

    - **LLM API Keys:** To test the LLMs (Gemini and GPT), you **must** populate the `GView.ini` file with the appropriate API keys.  Locate the relevant sections within the file and enter your keys.
    - **Automation Script Compatibility:** If you intend to use the automation scripts, you **must** uncomment the `"Size"` entry within the `[AppCUI]` category of the `GView.ini` file.  This setting is required for the scripts to function correctly.

## ⬇️ Obtaining GView

The GView binaries required for this project can be downloaded from the following link: [https://github.com/gdt050579/GView/releases/tag/0.365.0](https://github.com/gdt050579/GView/releases/tag/0.365.0)
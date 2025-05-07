# Build System and Configuration

This folder contains the build system and configuration files necessary to compile all source code files used in this project. It ensures reproducibility and simplifies the deployment of both generated and manually written code.

## 📁 build_projects/

This directory houses the Visual Studio project files (`.vcxproj`) used for building all source code related to our experiments.

## ⚙️ Configuration Files

- **GView.ini:** This configuration file is essential for running GView and must be placed in the same directory as the GView executable.  

    - **LLM API Keys:** To test the LLMs (Gemini and GPT), you **must** populate the `GView.ini` file with the appropriate API keys.  Locate the relevant sections within the file and enter your keys.
    - **Automation Script Compatibility:** If you intend to use the automation scripts, you **must** uncomment the `"Size"` entry within the `[AppCUI]` category of the `GView.ini` file.  This setting is required for the scripts to function correctly.

## ⬇️ Obtaining GView

### Using already existing binaries

The GView binaries required for this project can be downloaded from the following link: [https://github.com/gdt050579/GView/releases/tag/0.368.0](https://github.com/gdt050579/GView/releases/tag/0.368.0)

### Build it yourself

To build GView from source, you will need the following tools installed on your system:

- **CMake**  
- **Git**  
- **C++ Compiler** (e.g., g++ or clang++)  

Follow these steps to build GView:

1. Clone the GView repository, including its submodules, by running:  
```bash
git clone --recurse-submodules https://github.com/gdt050579/GView.git
```

2. Navigate to the cloned repository and generate the build files using CMake:
```bash
cd GView
cmake -B build
```

3. Build the project by running:
```bash
cmake --build build
```

4. Once the build process is complete, navigate to the `bin` directory where the compiled files are located:
```bash
cd build/bin/Debug
    or
cd build/bin/Release
```

5. Run the GView executable.
   
You now have a fully functional version of GView built from source. For already built binaries see the previous step from above.
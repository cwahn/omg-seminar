# omg-seminar
OMG embedded programming seminar

## Requirements

### Git

1. **Download Git:**
   - Go to the Git website: [https://git-scm.com/download/win](https://git-scm.com/download/win)
   - The download should start automatically. If it doesn't, click on the link to download manually.

2. **Install Git:**
   - Run the downloaded `.exe` file.
   - Follow the installation prompts. Accept the default settings unless you have specific preferences.

3. **Verify Installation:**
   - Open the Command Prompt or Git Bash and type `git --version` to ensure it was installed correctly.

### VSCode with C++ Programming

1. **Download Visual Studio Code:**
   - Visit [https://code.visualstudio.com/](https://code.visualstudio.com/) and download the stable build for Windows.

2. **Install Visual Studio Code:**
   - Run the installer and follow the instructions.

3. **Install the C++ Extension:**
   - Open VSCode.
   - Go to the Extensions view by clicking on the Extensions icon in the Activity Bar on the side of the window or by pressing `Ctrl+Shift+X`.
   - Search for "C++" and install the extension by Microsoft called "C/C++".

### CMake

1. **Download CMake:**
   - Go to [https://cmake.org/download/](https://cmake.org/download/).
   - Under "Binary distributions", download the Windows `.msi` installer.

2. **Install CMake:**
   - Run the `.msi` file.
   - Follow the installation prompts, and select the option to add CMake to the system PATH.

3. **Verify Installation:**
   - Open a Command Prompt and type `cmake --version`.

### PlatformIO

PlatformIO is an open-source ecosystem for IoT development and can be installed as a Visual Studio Code extension.

1. **Install PlatformIO Extension:**
   - Open VSCode.
   - Go to the Extensions view (`Ctrl+Shift+X`).
   - Search for "PlatformIO".
   - Install the PlatformIO IDE extension.

2. **Verify Installation:**
   - Restart VSCode.
   - The PlatformIO icon should appear on the Activity Bar.
   - Click on it to open the PlatformIO Home and start a new project or import an existing one.

These steps should help you install all the necessary tools for the OMG embedded programming seminar. Always check the official documentation for each tool for the most up-to-date installation instructions.

### Catch2

Catch2 is a header-only test framework for C++, so it doesn't need to be installed like traditional software. In this case, it will be automatically added as Git submodule and you can integrate it with CMake.


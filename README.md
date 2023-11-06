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

---

## PlatformIO
To start an Arduino IDE project for the ESP32 with PlatformIO, you need to follow these steps:

### 1. Install PlatformIO Core

You should already have PlatformIO Core installed as a Visual Studio Code extension if you followed the previous guide. If not, please refer to the guide above to install it.

### 2. Start a New Project

- Open Visual Studio Code.
- Click on the PlatformIO icon in the Activity Bar on the left side.
- In the PlatformIO Home tab, click on "New Project".

### 3. Configure the New Project

- Enter a name for your project.
- Select "Espressif ESP32 Dev Module" from the board list. If you have a different ESP32 module, select the one that matches your hardware.
- Select "Arduino" as the framework.
- Choose the location where you want the project to be saved.
- Click "Finish".

PlatformIO will set up a new project with the necessary configuration files and directory structure.

### 4. Writing a Basic GPIO Program

Here is an example of a basic GPIO program that blinks an LED connected to GPIO 2 on the ESP32, which is a common built-in LED pin for many development boards.

First, navigate to the `src` directory of your PlatformIO project and create a file named `main.cpp` (PlatformIO should create this file by default). Then, write the following program:

```cpp
#include <Arduino.h>

#define LED_PIN 2 // Use the correct pin number for your ESP32 board's built-in LED

void setup() {
  pinMode(LED_PIN, OUTPUT); // Initialize the LED pin as an output
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // Turn the LED on
  delay(1000);                // Wait for a second
  digitalWrite(LED_PIN, LOW);  // Turn the LED off
  delay(1000);                // Wait for a second
}
```

### 5. Build and Upload the Program

- Save your `main.cpp` file.
- Click on the PlatformIO icon in the Activity Bar.
- Under the "Project Tasks" menu, expand your project's environment.
- Click on "Build" to compile your project.
- After the build process is successful, connect your ESP32 to the computer via USB.
- Click on "Upload" to upload the program to your ESP32 board.

If everything is set up correctly, the LED on your ESP32 board should start blinking.

### Troubleshooting

If you encounter any issues, make sure:

- Your ESP32 board is connected to the correct USB port.
- The correct drivers for the USB-to-Serial chip on your ESP32 board are installed on your computer.
- The board and port settings in `platformio.ini` match your actual hardware configuration.

The `platformio.ini` file should look something like this for an ESP32 Dev Module:

```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
```

This file tells PlatformIO which board and framework to use when building your project. If you're using a different ESP32 board, you would replace `esp32dev` with the identifier for your specific board.
# 📱 PROJECT COMPUTER ENGINEERING: "DEVELOPING GRAPHIC USER INTERFACE LIBRARY FOR ESP32 EMBEDDED PLATFORM USING LVGL"

## 🔍 PROJECT OVERVIEW

This project involves developing a full-featured graphical user interface (GUI) and control system for the ESP32-S3 embedded platform. It demonstrates how to integrate hardware-level components with the **LVGL (Light and Versatile Graphics Library)** to build a touchscreen-based, real-time interactive system.

### ✅ Key Features

- 🔧 **Platform**: ESP32-S3 with a 7-inch capacitive touchscreen LCD.
- 🌡️ **Sensor Integration**: Connected a **DHT20 temperature and humidity sensor** using a **dedicated I2C_NUM_1** channel, to avoid conflicts with the touchscreen controller (I2C_NUM_0).
- 🧩 **Multi-Bus Architecture**: Independently managed multiple I2C buses for seamless peripheral communication.
- 🎨 **LVGL-based UI**: Designed a responsive and interactive graphical user interface using LVGL for real-time data display and device control.
- ⚙️ **FreeRTOS-based Tasking**: Utilized FreeRTOS for parallel handling of UI updates, sensor readings, and WebSocket communication.
- 🧠 **Direct ESP-IDF Integration**: Developed the system natively using **ESP-IDF** with **no reliance on Arduino abstraction layers**.
- 🔌 **Relay & GPIO Control**: Added relay switching and peripheral interfacing through UART & RS485 protocol.

---

## 🛠️ BUILD INSTRUCTIONS & GUI INTEGRATION WITH SQUARELINE

This section guides you through building the project, from GUI design with Squareline Studio to deploying your code using PlatformIO.

### 1. 📐 **Designing GUI with Squareline Studio**

1. Open **[Squareline Studio](https://squareline.io/)**.
2. Create a new project:
   - Set resolution: `320x240`.
   - Select LVGL version compatible with your ESP-IDF version.
   - Choose `Generic ESP32` as target if unsure.
3. Design your UI:
   - Add widgets like labels, buttons, charts, etc.
   - Set object names (e.g., `temp_label`, `humidity_label`).
4. Export project:
   - Go to `File > Export > Export C Code`.
   - Set output folder (e.g., `./components/ui`).
   - Copy or move the exported code to your PlatformIO project.

### 2. 💻 **Setting Up PlatformIO Project**

1. **Create Project**:
   - Open VS Code → PlatformIO → `New Project`.
   - Board: `Espressif ESP32-S3 Dev Module`.
   - Framework: `ESP-IDF`.
   - Project name: `esp32_s3_lvgl_gui`.

2. **Install Required Libraries**:
   - Install the following libraries via `platformio.ini`:
     ```ini
     lib_deps =
       lvgl/lvgl
       adafruit/DHT sensor library@^1.4.4
     ```

3. **Project Folder Structure**:
esp32_s3_lvgl_gui/
├── src/
│ └── main.cpp
├── include/
├── components/
│ └── ui/ ← Paste Squareline export here
├── platformio.ini

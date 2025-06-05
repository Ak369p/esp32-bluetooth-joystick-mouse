# 🖱️ ESP32 Bluetooth Joystick Mouse

This is a wireless **Bluetooth HID mouse** built using an **ESP32** and a **joystick module**. The ESP32 emulates a BLE mouse, and the joystick controls the cursor. A tactile button toggles between **cursor mode** and **scroll mode**, allowing flexible usage.

---

## 📦 Features

- 🎮 **Joystick-controlled cursor movement**
- 🔘 **Single button click → Left click**
- 🔁 **Double press the button → Toggle scroll mode**
- ⬆️⬇️ **Joystick Y-axis in scroll mode → Scroll up/down**
- 🔋 **Battery-powered for full wireless freedom**
- 🖥️ **Serial monitor debug messages**
- 💤 **Low power consumption when idle (future)**

---

## 🔌 Hardware Requirements

| Component               | Quantity |
|------------------------|----------|
| ESP32 Dev Module       | 1        |
| Analog Joystick Module | 1        |
| Tactile Push Button    | 1        |
| 18650 Li-ion / Li-Po Battery (3.7V) | 1        |
| TP4056 Charging Module | Optional |
| Wires, Breadboard      | As needed |

**Battery Voltage Input**:  
Connect 3.7V–6V to the **Vin** pin of ESP32. ESP32 has onboard voltage regulators.  
⚠️ Don’t exceed 6V input on `Vin`. For 8.5V or higher, use a **buck converter**.

---

## 🧠 How It Works

- Reads analog X and Y input from joystick
- Button debounce and double-press detection logic
- Toggles between:
  - **Movement Mode** (joystick controls cursor)
  - **Scroll Mode** (joystick controls scroll wheel)
- Sends HID reports over BLE using `BleMouse` library

---

## 🔧 Setup Instructions

### 1️⃣ Install Board and Drivers

- Install [ESP32 Board Support Package](https://github.com/espressif/arduino-esp32) via **Arduino IDE Board Manager**
- Select board: `ESP32 Dev Module`
- If your board uses **CH9102X** USB chip, install the driver from [WCH official site](http://www.wch.cn/downloads/CH9102XDRV_ZIP.html)

### 2️⃣ Install Required Library

- Download [**BleMouse by T-vK**](https://github.com/T-vK/ESP32-BLE-Mouse) manually
- Place it in: `Documents/Arduino/libraries/ESP32_BLE_Mouse/`

### 3️⃣ Wiring Diagram

| ESP32 Pin | Joystick | Button |
|-----------|----------|--------|
| GPIO 34   | VRx      |        |
| GPIO 35   | VRy      |        |
| GPIO 27   |          | One end of button |
| GND       | GND      | Other end of button |
| 3.3V      | VCC      |        |

---

## 🧪 Serial Monitor Output

- Shows current mode (Scroll / Move)
- Shows X/Y joystick values
- Indicates button clicks and mode toggling

![image](https://github.com/user-attachments/assets/cf81019c-7f12-46be-b8be-57fc6b1502a4)
![project_image](https://github.com/user-attachments/assets/66997b7d-81d5-4577-a383-603ca5348717)



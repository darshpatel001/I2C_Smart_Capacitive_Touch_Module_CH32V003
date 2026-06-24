# I2C Smart Capacitive Touch Module Using CH32V003

## Overview

This project implements a Smart Capacitive Touch Module using the WCH CH32V003 RISC-V microcontroller.

The module acts as an I2C Slave device capable of detecting multiple capacitive touch inputs and reporting touch states to an external master controller such as ESP32, STM32, Raspberry Pi, or other embedded systems.

The design enables creation of scalable smart switch panels, home automation touch interfaces, industrial control panels, and human-machine interfaces.

---

## Features

* Capacitive Touch Sensing
* I2C Slave Communication
* Multi-Key Touch Detection
* Low Cost Hardware Design
* CH32V003 RISC-V MCU
* Home Automation Integration
* Real-Time Touch State Reporting
* Interrupt Driven Communication
* Embedded C Firmware
* Modular Design

---

## Hardware Used

| Component             | Purpose               |
| --------------------- | --------------------- |
| CH32V003              | Main Controller       |
| Capacitive Touch Pads | User Input            |
| I2C Interface         | Communication         |
| Pull-Up Resistors     | I2C Bus               |
| ESP32/STM32           | I2C Master (Optional) |

---

## Development Environment

| Tool             | Purpose                 |
| ---------------- | ----------------------- |
| MounRiver Studio | Development IDE         |
| WCH Toolchain    | Compiler                |
| CH32V003         | Target MCU              |
| WCH-LinkE        | Programming & Debugging |

---

## System Architecture

```text
          +--------------------+
          | Touch Sensors      |
          +--------------------+
                     |
                     v

          +--------------------+
          | CH32V003 MCU       |
          | I2C Slave Device   |
          +--------------------+
                     |
                     |
                    I2C
                     |
                     v

          +--------------------+
          | ESP32 / STM32      |
          | I2C Master         |
          +--------------------+
                     |
                     v

          +--------------------+
          | Home Automation    |
          | Control Logic      |
          +--------------------+
```

---

## Working Principle

### Touch Detection

The CH32V003 continuously scans touch inputs.

When a user touches a sensor:

```text
Touch Pad
    |
    v
Touch Detected
    |
    v
Touch State Updated
```

---

### I2C Communication

The module operates as an I2C Slave.

Example:

```text
I2C Address : 0x08
```

When the master requests data:

```text
ESP32 Master
      |
      v
Read Touch Status
      |
      v
CH32V003 Slave
      |
      v
Return Touch State
```

---

## Touch Mapping Example

| Touch Key | Function       |
| --------- | -------------- |
| Key 1     | Light Control  |
| Key 2     | Fan Control    |
| Key 3     | Socket Control |
| Key 4     | Scene Control  |

---

## Firmware Modules

### Touch Sensing Module

#### touch_scan()

* Scans touch channels.
* Detects touch events.
* Updates touch status.

---

### I2C Slave Module

#### I2C_Slave_Init()

* Configures I2C peripheral.
* Sets slave address.

#### I2C_Event_Handler()

* Handles I2C transactions.
* Responds to master requests.

---

### Application Module

#### update_touch_state()

* Updates touch status register.

#### get_touch_status()

* Returns current touch state.

---

## Communication Protocol

### Read Touch Status

Master sends:

```text
START
ADDRESS + READ
```

Slave responds:

```text
0000 0101
```

Meaning:

```text
Touch 1 = Pressed
Touch 3 = Pressed
```

---

## Project Structure

```text
.
├── User/
│   ├── main.c
│   ├── i2c_slave.c
│   ├── ch32v00x_it.c│
├── README.md
└── LICENSE
```

---

## Build Instructions

### Open Project

```text
MounRiver Studio
```

### Build

```text
Project → Build Project
```

### Program Device

```text
CH32V003
```

using

```text
WCH-LinkE
```

---

## Integration Example

### ESP32 Master

```text
ESP32
  |
  | I2C
  |
CH32V003 Touch Module
```

### Home Assistant

```text
Touch Input
      |
      v
CH32V003
      |
      v
ESP32
      |
      v
Home Assistant
```

---

## Screenshots

Add screenshots of:

* PCB Design
* Touch Module Hardware
* Serial Debug Output
* I2C Communication Test
* Home Assistant Integration

---

## Demo Video

If uploaded to repository:

```markdown
## 🎥 Project Demo

[Watch Demo Video](./touch_module_demo.mp4)
```

If uploaded to YouTube:

```markdown
## 🎥 Project Demo

[Watch on YouTube](https://youtube.com/your_video_link)
```

---

## Concepts Demonstrated

* Embedded C
* RISC-V Microcontrollers
* CH32V003 Development
* Capacitive Touch Sensing
* I2C Protocol
* I2C Slave Implementation
* Interrupt Handling
* Firmware Design
* Home Automation Hardware

---

## Applications

* Smart Switch Panels
* Home Automation
* Touch Interfaces
* Industrial HMIs
* Appliance Control Panels
* IoT Devices

---

## Future Improvements

* RGB Touch Feedback
* Multi-Gesture Support
* Touch Sensitivity Calibration
* EEPROM Configuration Storage
* I2C Command Protocol Extension
* Wireless Integration

---

## Learning Outcomes

Through this project, I gained practical experience in:

* CH32V003 Programming
* RISC-V Architecture
* Capacitive Touch Design
* I2C Slave Development
* Embedded Firmware Design
* Hardware Interface Development

---

## Author

**Darsh Patel**

Electronics & Communication Engineer

Firmware Engineer | Embedded Systems | IoT Developer

GitHub: https://github.com/darshpatel001

---

## License

This project is licensed under the MIT License.

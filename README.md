# 🏠 IoT Smart Security & Light Control System

<div align="center">

![IoT Security](https://img.shields.io/badge/IoT-Security-blue?style=for-the-badge&logo=shield&logoColor=white)
![ESP32](https://img.shields.io/badge/ESP32-WiFi-red?style=for-the-badge&logo=espressif&logoColor=white)
![MQTT](https://img.shields.io/badge/MQTT-Protocol-green?style=for-the-badge&logo=mqtt&logoColor=white)
![Wokwi](https://img.shields.io/badge/Wokwi-Simulation-orange?style=for-the-badge&logo=wokwi&logoColor=white)

_An intelligent IoT-based security and lighting system using ESP32 and cloud connectivity_

</div>

---

## 📋 Table of Contents

- [🎯 Aim](#-aim)
- [❗ Problem Statement](#-problem-statement)
- [🔍 Scope of the Solution](#-scope-of-the-solution)
- [📖 Project Description](#-project-description)
- [✨ Features](#-features)
- [🛠️ Required Components](#-required-components)
- [📚 Libraries Used](#-libraries-used)
- [📊 System Flowchart](#-system-flowchart)
- [🔌 Simulated Circuit](#-simulated-circuit)
- [🎥 Demo Video](#-demo-video)
- [📁 Project Structure](#-project-structure)
- [📡 MQTT Configuration](#-mqtt-configuration)
- [🌐 Wokwi Development](#-wokwi-development)
- [📄 License](#-license)
- [🤝 Contributing](#-contributing)

---

## 🎯 Aim

To develop an intelligent IoT-based Smart Security and Light Control System that provides automated home security monitoring with intelligent lighting management through cloud connectivity, enabling remote monitoring and real-time alerts for enhanced home automation and security.

---

## ❗ Problem Statement

Traditional home security systems face several limitations:

- **🔒 Limited Connectivity**: Most security systems operate independently without internet connectivity
- **💡 Manual Light Control**: Conventional lighting systems require manual operation and lack automation
- **📱 No Remote Monitoring**: Inability to monitor home security status remotely
- **⚡ High Energy Consumption**: Lights remain on unnecessarily, leading to energy wastage
- **🔔 Delayed Alerts**: Security breaches are detected only when physically present
- **💰 High Cost**: Commercial security systems are expensive and require professional installation

---

## 🔍 Scope of the Solution

Our IoT Smart Security & Light Control System addresses these challenges by providing:

### 🛡️ **Security Enhancement**

- Real-time motion detection using PIR sensors
- Instant cloud-based alert notifications
- Remote monitoring capabilities through web dashboard
- Historical data logging for security analysis

### 💡 **Intelligent Lighting**

- Automatic light control based on ambient conditions
- Motion-triggered lighting activation
- Energy-efficient operation with smart scheduling
- Remote lighting control via cloud platform

### 🌐 **Cloud Integration**

- MQTT protocol for reliable data transmission
- Adafruit IO platform for data visualization
- Real-time status updates and remote control
- Mobile and web accessibility

### 🎯 **Target Applications**

- Residential home security
- Small office monitoring
- Educational IoT projects
- Smart home automation systems

---

## 📖 Project Description

This IoT Smart Security & Light Control System is an intelligent home automation solution that combines security monitoring with automated lighting control. The system uses ESP32 microcontroller with WiFi connectivity to provide real-time monitoring and control through cloud-based MQTT communication via Adafruit IO platform.

### 🎯 Key Objectives

- **🔐 Smart Security**: PIR motion sensor-based intrusion detection system
- **💡 Intelligent Lighting**: Automated light control based on ambient conditions and motion
- **📱 Remote Monitoring**: Cloud-based monitoring and control through Adafruit IO
- **⚡ Real-time Alerts**: Instant notifications for security events

---

## 🛠️ Required Components

### 🔧 **Hardware Components**

| Component                      | Quantity | Specifications                     | Purpose                                |
| ------------------------------ | -------- | ---------------------------------- | -------------------------------------- |
| ESP32 Development Board        | 1        | WiFi + Bluetooth, 32-bit dual-core | Main microcontroller with connectivity |
| PIR Motion Sensor (HC-SR501)   | 1        | Detection range: 3-7m, Angle: 120° | Human movement detection               |
| LDR (Light Dependent Resistor) | 1        | 5-200kΩ resistance range           | Ambient light sensing                  |
| LED (Red)                      | 1        | 5mm, 20mA forward current          | Security alert indicator               |
| LED (White/Yellow)             | 1        | 5mm, 20mA forward current          | Automatic lighting control             |
| Resistors                      | 3        | 220Ω (2x), 10kΩ (1x)               | Current limiting and pull-up           |
| Breadboard                     | 1        | Half-size or full-size             | Circuit prototyping                    |
| Jumper Wires                   | 15-20    | Male-to-male                       | Component connections                  |

### 💻 **Software Requirements**

| Software                 | Version                 | Purpose                                        |
| ------------------------ | ----------------------- | ---------------------------------------------- |
| **Wokwi Editor**         | Latest                  | Online circuit simulation and code development |
| **Web Browser**          | Modern (Chrome/Firefox) | Accessing Wokwi platform and Adafruit IO       |
| **Adafruit IO Platform** | Cloud Service           | MQTT broker and data visualization             |
| **WiFi Network**         | 2.4GHz supported        | Internet connectivity for ESP32                |

### ☁️ **Cloud Environment**

| Service           | Provider            | Purpose                            | Cost                       |
| ----------------- | ------------------- | ---------------------------------- | -------------------------- |
| **Adafruit IO**   | Adafruit Industries | MQTT broker, data feeds, dashboard | Free tier available        |
| **WiFi Internet** | Local ISP           | Network connectivity               | User's existing connection |
| **Web Dashboard** | Adafruit IO         | Remote monitoring interface        | Included in service        |

---

## 📊 Flowchart

![System Flowchart](images/flowchart.png)

### 🔄 **Process Flow Description**

1. **🔌 System Initialization**: ESP32 boots up and initializes all components
2. **📶 WiFi Connection**: Establishes connection to local WiFi network
3. **☁️ Cloud Connection**: Connects to Adafruit IO MQTT broker
4. **📊 Sensor Reading**: Continuously monitors PIR and LDR sensors
5. **🚨 Alert Generation**: Triggers security alerts on motion detection
6. **💡 Light Control**: Automatically controls lighting based on ambient conditions
7. **📤 Data Transmission**: Sends sensor data and status to cloud platform
8. **📊 Dashboard Update**: Real-time updates on Adafruit IO dashboard

---

## 🔌 Simulated Circuit

![Wokwi Circuit Simulation](wokwi-circuit-diagram.png)

_Complete circuit diagram from Wokwi simulation - Image to be added_

### 🔗 **Component Connections**

| Component       | ESP32 Pin       | Wire Color | Description                    |
| --------------- | --------------- | ---------- | ------------------------------ |
| PIR Sensor VCC  | 3.3V            | Red        | Power supply                   |
| PIR Sensor GND  | GND             | Black      | Ground connection              |
| PIR Sensor OUT  | GPIO 12         | Yellow     | Motion detection signal        |
| LDR Pin 1       | 3.3V via 10kΩ   | Red        | Power through pull-up resistor |
| LDR Pin 2       | GPIO 34 (ADC)   | Green      | Analog input for light sensing |
| LDR Pin 2       | GND             | Black      | Ground connection              |
| Alert LED (+)   | GPIO 2 via 220Ω | Red        | Security status indicator      |
| Alert LED (-)   | GND             | Black      | Ground connection              |
| Control LED (+) | GPIO 4 via 220Ω | Blue       | Automatic light control        |
| Control LED (-) | GND             | Black      | Ground connection              |

### ⚙️ **Circuit Features**

- 🔌 **Power Supply**: 3.3V from ESP32 for all components
- 🛡️ **Protection**: Current limiting resistors for LEDs
- 📡 **Communication**: Digital and analog GPIO pins
- 🔧 **Expandable**: Additional GPIO pins available for future enhancements

---

## 🎥 Demo Video

[![IoT Smart Security System Demo](https://img.shields.io/badge/▶️-Watch%20Demo%20Video-red?style=for-the-badge&logo=youtube&logoColor=white)](https://youtube.com/your-demo-video-link)

_Complete system demonstration video - Link to be added_

---

## 📁 Project Structure

```
IoT-Smart-Security-System/
├── 📁 src/
│   ├── 📄 main.ino                 # Main Arduino sketch
│   ├── 📄 wifi_config.h            # WiFi configuration
│   ├── 📄 mqtt_config.h            # MQTT/Adafruit IO config
│   └── 📄 sensor_functions.h       # Sensor handling functions
├── 📁 simulation/
│   ├── 📄 wokwi-project.json       # Wokwi project configuration
│   └── 📄 diagram.json             # Circuit diagram data
├── 📁 images/
│   └── 📄 circuit-diagram.png      # Circuit schematic
│   └── 📄 flowchart.png            # flowchart of the code
├── 📄 README.md                    # Project documentation
├── 📄 LICENSE                      # MIT License
└── 📄 .gitignore                   # Git ignore rules
```

---

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---

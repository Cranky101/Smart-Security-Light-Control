# Smart Security & Light Control System

## Internet of Things (IoT) Project

### Aim
To design and simulate a smart home automation system that:
- Detects human movement using a PIR sensor.
- Monitors ambient light using an LDR sensor.
- Automatically controls lighting based on motion detection and low-light conditions.
- Sends real-time alerts to the cloud (Adafruit IO) via MQTT when motion is detected in low light.

---

### Problem Statement
In modern smart homes, energy efficiency and security are key concerns. The system aims to:
- Detect human presence using a PIR sensor.
- Sense ambient light using an LDR sensor.
- Automatically switch lights on/off based on detected motion and light conditions.
- Notify users via cloud (Adafruit IO) when a person is detected in a dark environment.

---

### Scope of the Solution
- Automate light control to improve energy efficiency.
- Enhance home security by alerting the owner about movement in dark conditions.
- Use IoT technologies (ESP32 + Wi-Fi + MQTT + Adafruit IO).
- Simulate the circuit in **Wokwi**.

---

### Required Components

#### Hardware
- ESP32 microcontroller with Wi-Fi
- PIR motion sensor
- LDR sensor (light-dependent resistor)
- LED (simulating a bulb/lamp)
- Resistors (as required for LDR circuit)

#### Software
- Arduino IDE (for ESP32 code)
- Wokwi (for circuit simulation)
- Adafruit IO (for cloud-based dashboard and alerts)

#### Cloud Platform
- Adafruit IO (via MQTT protocol)

---

### Flowchart
*(Include your flowchart image or link here)*

---

### Code Structure


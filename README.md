# ESP32-C3-Embedded-Control-System
ESP32-C3 embedded system project with traffic light logic, ultrasonic distance measurement, analog sensor processing and PWM control.


## Project Overview
This project was developed as part of a first-semester embedded systems course.  
It demonstrates fundamental microcontroller concepts using the ESP32-C3.

The system integrates:
- Traffic light control logic
- Analog sensor processing (potentiometer)
- Ultrasonic distance measurement (HC-SR04)
- PWM-based LED brightness control

---

## Hardware Components

- ESP32-C3 Dev Module
- 3 LEDs (Red, Yellow, Green)
- Potentiometer (analog input)
- HC-SR04 Ultrasonic Sensor
- Jumper wires
- Breadboard

---

## Pin Configuration

| Component | ESP32-C3 Pin |
|-----------|--------------|
| Green LED | GPIO10 |
| Yellow LED | GPIO2 |
| Red LED | GPIO3 |
| Potentiometer (Data) | GPIO0 |
| Ultrasonic Trigger | GPIO19 |
| Ultrasonic Echo | GPIO18 |

---

## Implemented Features

### 1. Traffic Light Logic
Implements a 4-phase traffic light sequence:
- Red
- Red-Yellow
- Green
- Yellow

Demonstrates digital output control and timing using `delay()`.

---

### 2. Analog Sensor Processing
Reads potentiometer values via ADC (`analogRead()`).

- Value range: 0–4095
- LED output depends on sensor value (if/else logic)

Demonstrates:
- Analog-to-Digital Conversion (ADC)
- Conditional control structures

---

### 3. Ultrasonic Distance Measurement
Uses HC-SR04 sensor to measure distance.

- Trigger pulse generation
- Echo time measurement (`pulseIn()`)
- Distance calculation:
  
  distance = runtime × 0.017

Demonstrates:
- Time-of-flight measurement
- Basic signal processing

---

### 4. PWM LED Dimming
Controls LED brightness using PWM.

- Brightness range: 0–255
- Automatic dimming using `for` loops
- Demonstrates duty-cycle control

---

## Technical Concepts Applied

- GPIO configuration
- Digital vs. Analog signals
- ADC (Analog-to-Digital Conversion)
- PWM (Pulse Width Modulation)
- Embedded C++ programming
- Sensor integration
- Structured program design (setup / loop architecture)

---

## How to Run

1. Install Arduino IDE
2. Install ESP32 board package
3. Select "ESP32C3 Dev Module"
4. Upload the code
5. Open Serial Monitor (9600 baud)

---

## Learning Outcome

This project demonstrates practical understanding of:
- Hardware-software interaction
- Real-time signal handling
- Embedded system control logic
- Structured debugging in microcontroller environments

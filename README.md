# On-Demand Traffic Light Control System

> **Educational Project Notice**
> This project was developed as an educational embedded systems application using AVR microcontrollers and Embedded C programming. The system demonstrates traffic light sequencing, pedestrian request handling, timer-based control, interrupt-driven events, LED interfacing, and real-time embedded system behavior.

## Overview

The On-Demand Traffic Light Control System is an embedded application designed to simulate a smart pedestrian traffic light system.

The system manages:

* Vehicle traffic lights
* Pedestrian crossing requests
* Safe traffic state transitions
* Timer-controlled LED sequencing
* Interrupt-driven button handling

The project demonstrates practical embedded systems concepts including:

* GPIO programming
* External interrupt handling
* Timer-based scheduling
* LED control
* State machine implementation
* Real-time embedded firmware development
* Embedded traffic management logic

The implementation was developed in Embedded C using low-level AVR register programming.

---

# Features

* Traffic light sequencing system
* Pedestrian crossing request support
* External interrupt handling
* Timer-controlled state transitions
* Vehicle and pedestrian LED indicators
* Real-time traffic control behavior
* GPIO peripheral control
* Embedded state machine logic
* Interrupt-driven pedestrian requests
* Modular embedded firmware architecture

---

# Technologies Used

* Embedded C
* AVR Microcontroller Programming
* GPIO Programming
* Timer Modules
* External Interrupts
* LED Interfacing
* State Machine Design
* Eclipse CDT
* AVR-GCC

---

# Hardware Components

The project was designed using:

* AVR Microcontroller
* LEDs for Vehicle Traffic Lights
* LEDs for Pedestrian Signals
* Push Button
* Timer Peripheral
* Breadboard and Embedded Circuit Components
* Power Supply

---

# System Architecture

The project follows a modular embedded system structure.

| Module                     | Responsibility                      |
| -------------------------- | ----------------------------------- |
| Traffic Light Controller   | Manages traffic light states        |
| Pedestrian Request Handler | Processes crossing requests         |
| Timer Module               | Controls timing intervals           |
| Interrupt Module           | Detects button presses              |
| GPIO Driver                | Controls LEDs and button pins       |
| Main Application           | Coordinates overall system behavior |

---

# Project Structure

```text
On-demand-Traffic-light-control-main/
│
├── On Demand Traffic Light Control/
│   ├── main.c
│   ├── led.c
│   ├── led.h
│   ├── button.c
│   ├── button.h
│   ├── timer.c
│   ├── timer.h
│   ├── interrupt.c
│   ├── interrupt.h
│   ├── gpio.c
│   ├── gpio.h
│   ├── std_types.h
│   └── common_macros.h
```

---

# Traffic Light Operation

The system controls two traffic flows:

* Vehicle traffic lights
* Pedestrian crossing lights

### Vehicle Light Sequence

| State   | Vehicle Light |
| ------- | ------------- |
| Stop    | Red           |
| Prepare | Yellow        |
| Move    | Green         |

### Pedestrian Logic

When the pedestrian button is pressed:

* Vehicle traffic is safely stopped
* Pedestrian crossing signal activates
* Traffic resumes after pedestrian crossing duration ends

---

# Pedestrian Request Handling

The project supports:

```text
On-demand pedestrian crossing requests
```

using an external push button.

When the button is pressed:

1. Interrupt is triggered
2. Current traffic state is evaluated
3. Safe transition sequence is executed
4. Pedestrian crossing phase starts
5. Normal traffic operation resumes afterward

This simulates a real-world smart pedestrian crossing system.

---

# External Interrupt Handling

The system uses external interrupts to detect pedestrian requests immediately.

### Interrupt Features

| Feature            | Purpose                   |
| ------------------ | ------------------------- |
| External Interrupt | Detect button press       |
| ISR Execution      | Process request instantly |
| Real-Time Response | Avoid polling delays      |

Example ISR:

```c
ISR(INT0_vect)
```

This enables:

* Fast response time
* Efficient CPU usage
* Real-time embedded behavior

---

# Timer-Based Control

Timers are used to:

* Control traffic light durations
* Handle LED blinking intervals
* Synchronize state transitions
* Implement crossing delays

Example timing behaviors:

```text
Green LED Duration
Yellow LED Blinking
Red LED Waiting Period
```

This demonstrates:

* Real-time scheduling
* Embedded timing management
* Deterministic system behavior

---

# LED Control

The project uses LEDs to simulate:

* Vehicle traffic lights
* Pedestrian crossing indicators

### LED States

| LED Color | Meaning           |
| --------- | ----------------- |
| Red       | Stop              |
| Yellow    | Prepare / Warning |
| Green     | Go                |

The LED drivers support:

* ON/OFF control
* LED blinking
* State synchronization

Example functions:

```c
LED_on()
LED_off()
LED_toggle()
```

---

# GPIO Programming

The project uses reusable GPIO drivers for:

* LED control
* Button input handling
* Peripheral interfacing
* Pin direction configuration

This demonstrates:

* Low-level embedded programming
* Hardware abstraction techniques
* Modular firmware design

---

# State Machine Logic

The traffic control behavior is implemented using:

```text
Finite State Machine (FSM)
```

Example states include:

* Vehicle Green
* Vehicle Yellow
* Vehicle Red
* Pedestrian Crossing

The system transitions between states according to:

* Timer events
* Interrupt requests
* Traffic control rules

---

# Core Embedded Concepts Demonstrated

This project demonstrates several important embedded systems concepts:

* External interrupts
* Timer-based scheduling
* State machine implementation
* LED interfacing
* GPIO programming
* Real-time embedded systems
* Interrupt-driven design
* Embedded firmware architecture
* Hardware/software integration

---

# Program Workflow

```text
Initialize Peripherals
          ↓
Start Normal Traffic Sequence
          ↓
Monitor Pedestrian Button
          ↓
Interrupt Triggered on Button Press
          ↓
Execute Safe Traffic Transition
          ↓
Enable Pedestrian Crossing
          ↓
Resume Normal Traffic Operation
```

---

# Development Environment

The project was developed using:

* Eclipse CDT
* AVR-GCC Compiler
* Embedded C

Included libraries:

```c
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
```

---

# How to Build and Run

## 1. Clone the Repository

```bash
git clone https://github.com/MahmoudEhabMorsy/On-demand-Traffic-light-control.git
```

## 2. Open the Project

Import the project into:

* Eclipse CDT
* Atmel Studio
* Microchip Studio

## 3. Compile the Project

Using AVR-GCC:

```bash
avr-gcc main.c led.c button.c timer.c interrupt.c gpio.c -o traffic_control.elf
```

## 4. Flash to AVR Microcontroller

Upload the firmware using:

* USBasp
* AVRDUDE
* Atmel Programmer

## 5. Connect Hardware

Ensure proper connection of:

* Traffic LEDs
* Push button
* AVR microcontroller pins

---

# Example Functional Behavior

## Normal Traffic Operation

```text
Vehicle Green LED ON
Pedestrian Red LED ON
```

## Pedestrian Request Activated

```text
Vehicle Red LED ON
Pedestrian Green LED ON
```

After the crossing duration:

```text
Normal Traffic Sequence Resumes
```

---

# Educational Value

This project provides practical experience with:

* Embedded systems development
* AVR microcontroller programming
* Real-time traffic control systems
* Interrupt-driven applications
* Timer and GPIO programming
* State machine design
* Embedded firmware architecture

It serves as an excellent practical introduction to:

* Smart traffic management systems
* Embedded control systems
* Real-time embedded applications

---

# Possible Future Improvements

Potential enhancements include:

* LCD/OLED traffic display
* Vehicle detection sensors
* Adaptive traffic timing
* RTOS integration
* Wireless traffic monitoring
* Smart city integration
* Multiple intersection support
* Emergency vehicle priority handling
* IoT connectivity
* Mobile application integration

---

# Known Limitations

* Educational prototype implementation
* Simplified traffic control logic
* Single intersection support
* No real vehicle sensing
* Limited user interface

---

# Software Design Highlights

The project emphasizes:

* Modular embedded driver architecture
* Interrupt-driven system behavior
* State machine implementation
* Real-time embedded responsiveness
* Clean hardware abstraction

---

# Author

Developed by:

* Mahmoud Ehab

---

# License

This project is provided for educational and learning purposes.

You are free to study, modify, and extend the implementation for academic or personal use.

---

# Acknowledgments

Special thanks to:

* AVR embedded systems documentation
* Embedded systems learning communities
* Open-source firmware development resources
* Educational embedded systems platforms

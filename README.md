# Multi Ultrasonic in One Microcontroller

This project demonstrates how to connect and operate **multiple ultrasonic sensors (HC-SR04)** using **a single microcontroller**—specifically an **AVR-based ATmega32**. The setup captures distance measurements from four directions and displays the real-time results on a 16x2 LCD.

## 🚀 Key Features

- 📏 Real-time distance measurement from **four directions**
- 🔄 **Sequential triggering** to prevent cross-sensor interference
- ⏱️ Utilizes **Timer** and **External Interrupts** for precise echo capture
- 📺 Real-time updates displayed on a **16x2 character LCD**
- 🧩 Modular code structure for easy portability and scalability
- 📐 Measures and displays distances in **centimeters**
- 🔌 Supports up to **4 ultrasonic sensors** on a single microcontroller
- ⚙️ Efficient, interrupt-driven design ensures minimal latency
- 💡 Optimized for obstacle detection, navigation, and embedded automation


## 🧰 Hardware Requirements

- ATmega32 microcontroller
- 4x HC-SR04 ultrasonic distance sensors
- 16x2 LCD display
- 5V Power Supply
- Breadboard + jumper wires

## 🖥️ Pin Configuration ( Follow the Proteus Design File )

| Ultrasonic Sensor | Trigger Pin | Echo Pin |
|-------------------|-------------|----------|
| Front             | PC0         | ICR PIN       |
| Back              | PC1         | ICR PIN       |
| Left              | PC2         | ICR PIN      |
| Right             | PC3         | ICR PIN     |
| LCD               | PORTA (Data)| RS/EN as needed |

## ⚙️ How It Works

The system reads distance measurements from four **HC-SR04 ultrasonic sensors** using a single microcontroller (e.g., ATmega32) by leveraging **sequential triggering** and **external interrupts** for accurate echo timing.

### 🔁 Step-by-Step Operation

1. **Trigger Sequence**  
   The microcontroller activates the **Trigger pin** of the first ultrasonic sensor by sending a 10μs HIGH pulse.

2. **Echo Detection via Interrupt**  
   The sensor sends out an ultrasonic pulse and waits for it to bounce back from an object. The returning signal is received via the **Echo pin**, which is connected to an external interrupt pin on the MCU.

3. **Timing the Echo**  
   The microcontroller starts a timer when the Echo pin goes HIGH and stops it when the pin goes LOW, measuring the time-of-flight in microseconds.

4. **Distance Calculation**  
   The measured time is used to calculate the distance using the standard formula:

5. **Display Output**  
The result is displayed on a **16x2 character LCD** for each sensor (front, back, left, right), showing real-time distance values.

6. **Repeat for All Sensors**  
The process is repeated for the remaining three sensors in sequence with slight delays to avoid ultrasonic signal overlap and interference.

### 🧠 Technical Highlights

- **Timer Module**: Used for precise timing of echo pulse durations.
- **External Interrupts**: Handle echo pulse detection to ensure non-blocking, accurate timing.
- **LCD Module**: Continuously updated to reflect real-time distances from all directions.
- **Sequential Control**: Only one sensor is active at a time to prevent interference.

This design ensures accurate, reliable measurements while minimizing processing overhead and hardware complexity.

## 🗂️ File Structure

Multi_Ultrasonic_in_one_MC/

├── src/

│   ├── main.c               # Main application code

│   ├── ultrasonic.c         # Functions for ultrasonic sensor control

│   ├── ultrasonic.h         # Header for ultrasonic.c

│   ├── lcd.c                # LCD interface functions

│   └── lcd.h                # Header for lcd.c

│

├── include/                 # Optional: common headers

│   └── config.h             # Pin definitions and global macros

│

├── docs/

│   └── schematic.png        # Circuit diagram or schematic image

│

├── Makefile                 # Build instructions for AVR-GCC

├── README.md                # Project documentation

├── LICENSE                  # License (e.g., MIT)

└── .gitignore               # Ignore build files or hex outputs



## 🔧 How to Build

This project is written in C and compiled using **AVR-GCC**. You can use tools like:

- **Atmel Studio**
- **AVRDUDE** + **AVR-GCC** + **Makefile**
- **Proteus** (for simulation)

## 🛠️ Getting Started

### 🔽 Clone the Repository

```bash
git clone https://github.com/Adham-amr-1/Multi_Ultrasonic_in_one_MC.git
cd Multi_Ultrasonic_in_one_MC

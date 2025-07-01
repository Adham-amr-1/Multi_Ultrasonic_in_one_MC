# Multi Ultrasonic in One Microcontroller

This project demonstrates how to connect and operate **multiple ultrasonic sensors (HC-SR04)** using **a single microcontroller**—specifically an **AVR-based ATmega32**. The setup captures distance measurements from four directions and displays the real-time results on a 16x2 LCD.

## 🚀 Features

- Supports **4 ultrasonic sensors** connected to one microcontroller
- Measures and displays distances in **centimeters**
- Real-time update on **16x2 character LCD**
- Uses **Timer** and **External Interrupts** for precise echo capture
- Efficiently avoids sensor interference via sequential triggering

## 🧰 Hardware Requirements

- ATmega32 microcontroller
- 4x HC-SR04 ultrasonic distance sensors
- 16x2 LCD display
- 5V Power Supply
- Breadboard + jumper wires

## 🧠 How It Works

Each ultrasonic sensor is triggered sequentially, and its echo signal is captured using external interrupts or polling. The time duration is then converted to distance using the speed of sound formula:


## 🗂️ File Structure

- `main.c` – Main logic to initialize peripherals and run the measurement loop
- `LCD.c/.h` – LCD control functions (initialize, print, clear, etc.)
- `Ultrasonic.c/.h` – Handles ultrasonic sensor triggering and echo timing

## 🔧 How to Build

This project is written in C and compiled using **AVR-GCC**. You can use tools like:

- **Atmel Studio**
- **AVRDUDE** + **AVR-GCC** + **Makefile**
- **Proteus** (for simulation)

### Example Make Command

```bash
avr-gcc -mmcu=atmega32 -Os main.c LCD.c Ultrasonic.c -o ultrasonic.elf
avr-objcopy -O ihex ultrasonic.elf ultrasonic.hex
avrdude -c usbasp -p m32 -U flash:w:ultrasonic.hex

# Day 04 – LED Blink on PA4 Using TIM2 Delay (Bare-Metal STM32F401RE)

## 🔧 Description
This project demonstrates how to blink an LED connected to **PA4** on the STM32F401RE Nucleo board using a custom delay function implemented via **TIM2** (Timer 2) at the register level. No HAL or CMSIS is used.

## 📅 Date
05-July-2025

## 🧠 Concepts Covered
- Timer Initialization using RCC and TIM2
- Using Prescaler and Auto-Reload Register (ARR) to generate delays
- Polling the UIF (Update Interrupt Flag) to create blocking delay
- Bit manipulation for GPIO and Timer configuration

## 🛠️ Hardware Used
- STM32F401RE Nucleo Board
- Onboard LED connected to **PA4**

## 📂 Files
- `Led_Blink_TIM2.c` – Main bare-metal code file

## ⚙️ Working
- PA4 is configured as a general-purpose output.
- TIM2 is used to generate a 1000 ms (1 second) delay using polling on the UIF bit.
- The LED toggles ON and OFF every 1 second.

## 🖼️ Output
- LED connected to **PA4** blinks ON for 1s, OFF for 1s continuously.

## 🔗 References
- [STM32F401RE Reference Manual (RM0368)](https://www.st.com/resource/en/reference_manual/dm00096844.pdf)
- [STM32F4xx Register Map](https://developer.arm.com/documentation/ddi0439/b/)

---

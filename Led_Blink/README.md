# Day 01 – Basic LED Blink Using GPIO (Bare-Metal STM32F401RE)

## 🔧 Description
This project demonstrates how to blink the onboard LED connected to **PA5** on the STM32F401RE using **pure register-level programming**. It’s a foundational exercise in understanding GPIO control using direct memory access with CMSIS headers.

## 📅 Date
30-June-2025

## 🧠 Concepts Covered
- Enabling peripheral clocks using `RCC->AHB1ENR`
- Configuring GPIO pin direction via `GPIOA->MODER`
- Controlling LED using `GPIOA->ODR`
- Using a basic `for` loop for delay (not timer-based)
- Bitwise operations in embedded C

## 🛠️ Hardware Used
- STM32F401RE Nucleo Board  
- Onboard Green LED → **PA5**

## 📂 Files
- `Led_Blink.c` – Main C file to blink LED using simple logic and delay loop

## ⚙️ Working
- PA5 is configured as output
- A `for()` loop creates a crude delay between toggles
- The LED turns ON for a short time, then OFF, continuously

## 🧠 Key Registers Used
- `RCC->AHB1ENR` – Enables clock for GPIOA  
- `GPIOA->MODER` – Configures PA5 as output  
- `GPIOA->ODR` – Writes HIGH/LOW output to LED pin

## 💡 Learning Outcomes
- Understood basic GPIO control at register level
- Learned how to enable and configure GPIOs in bare-metal
- Practiced low-level C for real-world hardware control

## 🔗 References
- [STM32F401RE Reference Manual (GPIO Section)](https://www.st.com/resource/en/reference_manual/dm00096844.pdf)
- [Nucleo-F401RE Board User Manual](https://www.st.com/resource/en/user_manual/dm00105823.pdf)

---

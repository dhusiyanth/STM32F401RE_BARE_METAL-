# Day 03 – Toggle LED Based on Button Press (Bare-Metal STM32F401RE)

## 🔧 Description
This project demonstrates how to toggle the onboard LED connected to **PA5** based on the state of the onboard **User Button (PC13)** using **CMSIS** and **bare-metal register-level programming** (no HAL).

## 📅 Date
17-June-2025

## 🧠 Concepts Covered
- Configuring GPIO pins as input and output using MODER
- Reading the input state using `IDR` (Input Data Register)
- Writing output using `ODR` (Output Data Register)
- Basic digital input/output interaction using bare-metal code
- Using conditional statements to control LED based on button status

## 🛠️ Hardware Used
- STM32F401RE Nucleo Board  
- Onboard User Button → PC13  
- Onboard Green LED → PA5

## 📂 Files
- `Button_With_LED.c` – Main C file for polling-based button control

## ⚙️ Working
- PC13 is configured as digital input (button)
- PA5 is configured as digital output (LED)
- The microcontroller continuously checks the state of PC13
- If the button is **pressed** (logic 0), the LED turns ON
- If the button is **released** (logic 1), the LED turns OFF

## 📌 Key Registers Used
- `RCC->AHB1ENR` – Enables GPIOA and GPIOC clocks  
- `GPIOx->MODER` – Configures PA5 as output, PC13 as input  
- `GPIOx->IDR` – Reads input from PC13  
- `GPIOx->ODR` – Controls output on PA5

## 🧠 Learning Outcomes
- Gained experience working with digital inputs and outputs using CMSIS
- Practiced bitwise operations and control logic in embedded systems
- Understood real-time polling technique for button-based input

## 🔗 References
- [STM32F401RE Reference Manual](https://www.st.com/resource/en/reference_manual/dm00096844.pdf)
- [STM32 Nucleo Board Datasheet](https://www.st.com/en/evaluation-tools/nucleo-f401re.html)

---

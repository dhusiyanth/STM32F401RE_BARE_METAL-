# Day 02 – LED Blink Using SysTick Timer (Bare-Metal STM32F401RE)

## 🔧 Description
This project demonstrates how to use the **SysTick timer** to generate precise 1ms interrupts and implement a non-blocking delay function. The LED connected to **PA5** toggles ON and OFF every 500 ms using the `SysTick_Handler()` and a global tick counter.

## 📅 Date
01-July-2025

## 🧠 Concepts Covered
- SysTick timer configuration for 1ms system tick
- Writing an interrupt service routine (`SysTick_Handler`) using CMSIS
- Creating a non-blocking delay function with a millisecond tick counter
- GPIO output control using `MODER` and `ODR` registers

## 🛠️ Hardware Used
- STM32F401RE Nucleo Board  
- Onboard LED (PA5)

## 📂 Files
- `Led_Blink_SysTick.c` – Bare-metal SysTick-based LED blink code

## ⚙️ Working
- The SysTick timer is configured to overflow every 1 millisecond
- The ISR (`SysTick_Handler`) increments a global `tick` counter
- A `delay(ms)` function checks elapsed time by comparing tick values
- The LED on **PA5** blinks every 500 ms

## 🧠 Key Registers Used
- `SysTick->LOAD`, `VAL`, `CTRL` – Configures the SysTick timer  
- `GPIOA->MODER`, `GPIOA->ODR` – Controls GPIO direction and output  
- `tick` – Global millisecond counter incremented in the ISR

## 💡 Learning Outcomes
- Learned how SysTick works in Cortex-M microcontrollers
- Practiced writing interrupt service routines using CMSIS
- Built a custom millisecond delay function without busy loops
- Strengthened understanding of register-level peripheral control

## 🔗 References
- [STM32F401RE Reference Manual (SysTick – Section 4)](https://www.st.com/resource/en/reference_manual/dm00096844.pdf)
- [Cortex-M4 Generic User Guide (SysTick section)](https://developer.arm.com/documentation/100166/latest)

---

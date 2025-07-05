# Day 04 – LED Toggle on Button Press using EXTI (Bare-Metal STM32F401RE)

## 🔧 Description
This project demonstrates how to configure an **external interrupt (EXTI)** on pin **PC13** to toggle an LED on **PA5** using STM32F401RE. The implementation uses pure CMSIS and register-level access — no HAL.

## 📅 Date
29-June-2025

## 🧠 Concepts Covered
- Configuring GPIO for input (PC13) and output (PA5)
- Setting up **SYSCFG** and **EXTI line 13** for external interrupt
- Mapping **PC13** to **EXTI13** using EXTICR
- Enabling **Falling Edge Trigger** for EXTI
- Writing **Interrupt Service Routine** (ISR) for EXTI15_10_IRQn
- Toggling GPIO pin inside ISR

## 🛠️ Hardware Used
- STM32F401RE Nucleo Board  
- Onboard user button (connected to PC13)  
- Onboard green LED (connected to PA5)

## 📂 Files
- `Interrupt_Button_EXTI.c` – Main bare-metal code file

## ⚙️ Working
- PC13 is configured as input, and PA5 as output.
- On **falling edge** (button press), **EXTI13** triggers an interrupt.
- ISR (`EXTI15_10_IRQHandler`) toggles the LED with a small delay for debouncing.
- The LED toggles ON/OFF on every button press.

## 🧠 Key Registers Used
- `RCC->AHB1ENR` – Enable GPIO clocks  
- `RCC->APB2ENR` – Enable SYSCFG clock  
- `SYSCFG->EXTICR` – Map PC13 to EXTI13  
- `EXTI->IMR` and `EXTI->FTSR` – Interrupt mask and falling edge trigger  
- `NVIC_EnableIRQ()` – Enable interrupt in NVIC  
- `EXTI->PR` – Clear pending interrupt flag

## 🔗 References
- [STM32F401RE Reference Manual](https://www.st.com/resource/en/reference_manual/dm00096844.pdf)  
- [CMSIS Documentation](https://developer.arm.com/tools-and-software/embedded/cmsis)

---


# Day 06 – Button Debounce Using EXTI + Timer2 (Bare-Metal STM32F401RE)

## 🔧 Description
This project demonstrates how to implement **debouncing logic** for a push button using **External Interrupt (EXTI)** and **Timer2 delay** in bare-metal STM32. When the user button on **PC13** is pressed, a small delay is introduced to eliminate bouncing effects, and an LED on **PA4** is toggled only after confirming the button is still pressed.

## 📅 Date
06-July-2025

---

## 🧠 Concepts Covered
- Configuring **GPIO** input (PC13) and output (PA4)
- Setting up **External Interrupt (EXTI)** for falling edge on PC13
- Writing an **Interrupt Service Routine (ISR)** for EXTI15_10
- Using **Timer2** for software-based debounce delay
- Verifying **button state after delay** for clean toggling

---

## 🛠️ Hardware Used
- STM32F401RE Nucleo Board  
- Onboard Button → **PC13**  
- External or onboard LED → **PA4**

---

## 📂 Files
- `Debounce_EXTI_TIM.c` – Bare-metal C code using EXTI + TIM2

---

## ⚙️ Working
- When the button connected to PC13 is pressed, it triggers an interrupt.
- Inside the ISR:
  - First, the **pending flag** is cleared
  - Then a **20ms delay** is introduced using Timer2
  - After the delay, the code **checks if the button is still pressed**
  - If yes, the LED on PA4 is toggled
- This logic helps prevent **false toggles** caused by button bouncing.

---

## 🧠 Key Registers Used
- `RCC->AHB1ENR` – Enable clocks for GPIOA and GPIOC  
- `SYSCFG->EXTICR` – Maps PC13 to EXTI13  
- `EXTI->IMR`, `FTSR`, `PR` – Masking, edge selection, and flag handling  
- `TIM2->PSC`, `ARR`, `SR`, `CNT` – Timer2 for debounce delay  
- `GPIOx->MODER`, `ODR`, `IDR` – Configure and control GPIO pins

---

## 💡 Learning Outcomes
- Learned how to debounce mechanical buttons using timer-based software delay
- Practiced integrating EXTI and TIM2 for real-world responsiveness
- Gained deeper control over Cortex-M4 NVIC and peripheral configuration
- Reinforced interrupt-safe programming with real-time pin state checking

---

## 🔗 References
- [STM32F401RE Reference Manual](https://www.st.com/resource/en/reference_manual/dm00096844.pdf)  
- [NVIC & EXTI Basics](https://developer.arm.com/documentation/100166/latest)  
- [Debouncing Guide – Embedded Systems](https://www.ganssle.com/debouncing-pt2.htm)

---

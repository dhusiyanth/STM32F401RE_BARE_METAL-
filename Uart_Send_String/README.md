# Day 07 – UART Transmission Using Bare-Metal (STM32F401RE)

## 🔧 Description
This project demonstrates how to perform **UART data transmission** using **register-level (bare-metal) programming** with CMSIS on the STM32F401RE. A custom function `uart_tx()` sends strings from the microcontroller to a serial terminal at **9600 baud rate** via USART2 (PA2).

## 📅 Date
08-July-2025

---

## 🧠 Concepts Covered
- UART basics and how serial communication works
- GPIO configuration for alternate function (AF7 for USART2)
- Clock enabling for USART2 and GPIOA
- Setting baud rate using the `BRR` register
- Writing a custom transmit function using polling
- Transmitting data byte-by-byte using `USART2->DR` and `SR` flags

---

## 🛠️ Hardware Used
- STM32F401RE Nucleo Board  
- UART TX Pin → **PA2**  
- USB to Serial Adapter (optional)  
- Serial Monitor (e.g., PuTTY, TeraTerm, RealTerm)

---

## 📂 Files
- `Uart_tx.c` – Main C file with CMSIS-based UART TX logic

---

## ⚙️ Working
- GPIOA Pin 2 is configured as **Alternate Function 7 (USART2 TX)**
- USART2 is enabled, and baud rate is configured to 9600
- A custom function `uart_tx()` sends strings one character at a time
- `USART2->SR`'s TXE flag is polled before sending each byte
- Message is printed repeatedly with a delay loop

Expected Serial Output:
Bare-Metal Programming using STM32F401RE


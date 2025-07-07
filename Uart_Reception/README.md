# UART Receive and Echo using Bare-Metal (STM32F401RE)

## 📁 File Name
`uart_rx_echo.c`

## 👨‍💻 Author
Dhusiyanth

## 🗓️ Date
09-July-2025

## 📝 Description
This project demonstrates how to **receive characters through UART (USART2)** and **echo them back** using bare-metal register-level programming with **CMSIS** on the STM32F401RE. Characters sent from a serial terminal are echoed back instantly via USART2.

---

## 📌 Key Concepts Covered
- Configuring GPIOA pins **PA2 (TX)** and **PA3 (RX)** for USART2 in alternate function mode  
- Setting **baud rate to 9600** using `USART2->BRR`  
- Enabling USART2 transmit and receive functionalities  
- Using polling to:
  - Wait for RXNE (Receive Not Empty) flag before reading  
  - Wait for TXE (Transmit Empty) flag before writing  
- Writing custom `Uart2_Tx()` and `Uart2_Rx()` functions

---

## ⚙️ How It Works
- User types a character in the serial terminal connected to USART2
- The character is received via `USART2->DR` and echoed back immediately
- Communication is **full-duplex** and handled entirely using polling (no interrupts)

---

## 🔧 Hardware Required
- STM32F401RE Nucleo Board  
- USB-to-Serial Converter (or onboard ST-LINK Virtual COM)  
- Serial Terminal Software (e.g., PuTTY, TeraTerm)  
- Jumper Wires (if using external UART pins)

| UART Function | STM32 Pin | Serial Pin |
|---------------|-----------|-------------|
| USART2_TX     | PA2       | RX          |
| USART2_RX     | PA3       | TX          |

---

## 💻 Software Tools Used
- Keil uVision 5  
- CMSIS (Core & Device Startup Files)

---

## 📊 Registers Used
| Peripheral | Registers |
|------------|-----------|
| RCC        | AHB1ENR, APB1ENR |
| GPIOA      | MODER, AFRL |
| USART2     | BRR, CR1, SR, DR |

---

## 🚀 Learning Outcomes
- Learned how to configure UART RX and TX manually using registers  
- Practiced polling technique to manage UART communication  
- Gained insight into real-time character-level echoing  
- Strengthened CMSIS-level understanding of USART2 in STM32

---

## 📂 Folder Structure

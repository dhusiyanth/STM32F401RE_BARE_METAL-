/*
 * File Name   : uart_rx_echo.c  
 * Author      : Dhusiyanth  
 * Description : UART Receive using Interrupt (Bare-Metal STM32F401RE)
 * Date        : 10-07-2025  
 */
#include "stm32f4xx.h"
void Uart2_Tx(const char *str)
{
	for(uint32_t i=0;str[i]!=0;i++)
	{
		while(!(USART2->SR & (1<<7)));
		USART2->DR = str[i];
	}
}

char Uart2_Rx(void )
{
	while(!(USART2->SR & (1<<5)));
	return USART2->DR;
}

int main()
{
	RCC->AHB1ENR  |=(1<<0); // Enabling the clock for GPIOA (A2->TX,A3->RX)
	RCC->APB1ENR  |=(1<<17);// Enabling the clock for UART
	
	GPIOA->MODER  &=~(3<<4)|(3<<6);// Clearing PORT A
	GPIOA->MODER  |= (2<<4)|(2<<6);// Setting up A2 as Alternate function - TX & RX
	
	GPIOA->AFR[0] &=~(0XF<<8)|(0XF<<12); // Clearing the Alternate function register
	GPIOA->AFR[0] |= (7<<8)|(7<<12); // Setting up the Alternate Register for AF7 (0111)
	
	USART2->BRR = ((16000000 + (9600 / 2)) / 9600);// Setting up Baud rate for 9600
	USART2->CR1   |= (1<<2); // Enabling the reception register
	USART2->CR1   |= (1<<3); // Enabling the Transmission register 
	USART2->CR1   |= (1<<13); // Enabling the Uart
	USART2->CR1   |= (1<<5); // Enabling the Interrupt for RX in UART2
	
	NVIC_EnableIRQ(USART2_IRQn); // Enabling UART2 interrupt in NVIC
	while(1)
	{
		 

	}
	
} 
void USART2_IRQHandler()
{
	char ch = Uart2_Rx();
  Uart2_Tx(&ch);  
}

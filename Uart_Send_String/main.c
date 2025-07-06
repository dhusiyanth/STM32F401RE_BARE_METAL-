/*
File Name   : Uart_tx.c  
Author      : Dhusiyanth  
Description : Transmitting Data using UART - BareMetal (CMSIS) 
Date        : 08-07-2025  
*/

#include "stm32f4xx.h"

void uart_tx(const char *str)
{
	for(uint32_t i=0;str[i]!=0;i++)
	{
		while(!(USART2->SR &(1<<7)));
		USART2->DR=str[i];
	}
}
int main()
{
	RCC->AHB1ENR |=(1<<0);  // Enabling clock for GPIOA
	RCC->APB1ENR |=(1<<17); // Enabling clock for UART2
	
	GPIOA->MODER &=~(3<<4); // Clearing PORT A
	GPIOA->MODER |= (2<<4); // Setting up PORTA for Alternate function (UART)
	
	GPIOA->AFR[0] &=~(0XF<<8); // Clearing the A2 for alternate function
	GPIOA->AFR[0] |= (7<<8);  // Clearing the A2 for alternate function
	
	USART2->BRR = ((16000000 + (9600 /2)) /9600); // Baud Rater for 9600
	USART2->CR1 |=(1<<3);    // Enabling the TX for UART
	USART2->CR1 |=(1<<13);   // Enabling UART2
	
	while(1)
	{
	  uart_tx("Bare-Metal Programming using STM32F401RE\r\n");
		for (volatile int i = 0; i < 1000000; i++); 
	}
}

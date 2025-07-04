/*
*File Name:Interrupt_Button(EXTI)
*Author: Dhusiyanth
*Description: Toggling the Led based on Button press using External Interrupt with CMSIS file
*Date:29-06-2025
*/


#include "stm32f4xx.h"
void delay(int time)
{
	while(time--);
}

int main()
{
	RCC->AHB1ENR |=(1<<0);  // Enabling Clock For PORTA
	RCC->AHB1ENR |=(1<<2);  // Enabling Clock For PORTC
	RCC->APB2ENR |=(1<<14); // Enabling Clock For Interrupt (SYSCFG)
	
	GPIOA->MODER &=~(3<<10); // Clearing A5
	GPIOA->MODER |=(1<<10);  // Setting A5 as Output
	
	GPIOC->MODER &=~(3<<26); // Setting C13 as Input
	
	// Interrupt configurations
	 
	EXTI->IMR |=(1<<13);  // Enabling Interrupt Mask
	EXTI->FTSR |=(1<<13); // Setting up the Falling Edge Configuration
	SYSCFG->EXTICR[3] &=~(0XF<<4); // Configuring the EXTI4(0,1,2,3) as Interrupt input
	SYSCFG->EXTICR[3] |=(1<<5);   // Setting the PC13 as Interrupt input
	NVIC_EnableIRQ(EXTI15_10_IRQn);// Enabling the NVIC for the interrupt from pin 10-15
	
	
	
	while(1)
	{

	} 
}
//Function for interrupt (Note:EXTI15_10_IRQHandler is fixed for NVIC and  should not change
void EXTI15_10_IRQHandler()
{
	if(EXTI->PR &(1<<13))
	{
		delay(500000);
		EXTI->PR |=(1<<13);
		GPIOA->ODR ^=(1<<5);
	}
	
}

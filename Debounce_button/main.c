/*
*File Name   : Debounce_EXTI_TIM
*Author      : Dhusiyanth
*Description : Led blink based on debounce of button using EXTI and TIMER (bare-metal STM32F401RE)
*Date        : 06-07-2025
*/

#include "stm32f4xx.h"
void delay(uint32_t ms);
int main()
{
	RCC->AHB1ENR |=(1<<0); // Enabling Clock for GPIOA
	RCC->AHB1ENR |=(1<<2); // Enabling Clock for GPIOC
	
	GPIOA->MODER &=~(3<<8); // Clearing PORT A
	GPIOA->MODER |= (1<<8); // Setting A4 as Output
	
	GPIOC->MODER &=~(3<<26);// Setting C13 as Output
	
	RCC->APB2ENR |=(1<<14); // Enabling clock for SYSCFG
	SYSCFG->EXTICR[3]=(2<<4); // Enabling EXTI for C13
	
	EXTI->IMR |=(1<<13); // UnMasking pin 13 
	EXTI->FTSR|=(1<<13); // Setting up for falling edge trigger
	
	NVIC_EnableIRQ(EXTI15_10_IRQn); // Enabling the NVIC for the interrupt from pin 10-15
	
	while(1)
	{

	}
	
}

	void EXTI15_10_IRQHandler()
	{
		if (EXTI->PR & (1 << 13))  // Check pending flag
			{
				EXTI->PR |= (1 << 13);  // Clear pending flag
				delay(20);
					// Confirm button still pressed (active low)
		if (!(GPIOC->IDR & (1 << 13)))
			{
							GPIOA->ODR ^= (1 << 4);  // Toggle LED
			}
			}
	}
void delay(uint32_t ms )
{
	RCC->APB1ENR |=(1<<0); // Enabling Clock for TIM2
	
	TIM2->PSC= 16000-1; // Setting up prescaler for timer
	TIM2->CR1 |=(1<<0); // Enabling Counter for TIM2
	TIM2->CNT =0; // Setting up Counter to 0 
	TIM2->ARR=ms-1; // Loading ARR with reqiured delay - 1
	
	while((TIM2->SR &(1<<0))==0); // Checking whether the UIF == 0
	
	TIM2->SR &=~(1<<0); // If UIF is 1 clearing the UIF 
		
}

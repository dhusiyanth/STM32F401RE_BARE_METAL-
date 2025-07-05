/*
*File Name   : Led_Blink_TIM2.c
*Author      : Dhusiyanth
*Description : Blinking LED on PA4 using Timer2 delay (bare-metal STM32F401RE)
*Date        : 05-07-2025
*/

#include "stm32f4xx.h"

void delay(uint32_t ms)
{
	RCC->APB1ENR |=(1<<0); // Enabling the clock for Timer2
  TIM2->CR1 |=(1<<0); // Enabling counter for Timer 2
	TIM2->CNT = 0; // Clearing the counter 
	TIM2->PSC = 16000-1; // Setting up the prescaler value for 1000ms
	TIM2-> ARR = ms-1; // Counts till the ms-1 value eg: 1000-1 = 999ms = 1 Sec 	
	
	while((TIM2->SR & (1<<0))==0); // Checking the status of UIF if 0 means continue if 1 means breaks out of loop
	
	TIM2->SR &=~(1<<0); // Resets UIF , If UIF=1 ,means it stops counting to enable again we should reset to 0 again
	
}
int main()
{
	RCC->AHB1ENR |=(1<<0); // Enabling the clock for GPIO
		
	GPIOA->MODER &=~(3<<8); // Clearing PORT A 
	GPIOA->MODER |= (1<<8); // Settingup A4 as Output
	
	while(1)
	{
		GPIOA->ODR |=(1<<4);
		delay(1000);
		GPIOA->ODR &=~(1<<4);
		delay(1000);
	}
}


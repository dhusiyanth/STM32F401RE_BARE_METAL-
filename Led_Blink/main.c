/*
 * File Name    : Led_Blink.c
 * Author       : Dhusiyanth M
 * Description  : Blinks an LED connected to PA5 using STM32F401RE in bare-metal (CMSIS) style
 * Date         : 16-06-2025
 */
#include"stm32f4xx.h"
void delay(int time)
{
	while(time--);
}
int main()
{
	RCC->AHB1ENR |=(1<<0);
	GPIOA->MODER &=~(3<<10);
	GPIOA->MODER |=(1<<10);
  
	
	while(1)
	{
		GPIOA->ODR ^=(1<<5);
		delay(1000000);
	}
}




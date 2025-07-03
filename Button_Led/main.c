/*
*File Name:Button With Led
*Author: Dhusiyanth
*Description: Toggling inbuilt  led based on  inbuilt button press with Bare-Metal using CMSIS file
*Date:17-06-2025
*/

#include "stm32f4xx.h"
int main()
{
RCC->AHB1ENR |=(1<<0); // Enabling Clock for PORTA
RCC->AHB1ENR |=(1<<2); // Enabling Clock for PORTC
	
GPIOA->MODER &=~(3<<10); // Resetting PORTA
	
GPIOA->MODER |=(1<<10); // Setting PORTA PIN5 As Output
GPIOC->MODER &=~(1<<26);// Setting PORTC PIN13 As INPUT

while(1)
{
	if ((GPIOC->IDR & (1 << 13)) == 0) // Checking condition for Button Press 
	{
		GPIOA->ODR|=(1<<5); // Turning on the led while button is pressed 
	}
	else
	{
		GPIOA->ODR&=~(1<<5); // Turning off the led when button is not pressed 
	}
}
}









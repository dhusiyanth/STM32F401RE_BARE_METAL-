/*
*File Name   : Led_Blink_SysTick.c  
*Author      : Dhusiyanth  
*Description : Blinking LED on PA5 using SysTick timer (bare-metal STM32F401RE)  
*Date        : 01-07-2025  
*/

#include "stm32f4xx.h"

volatile uint32_t tick = 0;  // Global millisecond counter

// SysTick interrupt handler – runs every 1ms
void SysTick_Handler(void)
{
    tick++;
}

// Simple millisecond delay function
void delay(uint32_t ms)
{
    uint32_t t = tick;
    while ((tick - t) < ms);
}

// GPIO Initialization
void GPIO_init(void)
{
    RCC->AHB1ENR |= (1 << 0);        // Enable clock for GPIOA
    GPIOA->MODER &= ~(3 << 8);      // Clear MODER5 bits
    GPIOA->MODER |=  (1 << 8);      // Set PA5 as output (01)
}

// SysTick Configuration for 1ms tick (16 MHz clock)
void SysTick_init(void)
{
    SysTick->LOAD  = 16000 - 1;      // 16MHz / 16000 = 1kHz -> 1ms
    SysTick->VAL   = 0;              // Clear current value
    SysTick->CTRL  = (1 << 2) |      // Enabling Clk source as Processor Clock
                     (1 << 1) |      // Enabling (TICKINT) for counting down to zero
                     (1 << 0);       // Enabling the Counter SysTick
}

int main(void)
{
    GPIO_init();     // Initialize PA5
    SysTick_init();  // Configure SysTick for 1ms interrupt

    while (1)
    {
        GPIOA->ODR |=  (1 << 4);  
        delay(500);             
        GPIOA->ODR &= ~(1 << 4);  
        delay(500);             
    }
}



#include "STM32F4xx.h"
#include "stm32f4xx_conf.h"
#include "stm32f4xx_gpio.h"

// pins
#define PORTLed				GPIOD
#define LedGreen			GPIO_Pin_12	
#define LedOrange			GPIO_Pin_13	
#define LedRed				GPIO_Pin_14	
#define LedBlue				GPIO_Pin_15	

void SysTick_Handler(void);
void delay_ms(uint16_t delay_t);

void init_GPIO(void);

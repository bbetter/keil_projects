#include "main.h"

GPIO_InitTypeDef GPIO_InitStructure;


/*---------------------------Interrupt Systick-------------------------------*/

uint16_t delay_c = 0;

void SysTick_Handler(void){
	if(delay_c > 0)
		delay_c--;
}
void delay_ms(uint16_t delay_t){
	delay_c = delay_t;
	while(delay_c){};
}


/* ------------------------ init gpio  --------------------------------- */
void init_GPIO()
{
	//tacting (to use some peripherals, need to tact them first)
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	// working only with red led ( 12 pin)
  GPIO_InitStructure.GPIO_Pin = LedRed;
	// out mode
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	//no pulls (don't no why)
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
}

uint16_t delay = 0;

int main(){

	/*--------------------------Init Clock------------------------------*/
	SystemCoreClockUpdate();                      /* Get Core Clock Frequency   */
  if (SysTick_Config(SystemCoreClock / 1000)) { /* SysTick 1 msec interrupts  */
    while (1);                                  
  }

	init_GPIO();
	while(1){
		GPIO_SetBits(PORTLed,LedRed);
		delay_ms(delay);
		GPIO_ResetBits(PORTLed,LedRed);
		delay_ms(delay)
		if(delay+500 < UINT16_MAX)
			delay=0;
		delay+=500;
	}
}

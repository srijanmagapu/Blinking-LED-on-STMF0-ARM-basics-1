/* #include <stm32f0xx.h>



int main(void)
{
	RCC ->AHBENR |=(1<<19);
	GPIOC ->MODER |=(1<<16);
	GPIOC ->ODR |=(1 << 8);

		while(1)
		{
			

    }
}		
*/

#include "stm32f0xx.h"

#define LED4        0x0100
#define LED3				0x0200
#define PushButton

GPIO_InitTypeDef        GPIO_InitStructure;



int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f0xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f0xx.c file
     */

  /* GPIOC Periph clock enable */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

  /* Configure PC8 and PC9 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	

	
ButtonRead = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_9);
	
	if(ButtonRead){ //If button is pressed, turn green LED on and blue off
     GPIO_SetBits(GPIOC, GPIO_Pin_9);
     GPIO_ResetBits(GPIOC, GPIO_Pin_8);
}
else{ //If button isn’t pressed, turn green LED off and blue on
     GPIO_ResetBits(GPIOC, GPIO_Pin_9);
     GPIO_SetBits(GPIOC, GPIO_Pin_8);
}

  while (1)
  {

		volatile int i;
		
    GPIOC->BSRR = LED3;
		GPIOC->BRR  = LED4;
		
 //   GPIOC->BRR  = LED3;
	//	GPIOC->BSRR = LED4;

  }
}

#ifdef  USE_FULL_ASSERT


void assert_failed(uint8_t* file, uint32_t line)
{

  while (1)
  {
  }
}
#endif

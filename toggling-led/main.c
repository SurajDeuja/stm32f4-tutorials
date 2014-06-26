#include "stm32f4xx_conf.h"

#include "stdio.h"

int main(int argc, char *argv[])
{
    	GPIO_InitTypeDef gpioInitStruct;
    	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

    	gpioInitStruct.GPIO_Pin   = GPIO_Pin_15 | GPIO_Pin_14;
    	gpioInitStruct.GPIO_Mode  = GPIO_Mode_OUT;
    	gpioInitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    	gpioInitStruct.GPIO_OType = GPIO_OType_PP;
    	gpioInitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    	GPIO_Init(GPIOD, &gpioInitStruct);

    	GPIOD->BSRRL = 0xF000;

	return 0;
}

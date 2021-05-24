# include "stm32f446xx.h"

// Create a function to wait for a specified amount of time

static void delay(int delay_time)
{
	volatile int i, j=0;   //volatile makes the i and j not to be optimized later in our code
	
	for(i=0; i<delay_time; i++)
	{
		j++;
	}
}

int main()
{
	// Sudo code 
	// Enable GPIO Clock for port A using  AHB and RCC
	
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	
	// Set any control registers for port c pin 5
	// Moder - mode type
	GPIOA->MODER |= GPIO_MODER_MODE5_0;
	//GPIOA->MODER &= ~(GPIO_MODER_MODE5_1);
	
	//OTyper
	GPIOA->OTYPER &= ~(GPIO_OTYPER_OT_5);
	
	//OSpeedr
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR5;
	
	//PUPDR 
	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR5);
	
	while(1)
	{
		// Turn on LED
		// USE BSRR
		GPIOA->BSRR |= GPIO_BSRR_BS_5;
		//wait
		delay(900000);
		
		//Turn off LED
		//Use BRR
		GPIOA->BSRR |= GPIO_BSRR_BR_5;
		//Wait		
		delay(100000);
	}
}

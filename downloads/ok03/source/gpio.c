#include <sys/types.h>
#define GPIO_BASE 0x20200000 //538968064 in decimal

/* Base address of Function Select Register 1 */
#define GPIO_PIN_FUNC (GPIO_BASE+4)

/* Base address of Output Set Register 0 */
#define GPIO_PIN_ON (GPIO_BASE+28)

/* Base address of Output Clear Register 0 */
#define GPIO_PIN_OFF (GPIO_BASE+40)

void SetGpioFunction( register long int pinNum , register long int pinFunc);
void SetGpio(register long int pinNum , register long int pinVal  );

/*
*	Given GPIO pin number pinNum(0-53) and its operation pinFunc(0-7), 
*	the function define specified operation to that GPIO pin.
*/	
void SetGpioFunction( register long int pinNum , register long int pinFunc){
	register long int  gpioAddress = GPIO_BASE;
	/* Obtaining the address of the Function Select Register which controls the given pin number  */
	while(pinNum > 9){
		pinNum -= 10;
		gpioAddress += 4;
	}

	/* Defining the given pin function by setting the designated 3 bits of Function Select Register for the given pin number to pinFunc*/
	pinNum += pinNum << 1; 
	pinFunc = pinFunc << pinNum; 
	*((unsigned int *)(gpioAddress)) = pinFunc;
}

/*
*	Given GPIO pin number pinNum(0-53) and pin value which could be
*	either 0 or 1 for turning pin or off respectively.
*/
void SetGpio(register long int pinNum, register long int pinVal ){
	register long int gpioAddress = GPIO_BASE;
	register long int calculatePin;

	/* Multiplying the pinNum by 3 and adding it to the gpioAddress */
	calculatePin = pinNum >> 5; 
	calculatePin = calculatePin << 2; 
	gpioAddress += calculatePin;
	if(gpioAddress == GPIO_BASE){
		pinNum = pinNum & 31; 
		if(pinVal == 0)
			/* Setting the appropraite bit of Output Set Register to 1 to disable output to the given pin */
			*((unsigned int *)(GPIO_PIN_ON)) = 1 << pinNum; 
		else
			/* Setting the appropraite bit of Output Clear Register to 1 to disable output to the given pin */
			*((unsigned int *)(GPIO_PIN_OFF)) = 1 << pinNum; 
	}
}

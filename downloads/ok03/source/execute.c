#include <sys/types.h>

void execute(void);
 
/* Base address of Function Select Register 0 */
#define GPIO_BASE 0x20200000

/* Base address of Function Select Register 1 */
#define GPIO_PIN_FUNC (GPIO_BASE+4)

/* Base address of Output Set Register 0 */
#define GPIO_PIN_ON (GPIO_BASE+28)

/* Base address of Output Clear Register 0 */
#define GPIO_PIN_OFF (GPIO_BASE+40)

/*
*	The function repeatedly turn on and turn off the 16th GPIO pin
*/
void execute(void) {   
    register long int pinNum = 16;
    register long int counter = 0;
	/* Defining output operation to the 16th GPIO */
	SetGpioFunction(16,1);
	while(1==1){
		/* Turning on the ACT LED */
		SetGpio(pinNum,0); 

		/* Busy Waiting */
		counter = 0x3F0000; 
		while(counter--);

		/* Turning off the ACT LED */
		SetGpio(pinNum,1); 

		/* Busy Waiting */
		counter = 0x3F0000; 
		while(counter--);
	}
}





 

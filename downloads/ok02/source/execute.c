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
	register int counter = 0;

	/* Defining output operation to the 16th GPIO pin by setting bits 18-20 of Function select Register 1 to 001 */
    *((unsigned int *)(GPIO_PIN_FUNC)) = (1 << 18);

	while (1 == 1) {   

		/* Turning on the ACT LED */
		/* Clearing output to the 16th GPIO pin by setting the 16th bit of Ouput Clear Register 0 to 1*/
	    *((unsigned int *)(GPIO_PIN_OFF)) = (1 << 16); 

		/* Busy Waiting */
		counter = 0x3f0000; 
	    while (counter--);

		/* Turning off the ACT LED */
		/* Setting output to the 16th GPIO pin by setting the 16th bit of Ouput Set Register 0 to 1*/
	    *((unsigned int *)(GPIO_PIN_ON)) = ( 1 << 16 ); 

		/* Busy Waiting */
		counter = 0x3f0000; 
	    while (counter--);
    }
}	

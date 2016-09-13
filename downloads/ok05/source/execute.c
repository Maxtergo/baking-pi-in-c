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
*	The function turns on and off the ACT LED according to a specified pattern
*/
void execute(void){
	register long int pinNum = 16;
	/* Defining the pattern where each 1 in the pattern correspond to turning the ACT LED ON and 
	   each 0 correspond to turning the ACT LED OFF 
	*/
	static int pattern[32] = {1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0}; 
	register long int counter = 0;
	/* Setting the amount of time we want to delay in Micro seconds */
	register long int delay = 50000;
	/* Defining output operation to the 16th GPIO */
	SetGpioFunction(pinNum,1);
	while( 1 == 1 ){
		SetGpio(pinNum, pattern[counter]); //'On and Off' depends on pattern value
		Wait(delay);
		counter++;
		if(counter > 31){
			counter = 0; //Reset Counter
		}
	}
}

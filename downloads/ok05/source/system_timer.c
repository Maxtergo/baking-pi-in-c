#include <sys/types.h>
 
/* System timer base address */
#define SYSTEM_TIMER_BASE 0x20003000 

int GetTimeStamp(void) ;
void Wait(register long int delay);

/*
* The method returns the lower 32 bits of the current counter value
*/
int GetTimeStamp(void){
	register long int time = *( (unsigned int *)(SYSTEM_TIMER_BASE + 4) ); 
	return time;
}

/*
*	Given the amount of time to delay as input, the function waits
*	by using the System timer initial counter value and current 
*	counter value.
*	
*/
void Wait(register long int delay){
	register long int start, elapsed;

	/* Obatining the initial counter value. This value is obtained only once */
	start = GetTimeStamp();
	
	/* Obtaining the difference of the current counter value and the initial counter value */
	elapsed = ( GetTimeStamp() - start );

	/* Waiting untill the difference of the current counter value and the initial counter value is less then the time to delay */
	while( elapsed <= delay ){
		elapsed = (GetTimeStamp() - start);
	}
}

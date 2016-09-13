#include <sys/types.h>

int Random(register long int xnm);

/* 
* Random is a function with an input of the last number it generated, and an 
* output of the next number in a pseduo random number sequence.
*/
int Random(register long int xnm){
	register long int result = 61184;
	result = result*(xnm*xnm)+xnm+73;
	return result;
}
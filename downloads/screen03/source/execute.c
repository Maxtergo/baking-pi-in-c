#include <sys/types.h>

void execute();

void execute(){
	/* Obtaining pointer to the Frame Buffer Structure */
	int fbInfoAddress = InitialiseFrameBuffer(1024, 768, 16);
	/* Checking whether the frame buffer is a failed one or not */
	if( fbInfoAddress != 0 ){
		/* Drawing the string at the given location */
		DrawString("Ashar is a good and obedient boy\t bakwas ",0,0);
	}
	/* If the frame buffer is a failed one */
	else{
		/* Turning the ACT LED ON */
		SetGpioFunction(16,1);
		SetGpio(16, 0);
	}
	/* Loop forever */
	while(1);
}

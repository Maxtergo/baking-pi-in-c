#include <sys/types.h>

void execute();

void execute(){
	/* Obtaing the address of the frame buffer structure */
	int fbInfoAddress = InitialiseFrameBuffer(1024, 768, 16);
	/* if GPU has accepted our request to create a frame buffer then*/
	if( fbInfoAddress != 0 ){
		int fbAddr, y=0, x=0, color;
		while( 1 ){
			/* Obtaing the pointer to the frame buffer from the fram buffer structure */
			fbAddr = *((unsigned int*)(fbInfoAddress+32));
			y = 768;
			while( y != 0 ){
				x = 1024;
				while( x != 0 ){
					/* Drwaing the pixel by putting in the color information at location pointed by frame buffer */
					*((unsigned int*)(fbAddr)) = color;
					fbAddr = (fbAddr+2);
					x = x-1;
				}
				y = y-1;
				/* Changing the color */
				color = color+1;
			}
		}
	}
	/* If GPU has denied our request to create a fram buffer then */
	else{
		/* Turn on the ACT LED */
		SetGpioFunction(16,1);
		SetGpio(16, 0);
		while(1);
	}
}

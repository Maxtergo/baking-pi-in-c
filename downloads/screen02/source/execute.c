#include <sys/types.h>

void execute();

void execute(){
	/* Obtaing the address of the frame buffer structure */
	int fbInfoAddress = InitialiseFrameBuffer(1024, 768, 16);
	/* Checking whether the frame buffer is a failed one or not */
	if( fbInfoAddress != 0 ){
		unsigned int y=0, x=0,lastRandom=0,lastX=0,lastY=0,color=0;
		while( 1 ){
			/* Obtaing new coordinates on the basis of old */
			x = Random(lastRandom);
			y = Random(x);
			lastRandom = y;

			/* Chaging the color */
			color = color + 1;
			color = color << 16;
			color = color >> 16;
			SetForeColour(color);

			/* Preventing the coodrinates from going out of range */
			x = x >> 22;
			y = y >> 22;
			
			if(y < 768){
				/* Drawing a line between the given coordinates */
				DrawLine(lastX,lastY,x,y);
				lastX = x;
				lastY = y;
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

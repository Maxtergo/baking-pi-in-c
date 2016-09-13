#include <sys/types.h>

#define FB_ADDR 0x5000

int InitialiseFrameBuffer(int paramWidth, int paramHeight, int paramBitDepth);

/* NEW
* InitialiseFrameBuffer creates a frame buffer of width , height and bit depth
* specified in paramaters, and returns a FrameBuferDescription
* which contains information about the frame buffer returned. 
*/

int InitialiseFrameBuffer(int paramWidth, int paramHeight, int paramBitDepth){
	register long int fbiAddress = 0;
	int result = 0;
	fbiAddress = FB_ADDR;
	*((unsigned int*)(fbiAddress+0)) = 1024; // Width
	*((unsigned int*)(fbiAddress+4)) = 768; // Height
	*((unsigned int*)(fbiAddress+8)) = 1024; // vWidth
	*((unsigned int*)(fbiAddress+12)) = 768; // vHeight
	*((unsigned int*)(fbiAddress+16)) = 0; // GPU Pitch
	*((unsigned int*)(fbiAddress+20)) = 16; // Bit Depth
	*((unsigned int*)(fbiAddress+24)) = 0; // X
	*((unsigned int*)(fbiAddress+28)) = 0; // Y
	*((unsigned int*)(fbiAddress+32)) = 0; // GPU Pointer
	*((unsigned int*)(fbiAddress+36)) = 0; // GPU Size
	if( paramWidth<=4096 && paramHeight<=4096 && paramBitDepth<=32 ){
		*((unsigned int*)(fbiAddress+0)) = paramWidth;
		*((unsigned int*)(fbiAddress+4)) = paramHeight;
		*((unsigned int*)(fbiAddress+8)) = paramWidth;
		*((unsigned int*)(fbiAddress+12)) = paramHeight;
		*((unsigned int*)(fbiAddress+20)) = paramBitDepth;
		
		MailboxWrite( fbiAddress+0x40000000, 1 );
		
		result = MailboxRead(1);
		
		if( result != 0 ){
			result = 0;
			return result;
		}else{
			result = fbiAddress;
			return result;
		}
	}else{
		result = 0;
		return result;
	}
}

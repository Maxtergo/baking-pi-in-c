#include <sys/types.h>

/* Base address for frame buffer structure */
#define GRAPHIC_ADDRESS 0x5000

/* The foreColour is the colour which all our methods will draw shapes in */
#define FORE_COLOR 0xFFFF

void SetForeColour(unsigned short int color);
void DrawPixel(unsigned int px,unsigned int py);
void DrawLine(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1);


/* 
* SetForeColour changes the current drawing color to the 16 bit colour in paramater color.
*/
void SetForeColour(unsigned short int color){
	if(color >= 0x10000){
		return;
	}
	*((unsigned short int*)(FORE_COLOR)) = color;
}

/* 
* DrawPixel draws a single pixel to the screen at the point in (px,py).
*/
void DrawPixel(unsigned int px,unsigned int py){
	register long int address = GRAPHIC_ADDRESS;
	int height = *((unsigned int*)(address+4));
	height = height - 1 ;
	if( py > height ){
		return;
	}
	int width = *((unsigned int*)(address+0));
	width = width - 1;
	if( px > width ){
		return;
	}
	address = *((unsigned int*)(address+32));
	width = width + 1;
	px = (py * width) + px;
	address = address + (px << 1);
	*((unsigned short int*)(address)) = *((unsigned short int*)(FORE_COLOR));;
}

/*	Draws a line between points (px1,py1) and (px2,py2)
	Uses Bresenham's Line Algortihm
*/
void DrawLine(unsigned int x0,unsigned int y0,unsigned int x1,unsigned int y1){

	int dx=0, sx=0, dyn=0, sy=0, err=0;

	if( x0 > x1 ){
		dx = x0 - x1;
		sx = -1;
	}else{
		dx = x1 - x0;
		sx = 1;
	}

	if( y0 > y1 ){
		dyn = y1 - y0;
		sy = -1;
	}else{
		dyn = y0 - y1;
		sy = 1;
	}

	err = dx + dyn;
	x1 = x1 + sx;
	y1 = y1 + sy;

	while( 1 ){
		if( x0 == x1 || y0 == y1 ){
			return;
		}
		DrawPixel( x0, y0 );	
		if( dyn <= (err << 1) ){
			err = err + dyn;
			x0 = x0 + sx;
		}
		if( dx >= (err << 1) ){
			err = err + dx;
			y0 = y0 + sy;
		}
	}
}

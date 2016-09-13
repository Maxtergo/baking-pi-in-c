#include <sys/types.h>

/* Base address for frame buffer structure */
#define GRAPHIC_ADDRESS 0x5000

/* The foreColour is the colour which all our methods will draw shapes in */
#define FORE_COLOR 0xFFFF

/*
*   The two dimensional array is just a bit map font for ASCII characters
*	The font is monospace monochrome font where each character is essentially 
*	8*16 pixel where each pixel is one bit in size. The size for each 
*	character is 16 bytes
*/
unsigned char font_bin[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x08, 0x08,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x14, 0x14, 0x14, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x48,
  0x68, 0xfe, 0x24, 0x24, 0x7f, 0x14, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x10, 0x7c, 0x92, 0x12, 0x1c, 0x70, 0x90, 0x92, 0x7c,
  0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x09, 0x46, 0x38,
  0x66, 0x90, 0x90, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38,
  0x04, 0x04, 0x0c, 0x92, 0xb2, 0xa2, 0x46, 0xbc, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x10, 0x10, 0x20, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x08, 0x08,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x0c, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x10, 0x92, 0x7c, 0x38, 0xd6, 0x10, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x7f,
  0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x08, 0x04, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
  0x20, 0x20, 0x10, 0x10, 0x18, 0x08, 0x08, 0x04, 0x04, 0x02, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x38, 0x44, 0x82, 0x82, 0x92, 0x82, 0x82, 0x44, 0x38,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c,
  0xc2, 0x80, 0x80, 0x40, 0x30, 0x18, 0x04, 0xfe, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7c, 0x82, 0x80, 0xc0, 0x38, 0xc0, 0x80, 0xc2, 0x7c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x50, 0x58, 0x48, 0x44,
  0x42, 0xfe, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e,
  0x02, 0x02, 0x3e, 0xc0, 0x80, 0x80, 0xc2, 0x3c, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x78, 0x84, 0x02, 0x7a, 0xc6, 0x82, 0x82, 0xc4, 0x78,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x40, 0x40, 0x20, 0x20,
  0x10, 0x18, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c,
  0x82, 0x82, 0x82, 0x7c, 0x82, 0x82, 0x86, 0x7c, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x3c, 0x46, 0x82, 0x82, 0xc6, 0xbc, 0x80, 0x42, 0x3c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00,
  0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x18, 0x18, 0x08, 0x04, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x70, 0x0e, 0x0e, 0x70, 0x80, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00,
  0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x02, 0x1c, 0xe0, 0xe0, 0x1c, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x1c, 0x22, 0x20, 0x10, 0x08, 0x08, 0x00, 0x08, 0x08,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xcc, 0x84, 0xe2, 0x92,
  0x92, 0x92, 0xe2, 0x04, 0x0c, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
  0x28, 0x28, 0x28, 0x44, 0x44, 0x7c, 0xc6, 0x82, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7e, 0x82, 0x82, 0x82, 0x7e, 0x82, 0x82, 0x82, 0x7e,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x84, 0x02, 0x02, 0x02,
  0x02, 0x02, 0x84, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e,
  0x42, 0x82, 0x82, 0x82, 0x82, 0x82, 0x42, 0x3e, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xfe, 0x02, 0x02, 0x02, 0xfe, 0x02, 0x02, 0x02, 0xfe,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x02, 0x02, 0x02, 0xfe,
  0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78,
  0x84, 0x02, 0x02, 0xc2, 0x82, 0x82, 0x84, 0x78, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x82, 0x82, 0x82, 0x82, 0xfe, 0x82, 0x82, 0x82, 0x82,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x22, 0x1c, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x42, 0x22, 0x12, 0x0a, 0x0e, 0x12, 0x22, 0x22, 0x42,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02,
  0x02, 0x02, 0x02, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc6,
  0xc6, 0xaa, 0xaa, 0xaa, 0x92, 0x82, 0x82, 0x82, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x86, 0x86, 0x8a, 0x8a, 0x92, 0xa2, 0xa2, 0xc2, 0xc2,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x44, 0x82, 0x82, 0x82,
  0x82, 0x82, 0x44, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e,
  0xc2, 0x82, 0x82, 0xc2, 0x7e, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x38, 0x44, 0x82, 0x82, 0x82, 0x82, 0x82, 0x44, 0x78,
  0x60, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0xc2, 0x82, 0x82, 0x7e,
  0x42, 0x82, 0x82, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c,
  0x86, 0x02, 0x06, 0x7c, 0xc0, 0x80, 0xc2, 0x7d, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x7f, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0x82, 0x82, 0x82, 0x82,
  0x82, 0x82, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82,
  0xc6, 0x44, 0x44, 0x44, 0x28, 0x28, 0x28, 0x10, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x81, 0x81, 0x81, 0x5a, 0x5a, 0x5a, 0x66, 0x66, 0x66,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc6, 0x44, 0x28, 0x38, 0x10,
  0x28, 0x6c, 0x44, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41,
  0x22, 0x14, 0x14, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xfe, 0xc0, 0x60, 0x20, 0x10, 0x08, 0x0c, 0x06, 0xfe,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
  0x04, 0x04, 0x08, 0x08, 0x18, 0x10, 0x10, 0x20, 0x20, 0x40, 0x00, 0x00,
  0x00, 0x1c, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x14, 0x22, 0x63, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00,
  0x00, 0x00, 0x08, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x44, 0x40,
  0x7c, 0x42, 0x62, 0x5c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02,
  0x02, 0x3e, 0x66, 0x42, 0x42, 0x42, 0x66, 0x3e, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x44, 0x02, 0x02, 0x02, 0x44, 0x38,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x7c, 0x66, 0x42,
  0x42, 0x42, 0x66, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x3c, 0x66, 0x42, 0x7e, 0x02, 0x46, 0x3c, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x30, 0x08, 0x08, 0x08, 0x3e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x66, 0x42,
  0x42, 0x42, 0x66, 0x5c, 0x40, 0x44, 0x38, 0x00, 0x00, 0x02, 0x02, 0x02,
  0x02, 0x3a, 0x46, 0x42, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x00, 0x0e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x1c, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x0e, 0x00, 0x00, 0x02, 0x02, 0x02,
  0x02, 0x22, 0x12, 0x0a, 0x0e, 0x12, 0x22, 0x42, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x0e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x70,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x92, 0x92,
  0x92, 0x92, 0x92, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x3a, 0x46, 0x42, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x66, 0x42, 0x42, 0x42, 0x66, 0x3c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x66, 0x42,
  0x42, 0x42, 0x66, 0x3e, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x7c, 0x66, 0x42, 0x42, 0x42, 0x66, 0x5c, 0x40, 0x40, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x4c, 0x04, 0x04, 0x04, 0x04, 0x04,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x42, 0x02,
  0x3c, 0x40, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
  0x08, 0x7e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x70, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x62, 0x5c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x66, 0x24,
  0x24, 0x3c, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x81, 0x81, 0x5a, 0x5a, 0x5a, 0x24, 0x24, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x24, 0x18, 0x18, 0x18, 0x24, 0x66,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x44, 0x24,
  0x24, 0x28, 0x18, 0x10, 0x10, 0x08, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x7e, 0x40, 0x20, 0x18, 0x04, 0x02, 0x7e, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x38, 0x08, 0x08, 0x08, 0x08, 0x06, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x30, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x0e, 0x08, 0x08,
  0x08, 0x08, 0x30, 0x08, 0x08, 0x08, 0x08, 0x08, 0x06, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9c, 0x62, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

/* Length of the bit map font */
unsigned int font_bin_len = 2048;


void SetForeColour(unsigned short int color);
void DrawPixel(unsigned int px,unsigned int py);
void DrawLine(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1);
int* DrawCharacter(char character,unsigned int x,unsigned int y);
void DrawString(unsigned char *string,unsigned int x,unsigned int y);

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

/*
	Draws a character starting at point (x,y)
*/
int *DrawCharacter(char character,unsigned int x,unsigned int y){
	static int result[2];
	if(character > 127){
		result[0] = result[1] = 0;
		return result;
	}
	unsigned char *charAddr = font_bin + (character << 4);
	int row;
	for(row = 0; row < 16; ++row){
		unsigned char bits = *(charAddr + row);
		int bit;
		for(bit = 0; bit < 7; ++bit){
			if( ((bits >> bit) & 0x1) ){
				DrawPixel(x+bit,y+row);
			}
		}
	}
	result[0] = 8;
	result[1] = 16;
	return result;	
}


/*
	Draws a null terminated string starting at point (x,y)
*/
void DrawString(unsigned char *string,unsigned int x,unsigned int y){
	int x0 = x;
	int *dim;
	char character = *string; 
	while(character != '\0'){
		character = *string;
		dim = DrawCharacter(character,x,y);
		if(character == '\n'){
			x = x0;
			y = y + dim[1];
		}
		else if(character == '\t'){
			unsigned int x1 = x;
			dim[0] = dim[0] + (dim[0] << 2 );
			while( x1 <= x0){
				x1 = x1 + dim[0];
			}
			x = x1;
		}
		else{
			x = x + dim[0];
		}
		string = string + 1;
	}
}
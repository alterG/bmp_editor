#ifndef _RASTR_H_
#define _RASTR_H_

#include <stdlib.h>
#include <stdint.h>

typedef struct pixel_t {
	uint8_t rgbtBlue;
	uint8_t rgbtGreen;
	uint8_t rgbtRed;
} pixel_t;

typedef struct image_t {
	uint32_t width;
	uint32_t height;
	pixel_t* rastr;
} image_t;


#endif

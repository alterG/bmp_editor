#include <stdlib.h>
#include "rastr.h"

pixel_t * pixel_t_get (const image_t * const image, const uint32_t index_x, const uint32_t index_y) {
	
	return image->rastr+index_y*(image->width)+index_x;
}

/* Fucntion rotates image clockwise on 90 degrees */

void image_t_rotated_get (const image_t * const input_image, image_t * const output_image) {
	 
	/* (x2,y2) is new coordinates of (x1,y1) */
	uint32_t x1, y1, x2, y2;
	int i, j;

	output_image->height = input_image->width;
	output_image->width = input_image->height;
	for (i = 0; i < input_image->height; i++) {
		for (j=0; j < input_image->width; j++) {
			x1 = j;
			y1 = i;
			x2 = y1;
			y2 = (input_image->width) - x1;
		}
	}
}

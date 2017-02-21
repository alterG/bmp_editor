#include <stdlib.h>
#include "rastr.h"
#include "bmp_rotate.h"



static pixel_t pixel_t_get (const image_t * const image, const uint32_t index_x, const uint32_t index_y) {
	
	pixel_t pixel;
	pixel = *(image->rastr+index_y*(image->width)+index_x);
	return pixel;
}


static void pixel_t_set
(image_t * const image, const pixel_t pixel_replacer, const uint32_t index_x, const uint32_t index_y) {
	
	pixel_t * pixel_to_replace;
	pixel_to_replace = image->rastr+index_y*(image->width)+index_x;
	*pixel_to_replace = pixel_replacer;
}


/* Function rotates image clockwise on 90 degrees */

void image_t_rotated_get (const image_t * const input_image, image_t * const output_image) {
	 
	uint32_t x1, y1, x2, y2;	/* (x2,y2) is new coordinates of (x1,y1) */
	int i, j;
	pixel_t pixel_replacer;

	output_image->height = input_image->width;
	output_image->width = input_image->height;
	for (i = 0; i < input_image->height; i++) {
		for (j = 0; j < input_image->width; j++) {
			x1 = j;
			y1 = i;
			x2 = y1;
			y2 = (input_image->width) - x1;
			pixel_replacer = pixel_t_get(input_image, x1, y1);
			pixel_t_set(output_image, pixel_replacer, x2, y2);
		}
	}
}

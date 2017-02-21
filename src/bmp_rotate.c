#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "rastr.h"
#include "bmp_rotate.h"




static pixel_t * pixel_t_get (const image_t * const image, const uint32_t index_x, const uint32_t index_y) {

	return (image->rastr+index_y*(image->width)+index_x);
}


static void pixel_t_set
(image_t * const image, const pixel_t pixel_replacer, const uint32_t index_x, const uint32_t index_y) {
	
	*(image->rastr+index_y*(image->width)+index_x) = pixel_replacer;
	printf("%d %d %d\n", pixel_replacer.rgbtBlue, pixel_replacer.rgbtGreen, pixel_replacer.rgbtRed);


/*	pixel_t * pixel_to_replace;
	pixel_to_replace = &
	
	*pixel_to_replace = pixel_replacer;*/
}


/* Function rotates image clockwise on 90 degrees */

void image_t_rotated_get (const image_t * const input_image, image_t * const output_image) {
	 
	uint32_t x1, y1, x2, y2;	/* (x2,y2) is new coordinates of (x1,y1) */
	int i, j, k;
	
	output_image->height = input_image->width;
	output_image->width = input_image->height;
	
	output_image->rastr = (pixel_t *) calloc(sizeof(pixel_t), (output_image->width)*(output_image->height));
	for (i = 0; i < input_image->height; i++) {
		for (j = 0; j < input_image->width; j++) {
			x1 = j;
			y1 = i;
			x2 = y1;
			y2 = (input_image->width) - x1;
			*(pixel_t_get(output_image, x2, y2)) = *(pixel_t_get(input_image, x1, y1));
			/*printf("%d:  %d %d %d\n",i, (*(pixel_t_get(output_image, x2, y2))).rgbtBlue, (*(pixel_t_get(output_image, x2, y2))).rgbtGreen, (*(pixel_t_get(output_image, x2, y2))).rgbtRed);*/
		}
	}
}

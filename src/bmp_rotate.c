#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "rastr.h"
#include "bmp_rotate.h"

static int max (const int a, const int b) {
	return a>b?a:b;
}


static pixel_t * pixel_t_get (const image_t * const image, const uint32_t index_x, const uint32_t index_y) {

	return (image->rastr+index_y*(image->width)+index_x);
}


/* Function rotates image clockwise on <angle> degrees */

void image_t_rotated_get (const image_t * const input_image, image_t * const output_image, int angle) {
	int i, j, x1, y1, x2, y2;
	double rot_sin, rot_cos;
	pixel_t white_pixel = {255, 255, 255};

	rot_cos = cos(angle*M_PI/180.0f);
	rot_sin = sin(angle*M_PI/180.0f);
	output_image->width = max((int)(input_image->width*rot_cos - input_image->height*rot_sin), (int)(input_image->width*rot_cos + input_image->height*rot_sin));
	output_image->height = max((int)(input_image->width*rot_sin + input_image->height*rot_cos), (int)(input_image->height*rot_cos - input_image->width*rot_sin));
	output_image->rastr = (pixel_t *) calloc(sizeof(pixel_t), (output_image->width)*(output_image->height));
	for(i = 0; i < output_image->height; i++) {
		for(j = 0; j < output_image->width; j++) {
			x1 = j - output_image->width / 2;
			y1 = i - output_image->height / 2;
			x2 = x1*rot_cos - y1*rot_sin + input_image->width / 2;
			y2 = x1*rot_sin + y1*rot_cos + input_image->height / 2; 
			if(x2 >= input_image->width || y2 >= input_image->height) {
				*(pixel_t_get(output_image, j, i)) = white_pixel;
				continue;
			}
			*(pixel_t_get(output_image, j, i)) = *(pixel_t_get(input_image, x2, y2));
				/*printf("input: h_%d w_%d color %d %d %d\noutput: h_%d w_%d color %d %d %d\n",
				y1, x1,			
				(pixel_t_get(input_image, x1, y1))->rgbtRed,
				(pixel_t_get(input_image, x1, y1))->rgbtGreen,
				(pixel_t_get(input_image, x1, y1))->rgbtBlue,
				y2, x2,
				(pixel_t_get(output_image, x2, y2))->rgbtRed,
				(pixel_t_get(output_image, x2, y2))->rgbtGreen,				
				(pixel_t_get(output_image, x2, y2))->rgbtBlue);*/
		}
	}
}

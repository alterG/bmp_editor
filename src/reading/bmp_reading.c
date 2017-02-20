#include <stdlib.h>
#include <stdio.h>
#include "bmp_reading.h"
#include "rastr.h"
#include "bmp_header.h"

/*initialize image variable with width, height and copy of original image pixel rastr*/

static bitmap_header_t read_bitmap_header (FILE * const input_image) {
	bitmap_header_t * const bitmap_header;
	fseek(input_image, 0, SEEK_SET);
	fread(&bitmap_header, sizeof(bitmap_header_t), 1, input_image);
	return bitmap_header;
}

read_error_code_t from_bmp(char * const image_path, image_t * const image) {
	uint32_t i, j, offset;
	bitmap_header_t bitmap_header;
	FILE * input_image = fopen(image path, "rb");
	if (input_image == NULL) return READ_FILE_NOT_FOUND;
	bitmap_header = read_bitmap_header(input_image);
	if (bitmap_header->biBitCount != 24) return READ_INVALID_RESOLUTION;
	if ( (bitmap_header->bfType != 0x4D42) || (bitmap_header->biCompression != 0)
 	|| (bitmap_header->biPlanes != 1) ) return READ_INVALID_SIGNATURE;
	
	image->width = bitmap_header.biWidth;
	image->height = bitmap_header.biHeight;
	image->rastr = (image_t *) calloc(sizeof(pixel_t), (image->width)*(image->height));
	offset = ((image->width)*sizeof(pixel_t)) % 4;
	if (offset != 0) offset= 4-offset;
	fseek(input_image, bitmap_header.b0ffBits, SEEK_SET);
	for (i=0; i<(image->height); i++) {
		for (j=0; j<(image->width); j++) {
			fread(&(image->rastr)[i*(image->width)+j], sizeof(pixel_t), 1, input_image);
		}
		fseek(input_image, offset*, SEEK_CUR);
	}
	fclose(input_image);
	return READ_OK;
}

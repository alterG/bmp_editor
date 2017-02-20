#include <stdlib.h>
#include <stdio.h>


writing_error_code_t to_bmp(char * const image_path, image_t * const image) {
	bitmap_header_t bitmap_header;
	int offset;
	FILE * output_image = fopen(image_path, "wb");
	if (output_image == NULL) return WRITE_ERROR;
	offset = ((image->width)*sizeof(pixel_t)) % 4;
	if (offset != 0) offset= 4-offset;

 	bitmap_header->bfType = 0x4d42;	
  	bitmap_header->bfileSize = 54 + ((image->width)*sizeof(pixel_t)+offset)*(image->height);	
  	bitmap_header->bfReserved1 = 0;
	bitmap_header->bfReserved2 = 0;
	bitmap_header->b0ffBits = 54;  	/* dont add color table */ 

	bitmap_header->biSize = 54; 			/*cant use sizeof() from memory align*/
	bitmap_header->biWidth = image->width;
	bitmap_header->biHeight = image->height;
	bitmap_header->biPlanes = 1;		
	bitmap_header->biBitCount = 24;	
	bitmap_header->biCompression = 0;	
	bitmap_header->biSizeImage = 0;	
	bitmap_header->biXPelsPerMeter = 0xec4; /* 3780ppm (Microsoft displays) */
	bitmap_header->biYPelsPerMeter = 0xec4;
	bitmap_header->biClrUsed = 0;		 						
	bitmap_header->biClrImportant = 0;

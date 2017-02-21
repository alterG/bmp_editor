#include <stdlib.h>
#include <stdio.h>
#include "rastr.h"
#include "bmp_reading.h"
#include "bmp_writing.h"
#include "bmp_rotate.h"





int main (int argc, char ** argv) {
	image_t * source_image;
	image_t * output_image;
	reading_error_code_t reading_error_code;
	writing_error_code_t writing_error_code;
	char * source_bmp_path = "./res/example.bmp"; 
	char * output_filename = "./res/test.bmp";
	source_image = (image_t *) malloc(sizeof(image_t));
	output_image = (image_t *) malloc(sizeof(image_t));
	reading_error_code = from_bmp(source_bmp_path, source_image);
	switch (reading_error_code) {
		case READ_INVALID_SIGNATURE: 
			printf("File has invalid signature.\n");
			return -1;	
		case READ_INVALID_RESOLUTION: 
			printf("File has invalid resolution. Program works only with 24-bits bmp format.\n");
			return -2;
		case READ_FILE_NOT_FOUND: 
			printf("File not found.\n");
			return -3;
		case READ_SUCCESS: 
			printf("File has been read successfully.\n");
			break;
	}
	image_t_rotated_get(source_image, output_image);
	writing_error_code = to_bmp(output_filename, source_image);	
	switch (writing_error_code) {
		case WRITE_ERROR: 
			printf("Error. File cant be written.\n");
			return -1;	
		case WRITE_SUCCESS: 
			printf("File has been written successfully.\n");
			break;
	}
	free(source_image);
	free(output_image);
	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include "rastr.h"
#include "bmp_reading.h"
#include "bmp_writing.h"
#include "bmp_rotate.h"
#include "modules.h"


int main (int argc, char ** argv) {
	image_t * source_image;
	image_t * output_image;
	read_ptr read_ptr1;
	rotate_ptr rotate_ptr1;
	write_ptr write_ptr1;
	reading_error_code_t reading_error_code;
	writing_error_code_t writing_error_code;
	int angle, image_type;
	printf("Type number of input image:\n1 for BMP 24bit\n2 for JPEG\n3 for PNG 8bit.\nNumber:");
	scanf("%d", &image_type);
	switch (image_type) {
		case 1:
			read_ptr1 = &from_bmp;
			rotate_ptr1 = &image_t_rotated_get;
			write_ptr1 = &to_bmp;
			break;
		default:
			return 0;
	}
	
	printf("\nInput angle to rotate: ");
	scanf("%d", &angle);
	char * source_bmp_path = "../res/example.bmp";
	char * output_filename = "../res/rotated.bmp";
	source_image = (image_t *) malloc(sizeof(image_t));
	output_image = (image_t *) malloc(sizeof(image_t));
	reading_error_code = read_image(read_ptr1, source_bmp_path, source_image);
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
	rotate_image(rotate_ptr1, source_image, output_image, angle);
	writing_error_code = write_image(write_ptr1, output_filename, output_image);	
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


#include "rastr.h"
#include "modules.h"
#include "bmp_reading.h"
#include "bmp_writing.h"

reading_error_code_t read_image (read_ptr function, char * const image_path, image_t * const output_image) {
	return function(image_path, output_image);
}

void rotate_image (rotate_ptr function, image_t * input_image, image_t * output_image, int angle) {
	function(input_image, output_image, angle);
}

writing_error_code_t write_image (write_ptr function, char* output_filename, image_t* output_image) {
	return function(output_filename, output_image);
}

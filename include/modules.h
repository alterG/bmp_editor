#ifndef _MODULES_H_
#define _MODULES_H_
#include <stdlib.h>
#include "rastr.h"
#include "bmp_reading.h"
#include "bmp_writing.h"

typedef reading_error_code_t (*read_ptr) (char * const, image_t * const);
typedef void (*rotate_ptr) (const image_t * const, image_t * const, int);
typedef writing_error_code_t (*write_ptr) (char * const , image_t * const);

reading_error_code_t read_image (read_ptr function, char * const image_path, image_t * const output_image);
void rotate_image (rotate_ptr function, image_t * input_image, image_t * output_image, int angle);
writing_error_code_t write_image (write_ptr function, char* output_filename, image_t* output_image);

#endif

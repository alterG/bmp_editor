#ifndef _BMP_READING_H_
#define _BMP_READING_H_
#include <rastr.h>

typedef enum read_error_code_t {
	READ_OK = 0,
	READ_INVALID_SIGNATURE,
	READ_INVALID_RESOLUTION,
	READ_FILE_NOT_FOUND
} read_error_code_t;

read_error_code_t from_bmp(char *, image_t * const); 

#endif

#ifndef _BMP_READING_H_
#define _BMP_READING_H_
#include <rastr.h>

typedef enum reading_error_code_t {
	READ_SUCCESS = 0,
	READ_INVALID_SIGNATURE,
	READ_INVALID_RESOLUTION,
	READ_FILE_NOT_FOUND
} reading_error_code_t;

reading_error_code_t from_bmp(char *, image_t * const); 

#endif

#ifndef _BMP_WRITING_H_
#define _BMP_WRITING_H_

typedef struct writing_error_code_t {
	WRITE_SUCCESS = 0,
	WRITE_ERROR
} writing_error_code_t;

writing_error_code_t to_bmp(char * const image_path, image_t * const image);
static void bitmap_header_t_init (bitmap_header_t * const bitmap_header, image_t * const image);

#endif
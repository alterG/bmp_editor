#ifndef _BMP_ROTATE_H_
#define _BMP_ROTATE_H_

#include <stdlib.h>
#include <stdint.h>

static pixel_t * pixel_t_get (const image_t * const image, const uint32_t index_x, const uint32_t index_y);

static void pixel_t_set
(image_t * const image, const pixel_t pixel_replacer, const uint32_t index_x, const uint32_t index_y);

void image_t_rotated_get (const image_t * const input_image, image_t * const output_image);


#endif

#ifndef _BMP_ROTATE_H_
#define _BMP_ROTATE_H_

#include <stdlib.h>
#include <stdint.h>

#ifndef M_PI
#define M_PI 3.14159265
#endif


static pixel_t * pixel_t_get (const image_t * const image, const uint32_t index_x, const uint32_t index_y);

void image_t_rotated_get (const image_t * const input_image, image_t * const output_image, int angle);


#endif

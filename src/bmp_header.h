#ifndef _BMP_HEADER_H
#define _BMP_HEADER_H

#pragma pack(push, 2)

typedef struct bitmap_header_t {

	uint16_t bfType;				/* file type (BM for BitMap) */
	uint32_t bfileSize;				/* file size (in bytes) */
	uint16_t bfReserved1;			/* reserved (need to be 0) */
	uint16_t bfReserved2;			/* reserved (need to be 0) */
	uint32_t b0ffBits;				/* space (in bytes) between start of file and bit raster */
 
	uint32_t biSize;				/* size of struct */
	uint32_t biWidth;				/* pixels in width */
	uint32_t biHeight;				/* pixels in height */
	uint16_t biPlanes;				/* amount of image planes (usually 1) */
	uint16_t biBitCount;			/* amount of bits for pixel */
	uint32_t biCompression;			/* compression type (usually bmp has no compression) */
	uint32_t biSizeImage;			/* size of compressed image or 0 if there is no compression*/
	uint32_t biXPelsPerMeter;		/* resolution pixels/meter for X */
	uint32_t biYPelsPerMeter;		/* resolution pixels/meter for Y */
	uint32_t biClrUsed;				/* Amount of colors (using only for compressed images) if 0 amount 										of colors is determined by biBitCount */
	uint32_t biClrImportant;		/* amount of important colors (usually 0, all colors are important) */
} bitmap_header_t;

#pragma pack(pop)

#endif

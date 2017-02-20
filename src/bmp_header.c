#include "lib.h" /*check*/
#include "bmp_header.h"

static void bitmap_file_header_fill (bitmap_file_header_t *bfh) {
bfh->bfType = 0x4D42;
bfh->bfileSize
bfh->bfReserved1 = 0;
bfh->bfReserved2 = 0;
bfh->b0ffBits

}

static void bitmap_info_header_fill (bitmap_info_header_t *bih, uint32_t width, uint32_t height) {

bih->biSize = sizeof (bitmap_info_header_t);			
bih->biWidth = width;		
bih->biHeight = height;		
bih->biPlanes = 1;		
bih->biBitCount = 24;	
bih->biCompression = 0;
bih->biSizeImage;	
bih->biXPelsPerMeter;		
bih->biYPelsPerMeter;		
bih->biClrUsed = 0;				
bih->biClrImportant = 0;		

}

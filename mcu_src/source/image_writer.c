#include "image_writer.h"

#include <stdio.h>

#define LINE_WIDTH 18

int ceil(float f) {
	if(f == (int)f) return f;
	return ((int)f) + 1;
}

void write_image(uint8_t *buffer, char *image, int w, int h) {
	int x = 3;
	int y = 0;

	int row = 0;
	int col = 0;
	for(int i = 0; i < (ceil(w/8.0)*h); i++) {
		int x_block = x + col;
		int y_block = y + row;
		if(y_block >= 128) break;
		if(x_block >= 16) continue;
		buffer[2 + x_block + y_block*LINE_WIDTH] = image[i];
		if((i + 1) % (int)(ceil(w/8.0)) == 0) {row++; col = 0;} else {col++;}
        }
}

#include "lcd_buffer.h"

#define WIDTH	128
#define HEIGHT	128
#define W_BYTES	WIDTH/8
#define H_BYTES	HEIGHT/8

uint8_t buffer[W_BYTES * H_BYTES];

void update() {
	//MODE
	send_byte();

	//PIXELS
	for(int i = 0; i < HEIGHT; i++) send_line(i);

	//DUMMY
	send_byte(0);
	send_byte(0);
}

void reset() {
	uint8_t clear = 0x0;
	memset(buffer, clear, WIDTH * HEIGHT);
}

void send_line(uint8_t index) {
	//ADDR
	send_byte(index);

	//PIXELS
	for(int i = 0; i < 16; i++) send_byte(buffer[i + index*W_BYTES]);

	//DUMMY
	send_bytes(0);
}

void send_byte(uint8_t val) {
}

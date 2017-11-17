#include "lcd_buffer.h"
#include "spi_interface.h"

#include "em_gpio.h"
#include "custom_font.h"

#include <stdio.h>

uint8_t buffer[TOTAL_BUFFER_SIZE];
uint8_t display_mode_buffer	= 0b00000000;
uint8_t clear_mode_buffer	= 0b00000100;

void setup_LCD() {
	init_spi();									//Setup SPI
	reset();
	buffer[0] = 0b00000011;								//Set data update mode
	for(int i = 0; i < HEIGHT; i++) buffer[1 + i*(W_BYTES + 2)] = i + 1;		//Set address lines in buffer
	for(int i = 0; i < 2; i++) buffer[(W_BYTES * HEIGHT) + HEIGHT*2 + 1 + i] = 0x0;	//Zero dummy bytes
}

void update() {
	send_buffer(buffer, TOTAL_BUFFER_SIZE);
	enter_display_mode();
}

void enter_display_mode() {
	send_buffer(&display_mode_buffer, 1);
}

void clear() {
	send_buffer(&clear_mode_buffer, 1);
}

void reset() {
	clear();
	uint8_t clear = 0x00;
	for(int i = 0; i < HEIGHT; i++) memset(buffer + 2 + i*(W_BYTES + 2), clear, W_BYTES);
}

void set_byte(unsigned int pos, uint8_t val) {
	buffer[pos_to_buffer_pos(pos)] = val;
}

void set_single_pixel(unsigned int pixel, bool toggle) {
	int pixel_byte = (pixel / 8);
	int x_byte_index = pixel_byte % W_BYTES;
	int y_byte_index = (pixel_byte / W_BYTES);
	int byte_index = x_byte_index + y_byte_index*(W_BYTES + 2) + 2;
	unsigned int pixel_mask = 1 << (pixel - pixel_byte);
	if(toggle) {buffer[byte_index] = buffer[byte_index] & ~pixel_mask;
	} else {buffer[byte_index] = buffer[byte_index] | pixel_mask;}
}

unsigned int pos_to_buffer_pos(unsigned int pos) {return pos + 2 + (pos / W_BYTES)*2;}

uint8_t *get_buffer() {return buffer;}

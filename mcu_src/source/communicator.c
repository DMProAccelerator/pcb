#include "communicator.h"

#include "uart.h"
#include "lcd_buffer.h"
#include "custom_font.h"
#include "image_writer.h"
#include "images.h"

#define COM_BUFFER_SIZE	512
#define PYNQ_SIZE 8

char com_buffer[COM_BUFFER_SIZE];
int index = 0;
char last_char;

typedef struct {
	char index;
	char percentage;
} pynq_t;

pynq_t pynqs[PYNQ_SIZE];
char pynq_map[PYNQ_SIZE];
unsigned int pynq_num;

void update_status() {
	reset();
	writef("unit    progress", get_buffer(), 0, 0, 1);
	for(int i = 0; i < pynq_num; i++) {
		writef("pynq%i   %i\%", get_buffer(), 0, (i + 1)*9 + 5, 1, pynqs[i].index, pynqs[i].percentage);
	}

	for(int i = 0; i < 8; i++) writef("%i", get_buffer(), i*8, 120, 1, (last_char >> (7 - i)) & 1);
	update();
}

void reset_table() {
	for(int i = 0; i < PYNQ_SIZE; i++) {
		pynqs[i].percentage = 0;
		pynqs[i].index = 0;
		pynq_map[i] = 10;
	}
	pynq_num = 0;

	reset();
	write_image(get_buffer(), start_image, 69, 128);
	update();
}

void parse_command(char c) {
	if(c & 0b10000000) {
		reset_table();
		return;
	}

	char server_id	= c >> 4 & 0b111;

	if(pynq_map[server_id] == 10) {
		pynq_map[server_id] = pynq_num;
		pynqs[pynq_num++].index = server_id;
	}

	char percentage	= (c & 0b1111)*6.67;
	if(percentage > 100) percentage = 100;

	pynqs[pynq_map[server_id]].percentage = percentage;
	update_status();
}

void recv_char(char c) {
	if(c == last_char) return;
	last_char = c;
	parse_command(c);
}

void communicator_setup_lcd() {
	setup_LCD();
}

void communicator_setup_uart() {
	set_recv_callback(&recv_char);

	setup_uart();
}

void setup_project() {
	communicator_setup_lcd();
	reset_table();
	communicator_setup_uart();
	free(pynqs);
}



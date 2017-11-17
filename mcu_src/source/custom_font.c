#include "custom_font.h"
#include <stdbool.h>

#include <stdio.h>

#define ALPHABET_LENGTH	26
#define FONT_WIDTH	8
#define FONT_HEIGHT	8

#define SCREEN_WIDTH	128
#define SCREEN_HEIGHT	128

#define X_BLOCK_LEN	(SCREEN_WIDTH/8)
#define LINE_WIDTH	(X_BLOCK_LEN + 2)

#define MIN(x, y)	(x <= y ? x : y)

#define EXTRA_CHARS ":.%\0"

bool validate_character(char c) {
	return ((c - 'a' >= 0 && c - 'z' <= 0)
		|| (c - 'A' >= 0 && c - 'Z' <= 0)
		|| (c - '0' >= 0 && c - '9' <= 0)
		|| (c == ':' || c == '.' || c == '%') ? true : false);
}

uint8_t bit_mask[] = {
	0b00000000,
	0b00000001,
	0b00000011,
	0b00000111,
	0b00001111,
	0b00011111,
	0b00111111,
	0b01111111,
	0b11111111
};

void writef(char *s, uint8_t *buffer, unsigned int x, unsigned int y, int flip, ...) {
	int writef_buffer_size = 32;
	char buf[writef_buffer_size];
	va_list vl;
	va_start(vl, s);

	vsnprintf(buf, sizeof(buf), s, vl);
	va_end(vl);
	write_string(buf, writef_buffer_size, buffer, x, y, flip);
}

void write_string(char *s, unsigned long len, uint8_t *buffer, unsigned int x, unsigned int y, int flip) {
	if(y >= SCREEN_HEIGHT) return;
	for(int i = 0; i < len; i++) {
		if(x >= SCREEN_WIDTH || s[i] == '\0') return;
		if(s[i] != ' ') enter_char(s[i], buffer, x, y, flip);
		x += FONT_WIDTH;
	}
}

void enter_char(char c, uint8_t *buffer, unsigned int x, unsigned int y, int flip) {
	if(!validate_character(c)) return;
	unsigned char offset;
	unsigned char *c_map = get_char(c, &offset);
	int x_block = x/8;
	int first_block = 2 + x_block + y*LINE_WIDTH;

	for(int i = 0; i < MIN(FONT_HEIGHT, 128 - y); i++) {
		if(flip) {
			buffer[first_block + i*LINE_WIDTH] = 0;
			char c = c_map[i];
			for(int i2 = 0; i2 < 8; i2++) buffer[first_block + i*LINE_WIDTH] |= (((c >> i2) & 0x1) << (7 - i2));
		} else {
			buffer[first_block + i*LINE_WIDTH] = c_map[i];
		}
	}
}

unsigned char chars_big[39][8] = {
	{56,108,198,198,254,198,198,198},
	{248,204,204,248,204,198,198,252},
	{60,102,194,192,192,194,102,60},
	{248,196,194,194,194,194,198,248},
	{254,192,192,248,192,192,192,254},
	{254,192,192,240,192,192,192,192},
	{60,102,194,192,206,194,102,60},
	{198,198,198,198,254,198,198,198},
	{60,24,24,24,24,24,24,60},
	{6,6,6,6,6,198,198,124},
	{198,204,216,240,240,216,204,198},
	{192,192,192,192,192,192,192,254},
	{194,230,218,194,194,194,194,194},
	{194,226,210,202,198,194,194,194},
	{56,108,198,198,198,198,108,56},
	{252,198,198,198,252,192,192,192},
	{56,108,198,198,214,222,108,58},
	{252,198,198,206,248,204,198,198},
	{124,198,192,120,12,6,198,124},
	{254,24,24,24,24,24,24,24},
	{198,198,198,198,198,198,238,124},
	{198,198,198,198,108,108,56,16},
	{198,198,198,198,214,214,238,198},
	{198,198,108,56,56,108,198,198},
	{198,198,108,56,16,16,16,16},
	{254,4,12,24,48,96,192,254},
	{56,108,198,198,198,198,108,56},
	{60,12,12,12,12,12,12,62},
	{56,204,134,6,28,48,96,254},
	{60,102,6,28,14,6,102,60},
	{198,198,198,198,254,6,6,6},
	{254,192,192,252,6,6,6,252},
	{56,108,198,192,252,198,198,124},
	{254,6,12,24,48,48,48,48},
	{56,68,108,56,108,198,198,124},
	{126,198,198,198,126,6,6,6},
	{0,48,48,0,0,48,48,0},
	{0,0,0,0,0,24,24,0},
	{0,98,100,8,16,38,70,0}
};

unsigned char *get_char(char c, unsigned char *offset) {
	unsigned int pos;
	if(c - '0' >= 0 && c - '9' <= 0) {
		pos = ALPHABET_LENGTH + (c - '0');
		*offset = ((c - '0') % 2)*4;
	} else if (c - 'a' >= 0 && c - 'z' <= 0) {
		pos = (c - 'a');
		*offset = ((c - 'a') % 2)*4;
	} else if(c - 'A' >= 0 && c - 'z' <= 0) {
		return get_char(c - 'A' + 'a', offset);
	} else {
		int counter = 0;
		for(const char *ch = EXTRA_CHARS; *ch != '\0'; ch++) {
			if(*ch == c) {
				pos = ALPHABET_LENGTH + 10 + counter;
				break;
			}
			counter++;
		}
	}
	return chars_big[pos];
}

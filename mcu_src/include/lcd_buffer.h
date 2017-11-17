#include <stdbool.h>
#include <stdint.h>

#define WIDTH                   128
#define HEIGHT                  128
#define W_BYTES                 WIDTH/8
#define TOTAL_BUFFER_SIZE       (W_BYTES * HEIGHT) + HEIGHT*2 + 3

void setup_LCD();

void update();
void enter_display_mode();
void clear();
void reset();

unsigned int pos_to_buffer_pos(unsigned int pos);
void set_byte(unsigned int pos, uint8_t val);
void set_single_pixel(unsigned int pixel, bool toggle);

uint8_t *get_buffer();

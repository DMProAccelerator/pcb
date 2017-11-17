#include <stdint.h>
#include <stdarg.h>

void enter_char(char c, uint8_t *buffer, unsigned int x, unsigned int y, int flip);
void writef(char *s, uint8_t *buffer, unsigned int x, unsigned int y, int flip, ...);
void write_string(char *s, unsigned long len, uint8_t *buffer, unsigned int x, unsigned int y, int flip);
unsigned char *get_char(char c, unsigned char *offset);

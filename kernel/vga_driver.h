#ifndef VGADRIVER_H
#define VGADRIVER_H

#include <stdint.h>
#include <stddef.h>

enum vga_color {
        COLOR_BLACK = 0,
        COLOR_BLUE = 1,
        COLOR_GREEN = 2,
        COLOR_CYAN = 3,
        COLOR_RED = 4,
        COLOR_MAGENTA = 5,
        COLOR_BROWN = 6,
        COLOR_LIGHT_GREY = 7,
        COLOR_DARK_GREY = 8,
        COLOR_LIGHT_BLUE = 9,
        COLOR_LIGHT_GREEN = 10,
        COLOR_LIGHT_CYAN = 11,
        COLOR_LIGHT_RED = 12,
        COLOR_LIGHT_MAGENTA = 13,
        COLOR_LIGHT_BROWN = 14,
        COLOR_WHITE = 15,
};
uint16_t BG_COLOR;

static const size_t VGA_HEIGHT = 24;
static const size_t VGA_WIDTH = 80;


size_t cursor_col;
size_t cursor_row;
uint16_t* vga_buffer;

int vga_putchar(int c);
int vga_putstr(char* data);
void vga_initialize();
uint16_t make_vga_entry(char c, uint8_t color);
uint8_t make_color(enum vga_color fg, enum vga_color bg);


#endif

#include "vga_driver.h"

uint8_t make_color(enum vga_color fg, enum vga_color bg) {
    return fg | bg << 4;
}
 
uint16_t make_vga_entry(char c, uint8_t color) {
    uint16_t c16 = c;
    uint16_t color16 = color;
    return c16 | color16 << 8;
}

void vga_initialize() {
    cursor_col = 0;
    cursor_row = 0;
    BG_COLOR = make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
    vga_buffer = (uint16_t*) 0xB8000;

    uint16_t vga_entry = make_vga_entry(' ', BG_COLOR);
    for (size_t i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        vga_buffer[i] = vga_entry;
    }
    vga_buffer[0] = make_vga_entry('H', make_color(COLOR_GREEN, COLOR_BLACK));
    vga_buffer[1] = make_vga_entry('i', make_color(COLOR_GREEN, COLOR_BLACK));
}

int vga_putchar(int c) {
   uint8_t text_color =  make_color(COLOR_GREEN, COLOR_BLACK);
   vga_buffer[cursor_row * VGA_WIDTH + cursor_col] = make_vga_entry(c, text_color);
   cursor_col++;
   if (cursor_col > VGA_WIDTH) {
        cursor_col = 0;
        cursor_row++;
        // FIXME: write a function to push lines up the screen
        if (cursor_row > VGA_HEIGHT) {
            vga_initialize();
            cursor_row = 0;
        }
   }
   return c;
}

int vga_putstr(char* data) {
    int i;
    for (i = 0; data[i] != '\0'; ++i) {
        vga_putchar(data[i]);
    }
	return i;
}

void vga_copy_up_lines() {
}

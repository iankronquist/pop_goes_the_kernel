#include "vga_driver.h"
#include "idt.h"
#include "gdt.h"

void kernel_main() {
    vga_initialize();
    vga_putstr("Hello kernel!\n");
    vga_putstr("Loading GDT...\n");
    setup_gdt();
    vga_putstr("Loading IDT...\n");
    setup_idt();
    vga_putstr("Done!\n");
    int i = 0;
    int j = 10;
    i = j / i;
    vga_putstr("worked?!\n");
}

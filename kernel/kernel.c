#include "vga_driver.h"
#include "gdt.h"

void kernel_main() {
    vga_initialize();
    vga_putstr("Hello kernel!\n");
    vga_putstr("Loading GDT...\n");
    setup_gdt();
    vga_putstr("Done!\n");
    print_gdt();
}

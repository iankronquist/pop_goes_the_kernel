#include "vga_driver.h"

void kernel_main() {
    vga_initialize();
    vga_putstr("Hello kernel!");
}

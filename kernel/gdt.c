#include "gdt.h"
#include "vga_driver.h"

void setup_gdt() {
    gdt_entries[0] = 0;
    gdt_entries[1] = make_gdt_entry(0x08, 0);
    gdt_entries[2] = make_gdt_entry(0x10, 0);
    GDT.address = (int)&gdt_entries;
    GDT.size = 48; // 48 bits
    load_gdt(&GDT);
}

void print_gdt() {
    uint16_t mask;
    // Each entry in the GDT is 16 bits wide. There are three entries
    for (int entry = 0; entry < 3; entry++) {
        mask = 1;
        for (int bit = 0; bit < 16; bit++) {
            if (gdt_entries[entry] & mask) {
                vga_putchar('1');
            } else {
                vga_putchar('0');
            }
            mask <<= 1;
        }
        vga_putchar('\n');
    }
}

uint16_t make_gdt_entry(uint16_t offset, short privilege_level) {
    uint16_t entry = 0;
    entry |= 3 & (privilege_level);
    entry |= offset << 3;
    return entry;
}

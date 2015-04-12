#include "gdt.h"
#include "vga_driver.h"

void setup_gdt() {
    gdtp.limit = (sizeof(struct gdt_entry) * NUM_GDT_ENTRIES);
    gdtp.base = (unsigned int)&gdt;
    //memset(&gdt, 0, sizeof(struct gdt_entry) * NUM_GDT_ENTRIES);

    gdt_set_gate(0, 0, 0, 0, 0);
    gdt_set_gate(1, 0, 0xffffffff, 0x9a, 0xcf);
    gdt_set_gate(2, 0, 0xffffffff, 0x92, 0xcf);

    //load_gdt(); // This function is written in assembly in kernel/gdt.s
}

void gdt_set_gate(unsigned int entry, unsigned long base, unsigned long limit,
                  unsigned long access, unsigned char granularity) {
    gdt[entry].base_low = base & 0xffff;
    gdt[entry].base_middle = (base >> 16) & 0xff;
    gdt[entry].base_high = (base >> 24) & 0xff;

    gdt[entry].limit_low = limit & 0xffff;
    gdt[entry].granularity = (limit >> 16) & 0x0f;
    gdt[entry].granularity |= granularity & 0xf0;
    gdt[entry].access = access;
}

uint16_t make_gdt_entry(uint16_t offset, short privilege_level) {
    uint16_t entry = 0;
    entry |= 3 & (privilege_level);
    entry |= offset << 3;
    return entry;
}

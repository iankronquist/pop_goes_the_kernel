#ifndef GDT_H
#define GDT_H

#include <stdint.h> 
#include <stdbool.h> 

struct gdt_data {
    unsigned int address;
    unsigned short size;
}__attribute__((packed)) GDT;

uint16_t gdt_entries[3];

extern void load_gdt();
void setup_gdt();
uint16_t make_gdt_entry(uint16_t offset, short privilege_level);
void print_gdt();

#endif

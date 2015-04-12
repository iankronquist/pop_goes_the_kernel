#ifndef GDT_H
#define GDT_H

#include <stdint.h> 
#include <stdbool.h> 

struct gdt_entry {
    unsigned short limit_low;
    unsigned short base_low;
    unsigned char base_middle;
    unsigned char access;
    unsigned char granularity;
    unsigned char base_high;
};

struct gdt_ptr {
    unsigned short limit;
    unsigned int base;
}__attribute__((packed)) gdtp;

#define NUM_GDT_ENTRIES 6

struct gdt_entry gdt[NUM_GDT_ENTRIES];

void gdt_set_gate(unsigned int entry, unsigned long base, unsigned long limit,
                  unsigned long access, unsigned char granularity);
extern void load_gdt();
void setup_gdt();
void print_gdt();

#endif

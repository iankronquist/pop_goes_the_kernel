#ifndef IDT_H
#define IDT_H

#include <stdint.h> 
#include <stdbool.h>

extern void no_error_code_interrupt_handler_0();
extern void interrupt_handler_7();
extern void common_handler();
extern void load_idt();

struct cpu_state {
    unsigned int eax;
    unsigned int ebx;
    unsigned int ecx;
    unsigned int edx;
    unsigned int esi;
    unsigned int edi;
    unsigned int esp;
    unsigned int ebp;

} __attribute__((packed));

struct stack_state {
    unsigned int error_code;
    unsigned int eip;
    unsigned int cs;
    unsigned int eflags;
} __attribute__((packed));

struct idt_ptr {
    unsigned short limit;
    uintptr_t base;
} __attribute__((packed));

struct idt_entry {
    unsigned short base_low;
    unsigned short selector;
    unsigned char zero;
    unsigned char flags;
    unsigned short base_high;
} __attribute__((packed));

#define NUM_IDT_ENTRIES 256

struct idt_entry idt[NUM_IDT_ENTRIES];
struct idt_ptr idtp;

void generic_interrupt(struct cpu_state cpu, struct stack_state stack,
                       unsigned int interrupt);
void setup_idt();
void set_interrupts();
void idt_set_gate(unsigned char entry, void (*interrupt_base)(void),
                  unsigned short selector, unsigned char flags);

#endif

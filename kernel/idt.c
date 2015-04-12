#include "idt.h"
#include "gdt.h"
#include "vga_driver.h"

void generic_interrupt(struct cpu_state cpu, struct stack_state stack,
                       unsigned int interrupt) {
    vga_putstr("Interrupt caught!");
}

void setup_idt() {
    __asm__ volatile ("cli");
    idtp.limit = (sizeof(struct idt_entry) * NUM_IDT_ENTRIES) - 1;
    idtp.base = (uintptr_t)&idtp;
    set_interrupts();
    load_idt();
    __asm__ volatile ("sti");
}

void set_interrupts() {
    for (int i = 0; i < NUM_IDT_ENTRIES; i++) {
        idt_set_gate(i, common_handler, 0x08, 0x8e);
    }
}

void idt_set_gate(unsigned char entry, void (*interrupt_base)(void),
                  unsigned short selector, unsigned char flags) {
    idt[entry].base_low = (uintptr_t)interrupt_base & 0xffff;
    idt[entry].base_high = ((uintptr_t)interrupt_base >> 16) & 0xffff;
    idt[entry].selector = selector;
    idt[entry].zero = 0;
    idt[entry].flags = flags | 0x60;
}

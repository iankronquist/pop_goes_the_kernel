#include <machine/asm.h>

.intel_syntax noprefix

.global load_gdt

.extern gdtp

load_gdt:
	lgdt [gdtp];
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp 0x08:enter_new_segment

enter_new_segment:
	ret;


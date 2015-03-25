#include <machine/asm.h>

.intel_syntax noprefix

.global load_gdt

.extern gdt_data

load_gdt:
	cli;
	mov eax, [ebp+8]
	lgdt [eax];
	sti;
	ret;


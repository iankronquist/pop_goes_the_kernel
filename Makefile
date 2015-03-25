# This is our cross compiler's target architecture
TARGET=i686-elf
# This is the path to our C Compiler
CC=compiler/$(TARGET)/bin/$(TARGET)-gcc
# This is the path to our assembler
AS=compiler/$(TARGET)/bin/$(TARGET)-as
# Here are the flags for our C Compiler
CFLAGS= -std=c99 -ffreestanding -O2 -Wall -Wextra -fdiagnostics-color=auto
# These are the flags for the linking step
LDFLAGS= -lgcc -O2 -ffreestanding -nostdlib -fdiagnostics-color=auto

all: bootloader kernel link

# Boot the kernel!
start:
	qemu-system-i386 -kernel build/popos.img

# All of our object files, images, and executables will be stored here.
build:
	mkdir build

# This is the bootloader. We need to assemble it into an object file  we can 
# link against.
bootloader: build
	$(AS) kernel/boot.S -o build/boot.o

# Build the kernel.
kernel: build vga_driver gdt
	$(CC) -c kernel/kernel.c -o build/kernel.o  $(CFLAGS)

gdt:
	$(CC) -c kernel/gdt.c -o build/gdt.o $(CFLAGS)
	$(AS) -c kernel/gdt.s -o build/gdt_s.o $(ASFLAGS)

# Link it all together into a single image
link: build
	$(CC) -T kernel/linker.ld build/gdt.o build/gdt_s.o build/vga_driver.o build/boot.o build/kernel.o -o build/popos.img $(LDFLAGS)

# This is how we write to the screen
vga_driver: build
	$(CC) -c kernel/vga_driver.c -o build/vga_driver.o $(CFLAGS)

# delete everything so we can start fresh
clean:
	rm -rf build

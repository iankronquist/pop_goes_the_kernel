# This is our cross compiler's target architecture
TARGET=arm-none-eabi
# This is the path to our C Compiler
CC=compiler/$(TARGET)/bin/$(TARGET)-gcc
# This is the path to our assembler
AS=compiler/$(TARGET)/bin/$(TARGET)-as
# Here are the flags for our C Compiler
CFLAGS= -std=c99 -ffreestanding -O2 -Wall -Wextra
# These are the flags for the linking step
LDFLAGS= -lgcc -O2 -ffreestanding -nostdlib

all: bootloader kernel link

# Boot the kernel!
start:
	qemu-system-arm -kernel build/popos.img

# All of our object files, images, and executables will be stored here.
build:
	mkdir build

# This is the bootloader. We need to assemble it into an object file  we can 
# link against.
bootloader: build
	$(AS) kernel/boot.s -o build/boot.o

# Build the kernel.
kernel: build
	$(CC) -c kernel/kernel.c -o build/kernel.o  $(CFLAGS)

# Link it all together into a single image
link: build
	$(CC) -T kernel/linker.ld -o build/popos.img $(LDFLAGS)

# This is how we write to the screen
terminal: build
	$(CC) -c kernel/terminal.c -o build/terminal.o $(CFLAGS)

# delete everything so we can start fresh
clean:
	rm -rf build

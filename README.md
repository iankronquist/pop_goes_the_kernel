Pop Open a Kernel
=================

This is an introduction to writing a simple kernel for the Raspberry Pi.

What is a kernel?
-----------------


What do we need to get started?
-------------------------------
Since we're writing the kernel for the Raspberry Pi we'll need a special
compiler. The Raspberry Pi is an arm computer, but most laptops and desktops
are x86 or x86_64. Your version of GCC will only compile programs for your
computer, but we need to compile the kernel for the Raspberry pi.

We'll also want qemu, which runs virtual machines. qemu is pretty cool, I'll
show you how to log what instructions your VM is executing and other advanced
features.

How do I get a GCC Cross compiler?
----------------------------------
There is a script in `scripts/build_cross_compiler.sh`. It will try to
download and compile GCC for the Raspberry Pi, but it might not work on your
specific setup (this is Linux after all).
If you run into problems you can ask me. You can also join `#gcc` on
`irc.freenode.net` and ask questions ther.
Once it compiles the resulting binary will be stored at `compiler/arm/`.



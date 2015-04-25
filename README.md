Pop Open a Kernel
=================

This is an introduction to writing a simple kernel for x86

Talk Description
----------------

Ever wanted to build a simple kernel for a small computer? Curious how an OS
starts and how it communicates with your keyboard and screen? Together, we'll
build a simple kernel from scratch. No experience in assembly language or
knowledge about CPU architecture is required, just some basic knowledge of
C/C++ and curiosity about how things work under the hood.
Description

A kernel is such a fundamental, and much hyped, part of an operating system,
but most people don’t know how one works.
In this talk we’ll cover both the theory of kernel architecture design, and get
our hands dirty tearing apart a simple one.
We’ll start by describing the jobs of a kernel, then well talk about different
architectures and ways of achieving these goals.
Then we’ll look at the code from the bottom up, and describe how a kernel is
compiled and linked.
Next is the boot process. We’ll get in to the gritty details of what happens
once the power button is pushed, describe the boot loader, how the kernel is
loaded into memory, executed, and how the first user process starts.
We’ll discuss hardware interrupts and protection rings. We’ll even have to
learn a little bit of x86 assembly, but don’t be scared!
Finally we’ll take a look at multitasking, paging, and maybe file systems, and
system calls if we have time.
This session will be hands on – we get to take a look at a toy kernel, boot it,
watch it work and watch it fail. We’ll learn about hardware, low-level
software, and algorithms for multitasking and paging.



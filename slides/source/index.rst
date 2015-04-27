Pop Open a Kernel
=================

.. figure:: /_static/popcorn.png
	:width: 50%
	:align: center

Who am I?
---------

Ian Kronquist.

Developer at the Oregon State University Open Source Lab and a student.

iankronquist@gmail.com

muricula on Freenode, PSU IRC, and  Mozilla IRC networks.

@muricula on twitter.


.. figure:: /_static/osllogo.png
	:width: 50%
	:align: center

Changes in the program (sorry!)
-------------------------------

* The example kernel is x86, not ARM. There are more examples on the interwebs
  for x86 kernels.
* This session won't be as hands on as I hoped. It turns out getting everyone
  on the same page is hard.
* I may run short. That's okay, it means more time for questions!

What is a kernel and What Does it Do?
-------------------------------------
* The kernel is at the heart of the OS. It is among the first programs to start
  up and the only one always running.
* The kernel is the middleman between "normal" or userspace programs and your
  computers hardware.

.. figure:: /_static/tux.png
	:width: 30%
	:align: center



What's the difference between a kernel and an Operating System?
---------------------------------------------------------------

* A kernel is just one part of an operating system, and it's hardly the only
  part which matters.
* An operating system might include init systems, to start up programs and
  windowing managers, to draw windows on the screen,
* Most modern OSs include everything and the kitchen sink, including web
  browsers, office suites, desktop environments, you name it.
* Linux is the name of a *kernel*. Pedants like to call the whole OS
  *GNU/Linux*.

A Brief History of Kernels
--------------------------

* In the old old days only one program would run at a time. The level of safety
* and abstraction a kernel provides wasn't needed.
* Most research into kernels happened in the 1970s and 1980s.
* Most kernels widely used today have been around at least since the 1990s.
* Unix was the name of an operating system developed by Ken Thompson and Dennis
  Ritchie. They designed the C programming language in order to write Unix.

Kernels in Use Today
--------------------

* XNU Kernel (the modern OSX kernel) 1996
* Windows NT (the modern Windows kernel) 1993
* Solaris 1992
* Linux 1991
* GNU Hurd (A FOSS Linux competitor) 1983
* BSD 1977
* Unix 1973

A History of Unix Kernels
-------------------------

.. figure:: /_static/unix_history.png
	:width: 100%
	:align: center


Why is studying kernels relevant in the 21st century?
-----------------------------------------------------
Really interesting stuff is happening! In Linux we're seeing


* Reboot free updates with KSplice.
* Linux Containers, a technology originally developed in 2008, is now
  almost mature enough to use for production tools like Docker.
* Formal verification of Linux systems is an open challenge put out by some
  Linux kernel developers.


Different Kernel Architectures
------------------------------

There are three types of Kernel architectures.

* Microkernel
    - Runs drivers in userspace.
	- Task switching between userspace and kernel mode is expensive.
	- Examples: Various embedded kernels you've never heard of.
* Monolithic kernel
    - Runs drivers in kernel mode.
	- Broken drivers can take down the whole system.
	- Examples: Linux, BSD

.. nextslide::

* Hybrid kernel
    - A bit of both. Core services are baked into the kernel, but it offers
	  ways to run other drivers in userspace.
    - Examples: Windows, OS X
* A unikernel is a kernel which runs one program.

.. figure:: /_static/darwinmascot.png
	:width: 30%
	:align: center

- Either really old fashioned or really cutting edge.

Kernel Modules
--------------

It's really handy to be able to load drivers while the kernel is running
without rebooting. Linux does this using kernel modules.

A compromise between monolithic kernels and hybrid kernels.

Run ``lsmod`` to see what kernel modules your machine is running.

.. figure:: /_static/openbsd.png
	:width: 50%
	:align: center


User mode and Kernel mode
-------------------------

* Most kernels use hardware memory protection.
* At boot, the kernel set up the processor so that some parts of memory can
  only hold kernel code, and other parts can only hold user code. Likewise,
  some parts of memory can only hold data.
* There are four different protection "rings". The kernel runs on ring 0.
  User code runs on ring 3. Rings 1 & 2 aren't really used anymore.
* If code running in user mode (like any program you write) tries to access
  memory it doesn't have permission to use, it will trigger page fault, which
  is a special type of interrupt. The kernel typically just kills the program.

Hardware Interrupts
-------------------
* How does the kernel listen to the hardware clock, or process keystrokes?
* Every time you press a key, a signal is sent to the process or which triggers
  a hardware interrupt.
* The kernel stops whatever it's doing, looks up the interrupt number in a
  table, and executes a function in the table which might read the message the
  keyboard saying which key was pressed.

Making Syscalls
---------------
* An interface between your program and the kernel. Typically a function you
  call in your program.
* Any time you read from a file with ``read`` or ``fread`` you make a syscall.
* Your program talks to the kernel, which talks to the file system driver,
  Which talks to your hard-drive which reads some data and passes it back up
  the chain.
* How syscalls are actually made is architecture dependent.

Linux Syscalls on x86
---------------------
* Syscalls are kept in a table. The table describes what number the syscall is,
  what calling convention to use (that's an assembly thing) and a pointer to
  the function in the kernel which implements the syscall.
* Your program loads a number representing which syscall to make into the eax
  register, and triggers interrupt 0x80.
* The kernel's interrupt handler looks up its function in the table which
  implements the syscall, and calls it.


Questions?
----------
Ian Kronquist.

iankronquist@gmail.com

muricula on Freenode, PSU IRC, and  Mozilla IRC networks.

@muricula on twitter.



My Kernel
---------

* It's written in C and some x86 assembly.
* It boots and prints "Hello Kernel" to the screen.


What Do I Need to Know to Write a Simple One?
---------------------------------------------

* Surprisingly little!
* Some basic C/C++
* However, be prepared to learn a *lot*


What Do I Need to Get Started?
------------------------------

We will start by running the kernel in a virtual machine.

* I'm going to install you're running Ubuntu or something similar.
* I'm going to assume you know some C or C++. Maybe you can write a program
  which fills a linked list with the first 100 Fibonacci numbers.
* Install qemu, which is for running virtual machines.
  `sudo apt-get install qemu`
* You will need to build a cross-compiler.
  This may actually be the hardest part.

What is a Cross-Compiler?
-------------------------

* The Kernel runs on a different hardware architecture than your laptop.
* Your computer is probably x86_64.
* We need to build a special version of GCC to compile code.
* Luckily I wrote a script to make this easier for you!
  No guarantees that it will work - building complicated programs like GCC can
  get complicated.


Questions?
----------
Ian Kronquist.

iankronquist@gmail.com

muricula on Freenode, PSU IRC, and  Mozilla IRC networks.

@muricula on twitter.



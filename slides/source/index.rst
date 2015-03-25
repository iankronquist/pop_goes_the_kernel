Pop Open a Kernel
=================

Who am I?
---------

My name is Ian Kronquist.
I am a developer at the Oregon State University Open Source Lab and a student.
I think kernels are awesome!

iankronquist@gmail.com
muricula on Freenode and Mozilla IRC networks.

What is a Kernel and What Does it Do?
-------------------------------------

This Kernel
-----------

* It's written in C and some ARM assembly.
* It boots on the Raspberry Pi. If you plug in a keyboard
  you can type on the screen.
* It implements interrupts (more about those later).

What Do I Need to Know to Write a Simple One?
---------------------------------------------

* Surprisingly little!
* Some basic C/C++
* However, be prepared to learn a *lot*

* The code and slides for this talk live at:
  https://github.com/iankronquist/pop_goes_the_kernel
  You may want to clone the repository and follow along,
  or just browse the code online.

Linus Torvalds, creator of the Linux Kernel says:
"Kernel coding style is super simple."

What are We Going to Learn About?
---------------------------------
* We will learn a little bit about assembly


What Do I Need to Get Started?
------------------------------

We will start by running the kernel in a virtual machine.

* I'm going to install you're running Ubuntu or something similar.
  You can in theory do all of this on any system including a Mac or
  (if you are very brave) Windows with Cygwin.
* I'm going to assume you know some C or C++. Maybe you can write a program
  which fills a linked list with the first 100 Fibonacci numbers.
* Install qemu, which is for running virtual machines.
  `sudo apt-get install qemu`

* You will need to build a cross-compiler.
  This may actually be the hardest part.

What is a Cross-Compiler?
-------------------------

* The Raspberry Pi has a different hardware architecture than your laptop.
  It is an ARM computer.
* Your laptop is probably x86 or x86_64.
* Code compiled on your laptop with your normal compiler won't work on the
  rasppi and vice-versa.
* We need to build a special version of GCC to compile code for the
  raspberry pi.
* Luckily I wrote a script to make this easier for you!
  No guarantees that it will work - building complicated programs like GCC can
  get complicated.


Building a Cross-Compiler
-------------------------

* To build the cross compiler you need GCC and a couple libraries.
  `$ sudo apt-get install gcc gcc-c++ gmp-dev mpfr-dev`

* Run the following command, and be patient, it may take a while (20+ minutes):
  `$ sh scripts/build_cross_compiler.sh`

* If it fails, ask for help.

* If you are on a Mac or a weird system building GCC can be painful.
  You can try and use the Vagrantfile in the repository. If you don't know what
  that means, ask.

+-----+----------------------------------------------------------------+
|CPU: | 700 MHz ARM1176JZF-S core (ARM11 family, ARMv6 instruction set)|
+-----+----------------------------------------------------------------+


How Does the Kernel Boot?
-------------------------

How Does the Linux Boot Process Differ?
---------------------------------------

Yikes, Assembly!
----------------
* It's not so bad.
* ARM assembly is easier than other kinds.
* Each assembly line is called an instruction.
* Each instruction has two or three parts.


Sections in boot.S
------------------

kernel.c
--------

* Pretty straightforward actually.

* Sets up these things called interrupts


What is an Interrupt?
---------------------

What is an Interrupt Handler and How Do We Write One?
-----------------------------------------------------

How Do We Read From the Keyboard?
---------------------------------

How Do We Allocate Memory?
--------------------------

Review on Processes
-------------------

How Do We Switch Between Processes?
-----------------------------------

How Do We Schedule Processes?
-----------------------------

Questions?
----------
Ian Kronquist.
iankronquist@gmail.com
muricula on Freenode and Mozilla IRC networks.

The code and slides for this talk live at:
https://github.com/iankronquist/pop_goes_the_kernel



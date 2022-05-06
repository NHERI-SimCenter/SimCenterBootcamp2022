
.. _lblComputer:

******************
What is A Computer
******************

What is a computer entered into google:

#. `A computer is an electronic device that manipulates information, or data. It has the ability to store, retrieve, and process data. <https://edu.gcfglobal.org/en/computerbasics/what-is-a-computer/1/>`_
#. `An electronic device for storing and processing data, typically in binary form, according to instructions given to it in a variable program. <https://www.lexico.com/en/definition/computer>`_
#. `A computer is a machine that can be instructed to carry out sequences of arithmetic or logical operations automatically via computer programming. <https://en.wikipedia.org/wiki/Computer>`_
#. `A computer is a programmable device that stores, retrieves, and processes data. The term "computer" was originally given to humans (human computers) who performed numerical calculations using mechanical calculators, such as the abacus and slide rule. The term was later given to a mechanical device as they began replacing the human computers. Today's computers are electronic devices that accept data (input), process that data, produce output, and store (storage) the results. <https://www.computerhope.com/jargon/c/computer.htm>`_

In short computers are basically simple machines that perform operations/calculations on data. Their rise is due to the fact that they can perform these calculations incredibly fast. 

Computer Hardware
-----------------

Most programmable computers (desktop, servers, phones, programmable calculators, ...) when you take apart all have similar components:

#. Central Processing Unit (CPU) where data is manipulated.
#. Memory for storing data:
   #. Hard Drive (disk or SSD) for the permanent storage of the data
   #. Random Access Memory (RAM) for temporary storage of data (data being lost when power goes off)
#. Input Devices (keyboard, monitor, network)
#. Output Devices (Monitor, Speakers)
#. Motherboard (the chasis of the computer) the thing to which everything is connected and the Powersupply to provide power to the connected devices.

These fundamental components have existed in most programable computers for the last 70years. The architecture for this was something described by `John Von Neumann in 1945 in his description of the EDVAC system <http://qss.stanford.edu/~godfrey/vonNeumann/vnedvac.pdf>`_.

   .. figure:: figures/vonNewmann1.png
      :align: center
      :figclass: align-center

      vonNewmann Computer Architecture

John in his architectural description further broke the **CPU** into parts:

#. The Control Unit (CU): The control unit decodes what each instruction means, and can then control how the other components operate. So when the control unit receives an instruction, which is just a binary number, it will then signal what the ALU and memory is supposed to do. It might be that the instruction is to add two numbers together, or it might be that the instruction is to store a number in RAM.

#. The Arithmetic Unit (ALU): The ALU performs a variety of operations. It can add and add binary numbers, increment bits, and compare binary numbers to see if they are the same. Modern ALU also contain circuits to perform operations on floating point numbers (add, subtraction, multiplication, division), something that would have to have been performed in code in older computers or using a connected devuce called a floating point unit.

#. Registers: Registers are parts of the CPU that store data. In this sense they are like memory, the difference is that the memory cells are composed of logic gates for fast access to the contents. There are a number of different types of registers for different purposes:
   
   #. Instruction Register: Stores address of current instruction
   #. Program Counter: Stores address in RAM of next instruction
   #. Memory Address: Stores RAM location of data
   #. Memory Data: Stores the data obtained from RAM   
   #. Accumulator: For storing results of ALU opeartions

.. figure:: figures/vonNewmann2.png
   :align: center
   :figclass: align-center

   More Detailed vonNewmann Architecture

The **programs** that the computer runs to manipulate the data are a sequence of unambiguous instructions that are meant to be followed in sequence by the CPU. The program, or list of instructions to be followed, is stored in the main memory. As the program executes each instruction is brought into the CPU (fetched), deciphered, and executed. The CPU does this repeatedly until the program finishes. To do this the CPU must be able to store the current instruction, store a counter to hold the count of the current instruction (so that location of next instruction can be fetched), contain elements for storing data on the CPU itself (registers: small memory units capable of each holding a single number), and provide units for performing arithmetic operations. The first CPU's where the size of rooms and made up of componnets such as vacuum tubes and swicthes. Modern CPU's (sometimes called microprocessors) are tiny containing millions of of tiny switches called transistors, which are wired together in such a way that an output from one switch can turn another switch on or off. As a computer computes, these switches turn each other on or off in a pattern determined both by the way they are wired together and the current instruction executing.

.. note::

   The CPU executes these instructions mechanically, i.e. without thinking about them.

When we think of the data that these programs work with we think of files containing numbers, images, text strings, movies. That could not be farther from the truth. The data stored on the computer and the data, the instructions and data being manipulated by the CPU consists soleley of binary digits (bits), **0**'s and **1**'s, a consequence of the binary nature of the transistor operations **on** or **off**. When a machine language instruction is loaded into the CPU, all that happens is that certain switches are turned on or off in the pattern that encodes that particular instruction. The CPU is built to respond to this pattern by executing the instruction it encodes; it does this simply because of the way all the other switches in the CPU are wired together. A consequence of this is that the instructions are kept pretty simple (there is only so much instruction that can be provided in a few dozen bits). These instructions include instructions to fetch some sequence of 4 bytes from memory and store them in register 1, or add the contents of registers 2 and 3 and store result in register 3.

.. note::

   A byte is collection of 8 bits.

Computer Software
-----------------

There are 2 types of programs running on the computer:

#. The Operating System. The operating system controls what is being run by the CPU, looks after the files stored in main memory, determines what is brought ito RAM, determines what is done when an interupt occurs.

#. Applications written to do useful work. These are the applications written by you and I and others that manipulate the data to do useful work. 

Ultimatly all these applications must be in the form of simple instructions of of 2 to 3 bytes containing 0's and 1's and stored in files managed by the operating system.













================
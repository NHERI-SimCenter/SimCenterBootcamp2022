C++ Exercises
=============

Today we have two problems for you to tackle.

Problem 1: Adding a ColoredShape
--------------------------------

Navigate to **/code/c++/ExerciseDay3/ex1/** to find the code for the C++ example presented in todays video. You are asked to create another shape of your choosing and add to the code base. A similar example was perfomed during the video.

.. hint::

   When starting a new **C++** class it is usual for developers to start by copying the **.h** and **.cpp** file of an existing working class that is similar to have the name of the new class they want. Then they open the new class and make isssue a global replacement to replace old class name with new name. This way they start with a working class. Then they would go into new class and start making modifications.

       .. code::

	$ cp workingClass.h newClass.h
	$ cp workingClass.cpp newClass.cpp
	$ emacs newClass.h
	emacs> <esc>%
	emacs> (asks for string to replace:>)  oldClass <enter>
	emacs> (asks for replacement string:>)  newClass <enter>
	emacs> !        <-- to replace all quickly
	emacs> // make other changes as needed
	emacs> <CTRL> XS
	emacs> <CTRL> XF
	emacs> newClass.cpp
	emacs> <esc>%
	$ (asks for string to replace:>)  oldClass <enter>
	$ (asks for replacement string:>)  newClass <enter>
	$ !        <-- to replace all quickly
	$ // make other changes as needed
	emacs> <CTRL> XF
	emacs> <CTRL> XC	

.. note::

   A **CMakeLists.txt** file has been provided. Add your file to it when created. The **cmake** command will check your system for compilers and other development tool and create a **Makefile** in each source folder. The **make** will build the executable(s). For subsequent builds, you only have to call **cmake** again if you change anything in the CMakeFilesList.txt file. Placing the compile files into a *build* folder makes cleanup easier: simply delete the entire *build* folder when done.  It can be regenerated easily using the procedure below.

   The build process again is:

   .. code::

	$ mkdir build
	$ cd build
	$ cmake ..
	$ make


.. note:: 




    
   
Problem 2: An engineering Vector Class requires you to finish off
-----------------------------------------------------------------

Navigate to **/code/c++/ExerciseDay3/ex2/** to find the partially completed code for a C++ Vector class. You are to finish it and test it. The directory contains a header file **Vector.h**,  an implementation file **Vector.cpp**, a **main.cpp** to test with and a **CMakeFilesList.txt** file for building and compiling.

The header file Vector.h:

.. literalinclude:: ./assignments/c3/Vector.h
  :language: c
  :linenos:


The implementation file Vector.cpp:
     
.. literalinclude:: ./assignments/c3/Vector.cpp
  :language: c
  :linenos:


.. hint::

   Wherever you see a comment **//PROVDE CODE** is a place you need to edit, e.g. line 8 requires some assignment using a  **new double[some value]**.

   

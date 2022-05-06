C: Day 2 In Class Exercises
===========================

Today we have several problems for you to tackle. 
Parts should look and feel familiar from Day 1, though we will add more features as we go.
Those problems are modeled after exercises in Python and, thus, allow you to learn how data structures
compare when transitioning from python to C (and later C++).



Problem 1: Reviewing the stress transformation problem
------------------------------
Navigate to **/code/c/ExerciseDay2/ex2-1/** to find another solution for the stress transformation
problem.  The main difference to Frank's solution is that this one places functions in separate files, as
well as adds a header file that contains the definition of the function without its implementation.

Compiling this version requires multiple steps:

.. code::

	gcc stresstransform.c -c
	gcc exercise2-1.c stresstransform.o -lm

And you can run the executable as

.. code::

	./a.out

Imagine doing this for many more files, usually tens to hundreds.  That would be painstaking and
inefficient and very error prone.  Software engineers developed several tools to simplify and automate the compile
process.  One of those tools is **cmake**, a member of the **make** family of tools.  You find a
configuration file names **CMakeList.txt** in the source folder. The configuration
file is a plain text file, so you can and should check out how it is written:


.. literalinclude:: ./solutions/c2/ex2-1/CMakeLists.txt
  :language: cmake
  :linenos:


The compile process now becomes 

1. a configuration step - done only once or every time you are adding a file to the project.  Inside the
source folder, execute

.. code::

	$ mkdir build
	$ cd build
	$ cmake ..


This will check your system for compilers and other development tool and create a **Makefile** in each
source folder. 

.. note:: 

    Placing the compile files into a *build* folder makes cleanup easier: simply delete
    the entire *build* folder when done.  It can be regenerated easily using the above procedure.

2. From now on, every time you make changes to any of the files within your project, simply
type

.. code::

	$ make

to recompile all portions necessary and link all parts to one executable.  That process remains exactly the
same regardless of the number of files in your project.  Give it a try and see how convenient this is
especially for projects provided by somebody else.
	    

	

      
   
Problem 2: Using structures
---------------------------------

The implementation of :code:`StressTransform()` was intentionally done a bit clumsy, just the way a beginner might
write it. Your task in this exercise is to create a structure 

.. code::

	typedef struct {
		double sigx;
		double sigy;
		double tau;
	} STRESS ;

and modify the code from the previous exercise to utilize the much easier to read data structure provided
by this :code:`struct`.  Use the code skeleton provided in **/code/c/ExerciseDay2/ex2-2** to develop that
code.  The included :code:`CMakeList.txt` shall be used to compile your code.

.. note::

   Your modified :code:`StressTransform(...)` will require a pointer to a :code:`STRESS` type object.  The
   way to achieve that in an efficient manner is to use a :code:`typedef struct {...} STRESS ;`.

   In addition, inside the function that receives the pointer to a structure, assigning a new value to
   entries in such a structure requires the syntax

   .. code::

      void StressTransform(STRESS stressIn, STRESS *stressOut, ....) {
	...
	stressIn->sigx = ... ;
      }

   This replaces the form

   .. code::

      *sigx = ... ;

   used for scalar-valued arguments.

A working solution is provided by the following set of files.

* stresstransform.c

.. literalinclude:: ./solutions/c2/ex2-2/stresstransform.c
  :language: c
  :linenos:

* stresstransform.h

.. literalinclude:: ./solutions/c2/ex2-2/stresstransform.h
  :language: c
  :linenos:

* exercise2-2.c

.. literalinclude:: ./solutions/c2/ex2-2/exercise2-2.c
  :language: c
  :linenos:


Problem 3: Writing data for use by other programs: CSV
_________________________________

While C is very powerful for numeric computations, it can be impractical to generate graphs or fancy
images using the computed values.  A more efficient way is to use C to do the analysis, write results to
an easily readable file, and use specialized tools for the post-processing.  One common and simple format
is **CSV** (comma-separated-values), which van be read easily by MATLAB, python, or Excel.  

**Your task**: modify the code given in **/code/c/ExerciseDay2/ex2-3** to

1. Take one argument :math:`\Delta\theta` in degrees after the name of the executable, defining the increment at
which transformed stress values shall be written:

.. code::

	$ Exercise2-3 5.0

The format of the output shall be for one angle per line, organized as follows:

.. code::

	theta, sigma_x, sigma_y, tau_xy
	...

Output shall commence until an angle of :math:`180^\circ` has been reached or exceeded.

Once your code outputs the information, run it once more and save the results to a file names
**list.csv** (make sure to add the spaces around the '>')

.. code::

	$ Exercise2-3 5.0 > list.csv

.. note::

    You may want to download the file **list.csv** to your local computer before trying the next step, for it
    will require access to your display.  That file can be opened in Excel and plotted there.  A more
    efficient way is to prepare some nice plotting code, such as the provided :code:`plotter.py`.  In the same
    folder where you placed **list.csv** run

    **Windows 10**

    .. code::

	    >> python.exe plotter.py


    **MacOS** or **Linux**

    .. code::

	    $ python3 plotter.py
	    
    Isn't that nice?
   

A working solution is provided by the following set of files.

*   *stresstransform.c* and *stresstransform.h* are identical to the ones created for **Problem 3**.

* exercise2-3.c

.. literalinclude:: ./solutions/c2/ex2-3/exercise2-3.c
  :language: c
  :linenos:

which creates a result like this:

.. literalinclude:: ./solutions/c2/ex2-3/list.csv
  :language: csv
  :linenos:

The *plotter.py* script that displays the data as Mohr's circle is given here to show how simple it is to
generate nice plots :red:`automagically`.

.. literalinclude:: ./solutions/c2/ex2-3/plotter.py
  :language: python
  :linenos:


.. figure:: ./solutions/c2/ex2-3/Figure_2-3.png
           :align: center
           :figclass: align-center

           Mohr's circle created from *list.csv* and *plotter.py*


Problem 4: Writing to a binary file
_________________________________


Modify the code generated in the previous exercise to write a binary file names *mohrcircle.dta* instead
of the formatted ASCII data.  The data shall be exported in clocks composed of :code:`double theta`
followed by a block of :code:`STRESS` (or the three components of stress as :code:`double`).

You may be working of your code or use the provided code skeleton in **/code/c/ExerciseDay2/ex2-4**.

This time, your code should be totally silent on execution.  The only sign of success will be the creation
of the data file. For the next steps, run your program with the following parameters:

.. code::

	$ Exercise2-4 5.0


.. note::

    How large do you expect the binary file to be?  Discuss, predicts, and check using

    .. code::

	    $ ls -l mohrcircle.dta

    You should be able to predict the **exact** number (to the byte!).


.. note::

    This problem comes with validation code, something worth developing every time you are working on
    software that will be modified over an extended period of time and/or by multiple people.

    The validation consists of (1) a C code :code:`parse.c` which reads the binary file and outputs its
    contents to a **CSV** file, and (2) a shell script :code:`validate.sh` that attempts to run the
    validation code and compares the output generated from your binary file to an output generated by a
    correct code.

    Run the validation script as

    .. code::

	$ sh ./validate.sh

    and check its feedback. (That script may not run on all platforms.)
    

A working solution is provided by the following set of files.

*   *stresstransform.c* and *stresstransform.h* are identical to the ones created for **Problem 3**.

* exercise2-4.c

.. literalinclude:: ./solutions/c2/ex2-4/exercise2-4.c
  :language: c
  :linenos:

Executing the generated executable as

.. code::

	$ Exercise2-4 5.0


creates a binary file *mohrcircle.dta* which has a size of (STRESS has 3 :green:`double` entires)

	(37 blocks) of (1 :green:`double` + 1 :green:`STRESS`) * ( 8 bytes/:green:`double` ) = 1184 bytes 

.. note::

    If your system has *gcc* installed, you may run the validation script to check your solution.
    Running it as

    .. code::
     
        $ sh ./validate.sh

    should generate the friendly answer:

    .. code::
    	
	**
	** Your code passed with flying colors!
	**

.. note::

    Binary files are not readable by traditional ASCII editors (text editors).  Doings so, usually shows
    some unintelligible scramble of characters, sometimes leaving your terminal in an unusable state.

    However, you may view binary files using a *hex-dump* utility.  That approach may help you understand
    and recover the structure of a binary file (though it still requires some practice and skill and
    **luck**).  You may try such a tool on your binary file using

    .. code::

	$ xxd mohrcircle.dta | less

    where the :code:`| less` pipes the output in a pager utility that allows you to search the output,
    jump pages forward and backward, or move to any specific line.  Press :code:`q` to exit this utility.

    You should get something like this output:

    .. literalinclude:: ./solutions/c2/ex2-4/hexdump.txt
      :language: c
      :linenos:



Problem 5: Reading From a binary file
_____________________________________

Reading of data from files and placing them into containers such as Vectors is easy if you know the size of the data you are reading. If this is unknown the problem becomes more tricky. The solution presented on slide 22 worked for a small number of nputs, but failed with a segmentation fault for larger problems. You are to fix the problem. A copy of the offending files has been placed in the directory ex2-5 along with two files. The program can handle the first **small.txt**, it will fail with the second **big.txt**. Can you make the program work. The solution will test your understanding of file I/O,  memory management and pointers.

.. note::

   No cmake or Makefile has been provided. You can compile the file with icc or whatever compiler you are using. The program takes a single input, the file to read. To compile and test the program, issue the following at the terminal prompt.

   .. code::

      icc file2.c -o file2
      ./file2 small.txt
      ./file2 big.txt
 


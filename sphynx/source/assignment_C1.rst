C Variables and Functions
=========================

Today we have three problems for you to tackle. Two are familiar and you performed them in Python as part of day 1 exercises and assignments. The third **pi** is new.

Problem 1: Solve the Quadratic
------------------------------
We wish to solve the quadratic equations, i.e. given **a**, **x**, and **c**, solve the following equation for **x**. 

.. math::

   ax^2+bx+c=0

The solution from your high school days is the legendary formula:

.. math::

    x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}

We want you to write an application developed in  **C** to solve this equation.

To start you off, we have provided a file **solveQuadratic.c** in **/code/c/ExerciseDay1/** which will read 3 numbers from the command line and print out a message to the screen. You are to modify it to print out the solution for **x**.

.. code_block:: c
  :linenos:
     
   /* *********************************************************                    
   //                                                                              
   // program to solve quadratic equation                                          
   //        ax^2 + bx + c = 0                                                     
   //                                                                              
   // soln: x = -b/2a +/- sqrt(b^2-4ac)/2a                                         
   //                                                                              
   // write a program to take 3 inputs and output the soln                         
   // deal with possible errors in input, i.e. b^2-4ac negative                    
   //                                                                              
   *********************************************************** */

   #include <stdlib.h>
   #include <stdio.h>
   #include <math.h>
   
   int main(int argc, char **argv) {

      if (argc != 4) {
         printf("Usage: appName a b c\n");
         exit(-1);
      }

      float a = atof(argv[1]);
      float b = atof(argv[2]);
      float c = atof(argv[3]);

      printf("Have a Nice Day!\n");
      return 0;
   }

.. note::

   When compiling because you will be using functions from the **C** math library you will need to include the math library when you compile and link your code, i.e.

   .. code::

      gcc solveQuadratic.c -lm
      
The solution `solveQuadratic.c  <https://github.com/NHERI-SimCenter/SimCenterBootcamp2020/tree/master/code/c/ExerciseDay1/solutions/solveQuadratic.c>`_ can be found on github. The contents of that file is presented here:

.. literalinclude:: ./solutions/c1/solveQuadratic.c
  :language: c
  :linenos:

      
Problem 2: Stress Transformations
---------------------------------

To transform stress to a rotated coordinate system one can use the formula shown in the figure. We would ask you to write code that will take as input **4** values  sigmaXX, sigmaYY, tauXY, and **theta** compute the stress in the transformed coordinate system. We would ask you to perform that transformation computation in a function other than **main** and to complicate things, but demonstrate you understand passing of arrays, pass the input and output stresses to this new function in fixed length arrays.

   .. figure:: figures/stress.png
           :align: center
           :figclass: align-center

           Equation for stress transformation

.. note::

   If you need something extra work, write to a file the results of this transformation from **0** through **360** degrees in increments you input from the command line.

      To send you data to a file named **results.out**, start the application as follows:   

      .. code::

      ./appName 1.0 100.0 0.01 1 > results.out


      The solution `transformStress.c  <https://github.com/NHERI-SimCenter/SimCenterBootcamp2020/tree/master/code/c/ExerciseDay1/solutions/transformStress.c>`_ can be found on github. The contents of that file is presented here:

.. literalinclude:: ./solutions/c1/transformStress.c
  :language: c
  :linenos:
   


Problem 3: Compute PI numerically
_________________________________

The figure below shows an method to compute **pi** by numerical integration. We would like you to implement that computation in a **C** program.

   .. figure:: figures/pi.png
           :align: center
           :figclass: align-center

           Computation of pi numerically


.. note::

   You will be using your solution on Day 4 as part of the parallel exercises.
   
	   
      The solution `pi.c  <https://github.com/NHERI-SimCenter/SimCenterBootcamp2020/tree/master/code/c/ExerciseDay1/solutions/pi.c>`_ can be found on github. The contents of that file is presented here:

.. literalinclude:: ./solutions/c1/pi.c
  :language: c
  :linenos:

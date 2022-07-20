C: Assignments Day 1
====================

Today we have three problems for you to tackle. Two are familiar and you performed them in Python as part of day 1 exercises and assignments. The third **pi** is new.


.. warning::

   In the Python part of the bootcamp pretty much everything was set up for you with Jupyter notebooks that were supplied. In this part of the bootcamp we will only be providing you with ONE example file. You will in a hurry have to learn some **emacs** and basic **git** and **linux** commands. The sidebar on the left contains some basic instruction on these (enough to get you through this part of the bootcamp). The training wheels have been removed!

   
Problem 1: Solve the Quadratic
------------------------------
We wish to solve the quadratic equations, i.e. given **a**, **b**, and **c**, solve the following equation for **x**. 

.. math::

   ax^2+bx+c=0

The solution from your high school days is the legendary formula:

.. math::

    x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}

We want you to write an application developed in  **C** to solve this equation.

To start you off, we have provided a file **solveQuadratic.c** in **/code/c/ExerciseDay1/** which will read 3 numbers from the command line and print out a message to the screen. You are to modify it to print out the solution for **x**. The contents of this file are shown below.

.. literalinclude:: ./assignments/c1/solveQuadratic.c
   :language: c
   :linenos:
		
.. note::

   When compiling because you will be using functions from the **C** math library you will need to include the math library when you compile and link your code, i.e.

   .. code::

      gcc solveQuadratic.c -lm

.. only:: C_DAY1_SOLUTION
	  
	  The solution `solveQuadratic.c  <https://github.com/NHERI-SimCenter/SimCenterBootcamp2022/tree/master/code/c/ExerciseDay1/solutions/solveQuadratic.c>`_ can be found on github. The contents of that file is presented here:

	  .. literalinclude:: ./solutions/c1/solveQuadratic.c
	     :language: c
             :linenos:

      
Problem 2: Stress Transformations
---------------------------------

To transform stress to a rotated coordinate system one can use the formula shown in the figure. We would ask you to write code that will take as input **4** values  sigmaXX, sigmaYY, tauXY, and **theta** compute the stress in the transformed coordinate system. We would ask you to perform that transformation computation in a function other than **main** and to complicate things, but demonstrate you understand passing of arrays, pass the input and output stresses to this new function in fixed length arrays.

**Theory**: Stress transformation

.. math::
    \sigma_x' = \sigma_x \cos^2\theta + \sigma_y \sin^2\theta + 2 \tau_{xy} \sin\theta \cos\theta \\
    \sigma_y' = \sigma_x \sin^2\theta + \sigma_y \cos^2\theta - 2 \tau_{xy} \sin\theta \cos\theta \\
    \tau_{xy}' = ( \sigma_y - \sigma_x ) \sin\theta \cos\theta + \tau_{xy} ( \cos^2\theta - \sin^2\theta ) 

**Given state**:

.. math::
    \sigma_x = 12~\text{ksi}~, \qquad
    \sigma_y = -5.5~\text{ksi}~, \qquad
    \tau_{xy} = 3.5~\text{ksi}

.. note::

   If you need something extra work, write to a file the results of this transformation from **0** through **360** degrees in increments you input from the command line.

      To send you data to a file named **results.out**, start the application as follows:   

      .. code::

      ./appName 1.0 100.0 0.01 1 > results.out


.. only:: C_DAY1_SOLUTION
	  
      The solution `transformStress.c  <https://github.com/NHERI-SimCenter/SimCenterBootcamp2022/tree/master/code/c/ExerciseDay1/solutions/transformStress.c>`_ can be found on github. The contents of that file is presented here:

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
   
.. only:: C_DAY1_SOLUTION
	  
      The solution `pi.c  <https://github.com/NHERI-SimCenter/SimCenterBootcamp2022/tree/master/code/c/ExerciseDay1/solutions/pi.c>`_ can be found on github. The contents of that file is presented here:

      .. literalinclude:: ./solutions/c1/pi.c
         :language: c
         :linenos:

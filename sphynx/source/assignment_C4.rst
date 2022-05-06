C: Parallel Programming
=======================

Today we have two problems for you to tackle. They both parallelize the **pi.c** code you developed for day 1. Both programs will need to be compiled at one of the TACC supercomputers.

The figure below shows an method to compute **pi** by numerical integration. We would like you to implement that computation in a **C** program.

   .. figure:: figures/pi.png
           :align: center
           :figclass: align-center

           Computation of pi numerically

	   
The solution `pi.c  <https://github.com/NHERI-SimCenter/SimCenterBootcamp2020/tree/master/code/c/ExerciseDay1/assignments/pi.c>`_ can be found on github. The contents of that file is presented here:

.. literalinclude:: ./assignments/c4/pi.c
  :language: c
  :linenos:

.. note::

   1. When compiling at TACC if you wish to use **gcc** as I have done, issue the following command when you login.

   .. code::

      module load gcc         

   2. When building and testing that the application works, use **idev**, as I have been showing in the videos.

   3. When launchig the job to test the performance you will need to use **sbatch** and place your job in the queue. To do this you need to create a script that will be launched when the job runs. I have placed two scripts in each of the file folders. The script informs the system how many nodes and cores per node, what the expected run time is, and how to run the jib. Once the executable exists, the job is launched using the following command issued from a **login** node:

      
   .. code::

      sbatch submit.sh   

  Full documentation on submitting scripts for **OpenMP** and **MPI** can be found `online at TACC <https://frontera-portal.tacc.utexas.edu/user-guide/scripts/>`_
     
.. warning::

   Our solution of **pi.c** as written as a loop dependency which may need to revise for the second problem.
   
Problem 1: Parallelize using **MPI**
------------------------------------

You are to modify the **pi.c** application and run it to use mpi. I have included a few files in code/parallel/ExercisesDay4/ex1 to help you. They include **pi.c** above, gather1.c and a submit.sh script. **gather1.c** was presented in the video, and us shown below:

.. literalinclude:: ./assignments/c4/gather1.c
  :language: c
  :linenos:

The submit script is as shown below.

.. literalinclude:: ./assignments/c4/submit.sh
  :linenos:


One possible solution, which includes multiple approaches, is as shown in the following:

.. literalinclude:: ./solutions/c4/piMPI.c
  :linenos:
     
Problem 2: Parallelize using OpenMP
-----------------------------------

You are to modify the **pi.c** application and run it to use mpi. I have included a few files in code/parallel/ExercisesDay4/ex1 to help you. They include **pi.c** above and submitPI.sh script. **submitPI.sh** is as shown:

.. literalinclude:: ./solutions/c4/submitPI.sh
  :linenos:

One possible solution, which includes multiple approaches, is as shown in the following:

.. literalinclude:: ./solutions/c4/piOpenMP.c
  :linenos:

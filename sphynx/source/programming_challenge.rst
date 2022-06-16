Challenge Problem
-------------------
The goal is to create an object-oriented truss analysis program that

1. is based on the finite element method
#. handles arbitrary trusses in 2D
#. allows for arbitrary loading
#. can plot its undeformed and deformed shape

In order to succeed, we shall devide the task and conquer one class per team.
We will use Friday's session to combine your components into a single application.

The program will need and use the following objects:

Node
^^^^^^^^^^^^^^^^^^^^
Each instance represents one node in the system

.. list-table:: Node class
   :widths: 25 25 25 50
   :header-rows: 1

   * - method
     - input
     - returns
     - description
   * - `__init__(...)`
     - 
     - n/a
     - constructor.
   * - ` `
     - 
     - 
     - 
   * - ` `
     - 
     - 
     - 
   * - ` `
     - 
     - 
     - 
   * - ` `
     - 
     - 
     - 

Element
^^^^^^^^^^^^^^^^^^^^
Each instance represents one truss member

.. list-table:: Element class
   :widths: 25 25 25 50
   :header-rows: 1

   * - method
     - input
     - returns
     - description
   * - `__init__(...)`
     - 
     - n/a
     - constructor.
   * - ` `
     - 
     - 
     - 
   * - ` `
     - 
     - 
     - 
   * - ` `
     - 
     - 
     - 
   * - ` `
     - 
     - 
     - 

Material
^^^^^^^^^^^^^^^^^^^^
**This class is provided as a demonstration example.**


.. list-table:: Material class
   :widths: 25 25 25 50
   :header-rows: 1

   * - method
     - input
     - returns
     - description
   * - `__init__(...)`
     - parameters as `{'E':10.0}`
     - n/a
     - constructor. Sets parameters for this material and initializes all internal variables
   * - `getStress()`
     - 
     - :math:`\sigma`
     - request axial stress
   * - `getStiffness`
     - 
     - :math:`E_t`
     - request axial stiffness
   * - `setStrain(eps)`
     - strain :math:`\varepsilon`
     - n/a
     - update state for a user provided axial strain value
   * - ``
     - 
     - 
     - 

System
^^^^^^^^^^^^^^^^^^^^
Creates an instance of a truss model

.. list-table:: System class
   :widths: 25 25 25 50
   :header-rows: 1

   * - method
     - input
     - returns
     - description
   * - `__init__(...)`
     - 
     - n/a
     - constructor.
   * - ` `
     - 
     - 
     - 
   * - ` `
     - 
     - 
     - 
   * - ` `
     - 
     - 
     - 
   * - ` `
     - 
     - 
     - 

Plotter
^^^^^^^^^^^^^^^^^^^^


.. list-table:: Plotter class
   :widths: 25 25 25 50
   :header-rows: 1

   * - method
     - input
     - returns
     - description
   * - `__init__(...)`
     - 
     - n/a
     - constructor.
   * - ` `
     - 
     - 
     - 
   * - ` `
     - 
     - 
     - 
   * - ` `
     - 
     - 
     - 
   * - ` `
     - 
     - 
     - 


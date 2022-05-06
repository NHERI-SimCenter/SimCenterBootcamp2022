Writing Equations in documentation
==================================

The preamble: defining macros, environments, etc.
This only needs to be done once at the start of a document.  All remaining equations will know about
those definitions.

.. code::

   \def\RR{\mathbb{R}}
   \def\bold#1{{\bf #1}}
   \def\vectr#1{{\bf #1}}


.. math::
   \def\RR{\mathbb{R}}
   \def\bold#1{{\bf #1}}
   \def\vectr#1{{\bf #1}}
   
Using the new macros in an equation is as easy as:

.. code::

   {\bf v} \in \RR^n
   
.. math::

   {\bf v} \in \RR^n
   
Just to demonstrate that the definitions remain working past first use, simply add another equation.

.. code::

   \bold{K}\cdot\vectr{x} = \vectr{b}
   
.. math::

   \bold{K}\cdot\vectr{x} = \vectr{b}
   
Now that was easy.


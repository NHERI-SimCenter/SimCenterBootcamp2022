Graphical User Interface (GUI) Programming
***************************

While HPC computers are designed for heavy duty number crunching, they are not designed for an easy or
pretty user experience.  Desktop and Laptop computers, however, focus on user experience, and so
should your desktop applications.  The solution lies in the addition of a graphical user interface
(GUI) to your program.  

You already possess most of the programming skills needed.  The concept is
based on object oriented programming with some variations:

* **Graphic objects**: The "data" in each object is a visual graphic object, e.g., a label, push-button, a checkbox, etc.

* **Event-driven programming**: There is no pre-defined sequence in which your code will be executed.  Instead, the sequence is
  determined at runtime through user input (mouse action, keyboard input). 

Our demonstration uses the `Qt library <https://www.qt.io/>`_ . Qt is a cross-platform development
library that provides a wide range of graphical objects, advanced data types, and algorithms.
Moreover, it is a C++ library that is also offered as a python library, making code development easily
portable between python and C++.



Setup
====================

.. note::

    If you plan on following the demonstration on your own computer, or developing GUI applications
    later, you need to install one of the following.


Python
-------

.. code::

    pip install pyqt5


C++
-----

1.  Make sure you have a suitable C++ compiler installed (Windows: VisualC++ or gcc, MacOS: xcode  the 
command-line-tools from apple, or gcc, linux: gcc).  If you do not have one installed, you may want to try mingw, which comes with the
Qt installation (step 2).

2.  Download the installer for the **free** version of the Qt framework from the 
    `Downloads for open source users <https://www.qt.io/download>`_ .

    Make sure to select Qt and QCreator when running the installer.  
    As a beginner, you do not need all the extra packages offered by the installer, just the basics.



Quick Demonstration
====================


.. raw:: html

       <p><iframe width="560" height="315" src="https://www.youtube.com/embed/QR94VsXgTmc" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe></p>



Resources
====================

1. Getting Qt

    * Qt download page: https://www.qt.io/download 

2.  The "whole nine yards" Documentation

    * Full Qt5 documentation (a lot of information): https://doc.qt.io/qt-5/reference-overview.html

3. Our favorite tutorials

    * Qt5 quick start tutorial (C++): http://zetcode.com/gui/qt5/
    * pyqt5 quick start tutorial (python): http://zetcode.com/gui/pyqt5/ 

4. `Archived course notes from our 2018 Bootcamp <https://github.com/NHERI-SimCenter/SimCenterBootcamp2020/blob/master/presentations/NHERI-SimCenter-GUI-Qt.pdf>`_



.. _lblSetup:

******************
Setup Instructions
******************


Windows Computer
================

The following video demonstrates these installation instructions on a brand new Windows 10 system.

.. raw:: html

   <p><iframe width="560" height="315" src="https://www.youtube.com/embed/ywUDEEra0ns" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe></p>


These instructions are for a Windows 10 computer. You need to install Python, ssh and git.

.. note::

   These instructions should work for other versions of windows. However you will need to test them. In addition you will need to install a working version of **ssh** on your system. This is preloaded on Windows 10 machines.

Fork the SimCenter Code Repository
----------------------------------

#. Go to `github <https.github.com>`_ and sign in or sign up.
#. Go to the `SimCenterBootcamp2020 <https://github.com/NHERI-SimCenter/SimCenterBootcamp2020>`_ repository.
#. In the very top right corner, where it has fork and a number beside it, click the fork button. This will create a fork of the Bootcamp repo in your own account. 

Install Git
-----------

Install git from the `git download page <https://git-scm.com/downloads>`_. Once installed, open up powershell and **clone** your copy of the bootcamp repo by typing the following in powershell terminal:

.. code-block:: python
   
   git clone https://github.com/YOUR-GIT-LOGIN/SimCenterBootcamp2020.git

.. warning::

   replace YOUR-GIT-LOGIN with your github login name

.. note::

   To start a powershell window you use the search option and type PowerShell. Start the PowerShell application when it pops up.

Install Python on Windows
-------------------------

If you have not yet installed Python 3.7, we recommend installing Python 3.7 from `Python.org <https://www.python.org/downloads/windows>`_. We recommend installing using the 
**Windowsx86 64-bit executable installer**.  

.. note::

   Allow the installer to change your system environment variables so that the directory containing the executable is on your path. This requires checking the small box asking for this when the installer starts. The box is located at bottom of installer application window.

.. warning::
   The latest version of Python is 3.8.5 At time of writing Python 3.8.5 was not working with the current **numpy** package.

Once Python is installed, you need to extend it by installing a number of packages. To install these packages, start a `terminal window as an Admin user <https://www.howtogeek.com/194041/how-to-open-the-command-prompt-as-administrator-in-windows-8.1/>`_ and in that window type the following instructions:

.. code-block:: python

   pip install numpy
   pip install scipy
   pip install matplotlib
   pip install pandas 
   pip install openpyxl 
   pip install xlrd 
   pip install xlwt 
   pip install xlsxwriter
   pip install selenium 
   pip install bs4 
   pip install lxml 
   pip install requests 
   pip install geopandas 
   pip install census 
   pip install us
   pip install notebook

.. note::

   This step can also be done inside the PowerShell that you had previously opened. This is demonstrated in the video.

Test the Install of Python
^^^^^^^^^^^^^^^^^^^^^^^^^^

In powerwhell cd to the SimCenterBootcamp2020 folder and type the following.

.. code-block:: python

   cd code
   cd jupyter
   jupyter-notebook

This should open the browser running jupyter-notebook. Select any of the .ipynb files and it should open the notebook.


MacOS Computer
==============

The following video demonstrates these installation instructions on a brand new MacOS Catalina system.
Installation on MacOS Big Sur follows identical steps.

.. raw:: html

   <p><iframe width="560" height="315" src="https://www.youtube.com/embed/XzGqKSwnCTA" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe></p>


Fork the SimCenter Code Repository
----------------------------------

#. Go to `github <https.github.com>`_ and sign in or sign up.
#. Go to the `SimCenterBootcamp2020 <https://github.com/NHERI-SimCenter/SimCenterBootcamp2020>`_ repository.
#. In the very top right corner, where it has fork and a number beside it, click the fork button. This will create a fork of the Bootcamp repo in your own account. 

Install Git
-----------

There are a number of ways to install the source code management system `**git** <https://git-scm.com/download/mac>`_ on your computer. The simplest is to open a terminal application and type git. If the developer package has not already installed on your system, this wil ask you to install it. So say yes. When done test it using your **fork** of the github repo. To do this go to **YOUR** fork of the github repo, using the green pull down menu, gcopy the clone address. Open a terminal and in the terminal type

.. code-block:: python
   
   git clone https://github.com/YOUR-GIT-LOGIN/SimCenterBootcamp2020.git

.. warning::

   replace YOUR-GIT-LOGIN with your github login name

Install Python on a Mac
-----------------------

The Mac comes with Python pre-installed, which is currently the outdated version 2.7. As of January 1st, 2020 no new bug reports, fixes, or changes will be made to Python 2, and Python 2 is officially no longer supported. SimCenter tools require Python 3. We recommend installing Python 3.7 from `Python.org Mac Download <https://www.python.org/downloads/mac-osx>`_ using the 
**macOS 64-bit installer**. The installer will place a python3 executable in your /usr/local/bin directory, whose location should be on your system PATH. Version 3.8 does not appear to do so anymore, see the note below. 

.. note:: 
   #. We use the python.org installation over others, due to it's simplicity of install.
   #. In the current installation of **Python** it leaves two script files in a folder when the installation ends. You need to execute both script files to get Python set up correctly so that it can be invoked from the terminal. To execute the files, double click on them. The two files, shown in the image below, are: **Update Shell Profile.command.sh** and **Install CertificateCommand.sh**.

   .. figure:: figures/pythonInstallShell.png
      :align: center
      :figclass: align-center

      Python: Folder Displayed at Conclusion of Install

Once Python is installed, you need to extend it by installing a number of packages. To install these packages, start a terminal window and type the following:

.. code-block:: python

   pip3 install --user numpy
   pip3 install --user scipy
   pip3 install --user matplotlib
   pip3 install --user pandas 
   pip3 install --user openpyxl 
   pip3 install --user xlrd 
   pip3 install --user xlwt 
   pip3 install --user xlsxwriter
   pip3 install --user selenium 
   pip3 install --user bs4 
   pip3 install --user lxml 
   pip3 install --user requests 
   pip3 install --user geopandas 
   pip3 install --user census 
   pip3 install --user us
   pip3 install --user notebook

.. note:: 

   #. To start a terminal window you can use the spotlight app (magnifying glass at the top right corner of the desktop). Start the spotlight app and type in terminal. The terminal application should appear as the top hit. Click on it to start it.

   #. The --user option was required in my install dues to permisssions I gave myself as a user. If you use the user option, you will be required to edit your PATH env later.

   #. If you forget to invoke the **UpdateShellProfile.command.sh" script at the end of the install --user, you can always edit the correct shell file later to update the **PATH** variable to point to the python application.

   #. On Linux systems, the shell is the program that takes commands from the keyboard that you enter in the terminal window and passes them to the operating system to perform by invoking applications and passing data between applications. In the good old days, it was the only interface available to the user, i.e. there was no such thing as Finder! There are a number of shell programs that can be install --usered and made available to you. The most popular is the **bash** shell, the up and coming one is the **Z** shell. Power MacOS users will write shell scripts to do many many useful things. By default the applications that the shell program will invoke are limited to applications in a few specific directories that are defined in the users **PATH**. Users can modify this path by editing files that the shell program will read from everytime the program is started.

  When the frontend application is running the computations it is actually running a backend application using the shell program. As a consequence the shell program must be made aware of the locations of  some of the external applications that you have install --usered as **OpenSees** and **dakota** do not provide install --userers that automatically do this when they are install --usered. Other applications, like **Tcl** provide scripts that you invoke to do it. In short you have to edit the file appropriate to the shell you are using.

  To find which shell prgram you are using when you issue commands inside the terminal window, type the following in a terminal window:

  .. code:: none
   
	env | grep SHELL

  If the results is **/bin/bash** you will need to edit the **.bashrc** file or the **bash_profile** file. If the results is **/bin/zsh** you will need to edit the **.zshrc** or **.zprofile**. Typically the **.bash_profile** or the **.zprofile** file is the one to edit as these typically by design will invoke the **.bashrc** or **.zshrc** file. If in doubt, look for these files in your home directory and see which of these other installlers have modified.


Test the Install of Python
^^^^^^^^^^^^^^^^^^^^^^^^^^

In a terminal cd to the SimCenterBootcamp2020 folder and type the following.

.. code-block:: python

   cd code
   cd jupyter
   jupyter-notebook

This should open the browser running jupyter-notebook. Select any of the .ipynb files and it should open the notebook.

.. note::
   
   If it cannot find the jupyter-notebook application, you will need to edit your env PATH variable. This is done by editing the .bashrc or .zprofile file mentioned above. See the video for a demonstartion.


.. include:: install_issues.rst



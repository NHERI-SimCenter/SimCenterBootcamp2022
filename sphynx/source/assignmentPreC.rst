C: Assignment to Test Setup
===========================

.. warning::

   The TACC allocation for the bootcamp expired the first of the year. We are awaiting a request to TACC to activate the account for this year. In the meantime we have added you to an allocation we have on the TACC Stampede2 system. Changes to the instructions posted previously are minimal and only effect the **ssh** command.

.. note::

   The purpose of this exercise is to ensure that you are all ready to start programming at the start of the **C** part of the course. Because we will be spending time on parallel programming and showing how best to use **Tapis**, you will be using the `**Frontera** <https://www.tacc.utexas.edu/systems/frontera>`_ system and they provide a comprehinsive set of `usage notes <https://frontera-portal.tacc.utexas.edu/user-guide/>`_ . The following is a brief overview of it with Linux commands for this workshop.

   1. Using **git** on a daily basis to update the code base.
   2. Using **ssh** to login to Frontera from your terminal.
   3. Using **Linux** commands once logged in as Frontera is a Linux system.
   4. Compiling **C** code and running the compiled application on Frontera.
      
The following is a list of items you need to perform. For those of you who followed our **Python** course, steps **1** and **2** are not needed.

#. In your browser you need to sign up for `github <https://github.com>`_. If you have difficulties they have a `page devoted to signing up <https://docs.github.com/en/free-pro-team@latest/github/getting-started-with-github/signing-up-for-a-new-github-account>`_

#. After signing up and logging in, navigate in your browser to the SimCenterBottcamp2020 `git page <https://github.com/NHERI-SimCenter/SimCenterBootcamp2020>`_. At the website, click on the **Fork**, button at top right. This will create a fork of the repo under your own github username and take you to the main page for that repo.

#. Now under the **Code** pull down menu on this new page, copy the https address into your clipboard. 

#. Install and then pair the TACC Token app on your phone. Instructions can be found at the `TACC website <https://portal.tacc.utexas.edu/tutorials/multifactor-authentication>`_
   
#. Now we login to TACC. From Powershell terminal if on Windows10 or a terminal window if using MacOS, enter the following (replacing of course your DesignSafe account name with YOUR_NAME) and provide your designsafe login and the TACC token. For the TACC token open the TACC Token app you have installed on your phone.

   .. code::

      ssh YOUR_NAME@stampede2.tacc.utexas.edu

#. Now let us clone the repo that you just forked on github. To do so type the following:

   .. code::
      
      git clone https://github.com/YOUR GIT LOGIN/SimCenterBootcamp2020.git

#. This last command has created a new folder in your current directory named **SimCenterBootcamp2020**. We now want you to **cd** (change directory) into that directory. This is done by you typing the following:

   .. code::

      cd SimCenterBootcamp2020

#. Now we want you to issue the following command, which will add a pointer, called upstream, to the master SimCenterBootcamp2020 repo that you forked:

   .. code::
     
     git remote add upstream https://github.com/NHERI-SimCenter/SimCenterBootcamp2020.git

#. Now let us go back to your home folder. Here we will create a new folder named **hello** and get you to create your first **C** program in that folder.

   .. code::
     
     cd ~
     mkdir hello
     cd hello
     emacs hello.c

#. The last command you issues, **emacs** starts one of the few editors available to you on Frontera and opens up a file named **hello.c**. We now want you to place in that file the following:

   .. code::

      #include <stdio.h>
      int main(int argc, char **argv) {
         printf("Hello World\n");
      }

#. To save the file enter the following

   .. code::
	   
	   <Control> x <Control> s   

#. To quit emacs, enter now the following:

   .. code::

   	   <Control> x <Control> c   


#. Now we want you to compile the file to create an application called **a.out**. To do this type the following

   .. code::
      
      icc hello.c

#. To test the code and be responsible users while doing so, we want you to start an interactive session on a compute node. To do this type the following:

   .. code::
      
      idev

#. Once the session has started, you can run the application by typing the following:

   .. code::
      
      ./a.out

#. Application should run and output "Hello World" to the screen. You are done and have succesfully compiled and run your first **C** program. To now exit the interactive environment and also exit your sesssion at TACC type the following:

   .. code::
      
      exit
      exit

      
.. warning::
   #. Your TACC login name is the same as your DesignSafe login. If you do not have one yet, you need to obtain one from their `website <https://www.designsafe-ci.org/>`_.
   
   #. If you cannot log into Frontera, send us an email with your designsafe login as we have not added your login name to our allocation.
      
   #. If you have problems compiling the code, try and use the compiler messages to see what you did wrong.

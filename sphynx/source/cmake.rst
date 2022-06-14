.. _lblHelp:

*****
Cmake
*****


`CMake <http://www.cmake.org/>`_ is a cross-platform appliction for building applications. It is almost the default application required to build any open-source application and/or library on Linux based systems. It also comes included with many of the integrated development environments (IDE's) used for building C, C++ and Fotran applications on Windows, e.g. Visaul Studio and Intel Compiler Suite.

One of the first commands to use with cmake is to ask for help on the command line arguments. The useful thing about this command is that it will spit out the list of **Generators** available to you for your set-up. Generators are what is used to build the applications for specific target architectures, i.e. CPU's. Running cmake with the **help** option will show the default generator for your set-up, but you have the option of choosing any another with the **-G** option.

.. code-block:: console
		
		> cmake --help


The commands used when building an application utilizing cmake are pretty standard. The involve typing in a terminal window in the main directory of the applications source code the following:

.. code-block:: console
		
		> mkdir build
		> cd build
		> cmake ..
		> cmake --build . --config Release
		> cmake --install .


.. warning ::

    If running on a windows machine that you have installed the Intel oneAPI compiler suite on, you would issue the following from the terminal, or **cmd** application. The first line is a batch script provided with the intel installation that sets up the appropraite env variables needed by **cmake** and the applications it will invoke.

    .. code-block ::
   
                "C:\Program Files (x86)\Intel\oneAPI\setVars" intel64 mod
		mkdir build
		cd build
		cmake .. -G "Visual Studio 16 2019"
		cmake --build . --config Release
		cmake --install .


   
When run like this **cmake** will look for a **CMakeLists.txt** file in the source code directory. Below is a very basic **CmakeLists.txt** file that could be utilized for creating the **HelloWorld** application.

.. code-block::		

   cmake_minimum_required(VERSION 3.13)
   
   project(SimCenterHelloWorld
           VERSION 1.0
           LANGUAGES C)
   
   add_executable(HelloWorld hello.c)

The file starts with **cmake_minimum_required**,  which specifies the min version of cmake required to build the application, i.e. if yours is older it will not build. Next comes information on the project name, version and languages used in the source code files. Finally the line:

.. code-block::
   
   add_executable(HelloWorld hello.c)   
   
is what tells cmake the name of the application to build and the files to use. A more compilcated example is as shown below, in which multiple files are used to build the application. The files are compiled and seperatly linked when the **cmake --build .** command is entered.

.. code-block::
   
   cmake_minimum_required(VERSION 3.13)

   project(SimCenterExample
           VERSION 1.0
           LANGUAGES C)
   
   add_executable(exampleMath exampleMath.c math.c)

Finally a more complicated example still is as shown below. This example creates a library , that will be named mathLib. Now the exampleMath executable is created by linking to this library. 

.. code-block::

   cmake_minimum_required(VERSION 3.1...3.23)

   project(SimCenterExample
           VERSION 1.0
           LANGUAGES C)

   add_library(mathLib math.c)

   add_executable(exampleMath exampleMath.c)
   target_link_libraries(exampleMath PRIVATE mathLib)


.. note::

      It is somewhat common for the user to pass variables along with the cmake, e.g. the path to a user specific **C** compiler. For these cases the application is invoked with the **-D** option. For example if I had some c code to create an applicaton from and I wished to use a specific version of my C compiler in **/usr/local/gcc-8.2/bin/gcc**, I would issue the first **cmake** command with the following.

      ..code-block::

         > cmake -DCMAKE_CC_COMPILER=/usr/local/gcc-8.2/bin/gcc  ..


    It is usefulel to note why the first command and not the rest take the **-D** option. The first command will create a configuration file, **CMakeCache.txt** file in the top directory of the build tree. CMake uses this file to store the variables it uses for buidding the application, e.g. the name of the C compiler. Some of these variables were passed when the user provided the **-D** options. This is why subsequent invocations of the command do not need the **-D** options. However, it can also catch the unsuspecting user out who wishes to rerun the first cmake command again with the defaults. The user is required to remove the **CMakeCache.txt** file, or provide the defaults with the **--D** option if they want the defaults options.


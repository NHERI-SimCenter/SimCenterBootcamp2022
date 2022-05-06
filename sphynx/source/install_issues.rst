Known installation issues
=========================

Windows
-------

1. **Failure to install fiona package**

.. figure:: figures/installIssue1.png
   :align: center
   :figclass: align-center

   Reported installation error message

.. note::

   proposed solution (incomplete)
   --------

   It appears that the gdal package is the source of the problem. We recommend downloading the
   **gdal** and **fiona** packages closest to your system configuration from

   * gdal: https://www.lfd.uci.edu/~gohlke/pythonlibs/#gdal
   * fiona: https://www.lfd.uci.edu/~gohlke/pythonlibs/#fiona

   Install those packages using

   sudo pip install gdal*.whl fiona*.whl

2. **Runtime error when importing numpy (or matplotlib)**

   The following error was reported by several students who are running Windows 10 and a brand new
   installation of python::

	** On entry to DGEBAL parameter number  3 had an illegal value
	** On entry to DGEHRD  parameter number  2 had an illegal value
	** On entry to DORGHR DORGQR parameter number  2 had an illegal value
	** On entry to DHSEQR parameter number  4 had an illegal value
	Traceback (most recent call last):
	File "<string>", line 1, in <module>
	File "C:\Users\Song\AppData\Roaming\Python\Python39\site-packages\numpy\__init__.py", line 305, in <module>
	_win_os_check()
	File "C:\Users\Song\AppData\Roaming\Python\Python39\site-packages\numpy\__init__.py", line 302, in _win_os_check
	raise RuntimeError(msg.format(__file__)) from None
	RuntimeError: The current Numpy installation ('C:\\Users\\Song\\AppData\\Roaming\\Python\\Python39\\site-packages\\numpy\\__init__.py') fails to pass a sanity check due to a bug in the windows runtime. See this issue for more information: https://tinyurl.com/y3dm3h86



   This error is due to a bug in the latest version of ``numpy`` (1.19.4) on Windows 10.  
   It can be fixed by downgrading to ``numpy-1.19.3`` as follows::

   	pip uninstall numpy

   followed by::

   	pip install numpy==1.19.3

   


MacOS
------

1. "no CRS class" when import geopandas

.. note::
    Not a question, but knowledge-sharing: The issue of importing geopandas with the error of “no CRS class” in MacOS, the solution is to install the pyproj version 2.# since CRS is introduced version 2 in Pyproj. Do the following pip install pyproj==2.6.1


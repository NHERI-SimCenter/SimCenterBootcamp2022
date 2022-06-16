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

.. list-table:: Node class methods
   :widths: 25 25 25 50
   :header-rows: 1

   * - method
     - input
     - returns
     - description
   * - `__init__(x,y)`
     - coordinates of the point as two floats
     - n/a
     - constructor. Sets position and initializes displacement and force to zeros.
   * - `fixDOF(idx)`
     - `idx` of the degree of freedom (dof)
     - 
     - set internal flag for this dof accordingly.
   * - `isFixed(idx)`
     - `idx` of the degree of freedom (dof)
     - True|False
     - test function returning True if dof at `idx` is fixed, False otherwise.
   * - `setDisp(u,v)`
     - components of displacement
     - 
     - overwrited the displacements for this node.
   * - `getDisp()`
     - 
     - `np.array([u,v])`
     - returns displacement vector
   * - `getPos()`
     - 
     - `np.array([x,y])`
     - returns initial position
   * - `getDeformedPos(factor)`
     - 
     - `np.array([x+factor*u,y+factor*v])`
     - returns current position with displacement magnified by factor.  Would be good to have
       a default factor of 1.0 if none given.
   * - `addLoad(Px,Py)`
     - components of load
     - 
     - add this load to nodal load
   * - `setLoad(Px,Px)`
     - components of load
     - 
     - replace current load by provided load
   * - `getLoad()`
     - 
     - `np.array([Px,Py])`
     - returns current load


.. list-table:: Node class variables
   :widths: 25 25 50
   :header-rows: 1

   * - name
     - type
     - description
   * - `pos`
     - `np.array([x,y])`
     - holds `x` and `y` coordinates of the points
   * - `disp`
     - `np.array([u,v])`
     - holds `x` and `y` components of nodal displacement
   * - `fixity`
     - list of two `True|False`
     - `fixity[i]` is `True` if `i`-th degree of freedom is fixed, `False` otherwise.  Note:
       `i=0|1`
   * - `force`
     - `np.array([Px,Py])`
     - holds `x` and `y` components of the
       nodal load vector.


Element
^^^^^^^^^^^^^^^^^^^^
Each instance represents one truss member

.. list-table:: Element class methods
   :widths: 25 25 25 50
   :header-rows: 1

   * - method
     - input
     - returns
     - description
   * - `__init__(nd0, nd1, material)`
     - two `Node()` objects, one `Material()` object.
     - n/a
     - constructor.
   * - `getForce()`
     - 
     - list of (1d) np.array objects
     - A list of nodal forces.  Each nodal force shall be represented as a 1d np.array with
       two components of the force.
   * - `getStiffness()`
     - 
     - 2-by-2 list of 2-by-2 np.array
     - A list of lists (matrix) containing nodal tangent matrices as `np.array([[.,.],[.,.]])`

**Note**: a `Node()` object may have changed its state between calls, so you need to
recompute every time!


.. list-table:: Element class variables
   :widths: 25 25 50
   :header-rows: 1

   * - name
     - type
     - description
   * - `nodes`
     - List of `Node()` instances
     - representing the two nodes at either end of a truss.
   * - `material`
     - `Material()`
     - pointer to an instance of `Material()`. Needed to compute stress and tangent modulus.
   * - `force`
     - 2-list of (1d) np.array objects.
     - holding nodal forces `P0` and `P1`
   * - `Kt`
     - 2-by-2 array of 2-by-2 np.array objects.
     - tangent stiffness matrix. Representing all nodal stiffness matrices.

**Equations**

1. :math:`{\bf L} = {\bf X}_1 - {\bf X}_0`
#. :math:`\ell = ||{\bf L}||`
#. :math:`{\bf n} = \frac{1}{\ell} \, {\bf L}`
#. Strain: :math:`\varepsilon = {\bf n}\cdot( {\bf U}_1 - {\bf U}_0)`
#. Force: :math:`f = \sigma(\varepsilon) A` using `material.setStrain(eps)` and `material.getStress()`.
#. Nodal force vector: :math:`{\bf P}^e = f \, {\bf n}`
#. :math:`{\bf P}_0 = -{\bf P}^e ~~~~~~ {\bf P}_1 = {\bf P}^e`
#. Nodal stiffness matrix: :math:`{\bf k}^e = \frac{E_t(\varepsilon)\,A}{\ell}\, {\bf n}\otimes{\bf n}` using `material.getStiffness()` to find :math:`E_t`.
#. :math:`{\bf k}_{00} = {\bf k}_{11} = {\bf k}^e ~~~~~~~~ {\bf k}_{01} = {\bf k}_{10} = -{\bf k}^e`



Material
^^^^^^^^^^^^^^^^^^^^
**This class is provided as a demonstration example.**


.. list-table:: Material class methods
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

.. list-table:: Element class variables
   :widths: 25 25 50
   :header-rows: 1

   * - name
     - type
     - description
   * - `params`
     - dict
     - default parameters: `{'E':100., 'nu':0.0,  'fy:1.0e30}`
       Holds user provided parameters (MOE, Poisson's ratio, yield stress)
   * - `plastic_strain`
     - float
     - internal state variable.
   * - `sig`
     - float
     - holds current stress
   * - `Et`
     - float
     - holds current materil tangent modulus


System
^^^^^^^^^^^^^^^^^^^^
Creates an instance of a truss model

.. list-table:: System class methods
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
   * - `addNode(newNode)`
     - `Node(...)` object
     - 
     - add one `Node()` object to your list of elements (the model)
   * - `addElement(newElem)`
     - `Element(...)` object
     - 
     - add one `Element()` object to your list of elements (the model)
   * - `solve()`
     - 
     - 
     - assemble :math:`[K_t]` and :math:`\{P\}`, solve for :math:`\{u\} = [K_t]^{-1}\{P\}`,
       loop through nodes and update nodal displacement, compute unbalanced force :math:`\{R\}
       = \{P\} - \{F\}`
   * - `plot(factor=1.0)`
     - 
     - 
     - collect node info and send it to the plotter. Request the plot.
   * - `report()`
     - 
     - 
     - print a summary report: list of nodal position, load, displacement, unbalanced force.


.. list-table:: System class variables
   :widths: 25 25 50
   :header-rows: 1

   * - name
     - type
     - description
   * - `nodes`
     - List of `Node()` objects
     - holds all the nodes in the model
   * - `elements`
     - List of `Element()` objects
     - holds all the elements in the model
   * - `plotter`
     - `Plotter()`
     - pointer to `Plotter()` object to handle plotting
   * - `disp`
     - `np.array([...])`
     - system sized displacement vector
   * - `loads`
     - `np.array([...])`
     - system sized load vector


Plotter
^^^^^^^^^^^^^^^^^^^^
Creates undeformed and deformed plots of the system.


.. list-table:: Plotter class methods
   :widths: 25 25 25 50
   :header-rows: 1

   * - method
     - input
     - returns
     - description
   * - `__init__()`
     - 
     - n/a
     - constructor. Initialize the plotter object to sensible default settings, as needed.
   * - `setMesh(verts,lines)`
     - list of points, list of line indices
     - 
     - replace `self.vertices` and `self.lines` information.
   * - `setDisplacements(disp)`
     - list of displacement vectors
     - 
     - replace `self.disp` information.
   * - `setValues(vals)`
     - list of line (force) values.
     - 
     - replace `self.values` information.
   * - `displacementPlot(file=None)`
     - a string
     - 
     - creates a plot showing undeformed in black and deformed model in red lines. 
       If `file` is given, save a copy of the plot to a file
       of that name
   * - `valuePlot(deformed=False, file=None)`
     - a string
     - 
     - creates a plot showing the undeformed|deformed system (based on the user input) with
       lines colored based on `values`. Add a colormap/colorbar as legend.
       If `file` is given, save a copy of the plot to a file
       of that name

.. list-table:: Plotter class variables
   :widths: 25 25 50
   :header-rows: 1

   * - name
     - type
     - description
   * - `vertices`
     - List of `np.array([X,Y])`
     - list of coordinate pairs representing points (nodes in the model)
   * - `lines`
     - List of List
     - list of 2-element lists of indices.  The two lists shall contain the indices of the
       start and end point of a line in the `vertices list`, respectively.  
   * - `disp`
     - list of `np.array([u,v])`
     - list of point displacements for deformed plot.  This list must be of identical shape
       as the `vertices` list such that respective entries represent point position and
       displacement, respectively.
   * - `values`
     - `np.array([...])`
     - list containing the force values for each line (element).  This list must be of
       identical shape as the `lines` list.



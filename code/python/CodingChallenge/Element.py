import numpy as np
from Node import *
from Material import *

class Element():
    """
    class: representing a single element
    """

    def __init__(self, node0, node1, material):
        self.nodes    = [node0, node1]
        self.material = material
        self.force    = 0.0
        self.Forces   = [ np.zeros(2), np.zeros(2) ]
        self.Kt       = [ [np.zeros((2,2)), np.zeros((2,2))], [np.zeros((2,2)), np.zeros((2,2))] ]

    def __str__(self):
        s = \
"""Element: node {} to node {}:
   material properties: {}  strain:{}   stress:{}  
   internal force: {}
   Pe: [ {} {} ]""".format( self.nodes[0].index, self.nodes[1].index,
                           repr(self.material), self.material.getStrain(), self.material.getStress(),
                           self.force, *self.Forces[1] )
        return s

    def __repr__(self):
        return "Element({},{},{})".format(repr(self.nodes[0]),
                                          repr(self.nodes[1]),
                                          repr(self.material))

    def getAxialForce(self):
        self.updateState()
        return self.force

    def getForce(self):
        self.updateState()
        return self.Forces

    def getStiffness(self):
        self.updateState()
        return self.Kt

    def updateState(self):
        X0 = self.nodes[0].getPos()
        U0 = self.nodes[0].getDisp()
        X1 = self.nodes[1].getPos()
        U1 = self.nodes[1].getDisp()

        Lvec = X1 - X0
        ell = np.linalg.norm(Lvec)
        Nvec = Lvec / ell

        eps = Nvec @ (U1 - U0) / ell
        self.material.setStrain(eps)
        stress = self.material.getStress()
        area   = self.material.getArea()
        self.force = stress * area

        Pe = self.force * Nvec
        self.Forces = [-Pe, Pe]

        Et = self.material.getStiffness()
        ke = (Et * area / ell) * np.outer(Nvec, Nvec)
        self.Kt = [[ke,-ke],[-ke,ke]]


if __name__ == "__main__":
    # testing the Element class
    nd0 = Node(0.0, 0.0)
    nd0.index = 0
    nd1 = Node(3.0, 2.0)
    nd1.index = 1
    params = {'E':100, 'A':1.5, 'fy':1.0e20}
    elem = Element(nd0, nd1, Material(params))

    print(nd0)
    print(nd1)

    print("force =", elem.getAxialForce())
    print("nodal forces: ", *elem.getForce())
    print("element stiffness: ", elem.getStiffness())

    # change the nodal displacements
    nd0.setDisp(.1, .05)
    nd1.setDisp(.05, .2)

    print(nd0)
    print(nd1)

    print("force =", elem.getAxialForce())
    print("nodal forces: ", *elem.getForce())
    print("element stiffness: ", elem.getStiffness())



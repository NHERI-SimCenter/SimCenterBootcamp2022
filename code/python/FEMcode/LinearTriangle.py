from Element import *

class LinearTriangle(Element):
    """
    class: representing a single truss element
    """

    def __init__(self, node0, node1, node2, material):
        self.nodes    = [node0, node1, node2]
        self.material = material
        self.force    = 0.0
        self.Forces   = [ np.zeros(2), np.zeros(2) , np.zeros(2) ]
        self.Kt       = [ [np.zeros((2,2)), np.zeros((2,2)), np.zeros((2,2))],
                          [np.zeros((2,2)), np.zeros((2,2)), np.zeros((2,2))],
                          [np.zeros((2,2)), np.zeros((2,2)), np.zeros((2,2))] ]

    def __str__(self):
        s = \
"""Truss: node {} to node {}:
   material properties: {}  strain:{}   stress:{}  
   internal force: {}
   Pe: [ {} {} ]""".format( self.nodes[0].index, self.nodes[1].index,
                            repr(self.material), self.material.getStrain(),
                            self.material.getStress(),
                            self.force, *self.Forces[1] )
        return s

    def __repr__(self):
        return "Truss({},{},{})".format( repr(self.nodes[0]),
                                         repr(self.nodes[1]),
                                         repr(self.material))

    def updateState(self):
        X0 = self.nodes[0].getPos()
        U0 = self.nodes[0].getDisp()
        X1 = self.nodes[1].getPos()
        U1 = self.nodes[1].getDisp()
        X2 = self.nodes[1].getPos()
        U2 = self.nodes[1].getDisp()

        G1 = X1 - X0
        G2 = X2 - X0

        area = np.linalg.norm(np.cross(G1, G2)) / 2.

        g1 = G1 + U1 - U0
        g2 = G2 + U2 - U0

        DPhi0 = np.column_stack(G1,G2)
        DPhi  = np.column_stack(g1,g2)

        F = DPhi @ DPhi0.I

        eps = 0.5 * ( F.T @ F - np.eye(2) )

        strain = {'xx':eps[0,0], 'yy':eps[1,1], 'xy':eps[0,1]+eps[1,0]}

        self.material.setStrain(strain)
        self.force = self.material.getStress()

        Pe = self.force * area
        self.Forces = [-Pe, Pe]

        Et = self.material.getStiffness()
        ke = (Et * area / ell) * np.outer(Nvec, Nvec)
        self.Kt = [[ke,-ke],[-ke,ke]]

    def getStress(self):
        return None


if __name__ == "__main__":
    # testing the Element class
    nd0 = Node(0.0, 0.0)
    nd0.index = 0
    nd1 = Node(3.0, 2.0)
    nd1.index = 1
    nd2 = Node(2.0, 4.0)
    nd2.index = 2
    params = {'E':100, 'A':1.5, 'fy':1.0e20}
    elem = LinearTriangle(nd0, nd1, nd2, Material(params))

    print(nd0)
    print(nd1)
    print(nd2)

    print("stress =", elem.getStress())
    print("nodal forces: ", *elem.getForce())
    print("element stiffness: ", elem.getStiffness())

    # change the nodal displacements
    nd0.setDisp(.1, .05)
    nd1.setDisp(.05, .2)
    nd2.setDisp(-.05, .1)

    print(nd0)
    print(nd1)
    print(nd2)

    print("force =", elem.getAxialForce())
    print("nodal forces: ", *elem.getForce())
    print("element stiffness: ", elem.getStiffness())



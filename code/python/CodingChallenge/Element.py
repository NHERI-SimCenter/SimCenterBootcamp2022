import numpy as np

class Element():
    """
    class: representing a single element
    """

    def __init__(self, node0, node1, material):
        self.nodes    = [node0, node1]
        self.material = material
        self.force    = [ np.zeros(2), np.zeros(2) ]
        self.Kt       = [ [np.zeros((2,2)), np.zeros((2,2))], [np.zeros((2,2)), np.zeros((2,2))] ]

    def __str__(self):
        return "Element({},{},{})".format(repr(self.nodes[0]),
                                          repr(self.nodes[1]),
                                          repr(self.material))

    def __repr__(self):
        return "Element({},{},{})".format(repr(self.nodes[0]),
                                          repr(self.nodes[1]),
                                          repr(self.material))

    def getForce(self):
        self.updateState()
        return self.force

    def getStiffness(self):
        self.updateState()
        return self.Kt

    def updateState(self):
        X0 = self.nodes[0].getPos()
        U0 = self.nodes[0].getDisp()
        X1 = self.nodes[1].getPos()
        U1 = self.nodes[1].getDisp()

        Lvec = X1 - X0
        len = np.norm(Lvec)
        Nvec = Lvec / len

        eps = Nvec @ (U1 - U0) / ell

if __name__ == "__main__":
    # testing the Element class
    elem = Element()


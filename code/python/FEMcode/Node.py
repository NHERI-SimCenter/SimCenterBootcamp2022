import numpy as np


class Node():
    """
    class: representing a single Node
    """

    def __init__(self, x ,y, u=0, v=0):
        self.pos      = np.array([x,y])
        self.index    = -1
        self.disp     = np.array([u,v])
        self.fixity   = [False, False]
        self.force    = np.zeros(2)
        self._hasLoad = False

    def __str__(self):
        s = \
"""Node {}:
   x:{}   y:{}
   fix:{} fix:{}
   Px:{}  Py:{}
   u:{}   v:{}""".format( self.index,
                           self.pos[0],   self.pos[1],
                           *self.fixity,
                           self.force[0], self.force[1],
                           self.disp[0],  self.disp[1])
        return s

    def __repr__(self):
        return "Node({},{},u={},v={})".format(self.pos[0],self.pos[1],self.disp[0],self.disp[1])

    def fixDOF(self, idx):
        self.fixity[idx] = True

    def isFixed(self, idx):
        return self.fixity[idx]

    def setDisp(self, u, v):
        self.disp = np.array([u,v])

    def getDisp(self):
        return self.disp

    def getPos(self):
        return self.pos

    def getDeformedPos(self, factor=1.0):
        return self.pos + factor * self.disp

    def addLoad(self, Px, Py):
        self.force   += np.array([Px, Py])
        self._hasLoad = True

    def setLoad(self, Px, Py):
        self.force    = np.array([Px, Py])
        self._hasLoad = True

    def getLoad(self):
        return self.force

    def hasLoad(self):
        return self._hasLoad


if __name__ == "__main__":
    # testing the Node class
    node = Node(2.0, 3.5)
    node.index = 42
    node.setLoad(1.2, 3.4)
    node.addLoad(5.6, 7.8)
    node.setDisp(0.1234, -4.321)
    node.fixDOF(1)   # fixes y-direction

    print(repr(node))
    print(node)

import numpy as np

from Node import *
from Element import *
from Plotter import *


class System():
    """
    class: representing a System model
    """

    def __init__(self):
        self.nodes    = []
        self.elements = []
        self.plotter  = Plotter()
        self.disp     = np.array([])
        self.loads    = np.zeros_like(self.disp)

    def __str__(self):
        s = "System object"
        for node in self.nodes:
            s += "\n" + repr(node)
        for elem in self.elements:
            s += "\n" + repr(elem)
        return s

    def __repr__(self):
        return "System()"

    def addNode(self, newNode):
        newNode.index = len(self.nodes)
        self.nodes.append(newNode)

    def addElement(self, newElement):
        self.elements.append(newElement)

    def solve(self):
        # compute size parameters
        ndof = 2*len(self.nodes)
        Rsys = np.zeros(ndof)
        Ksys = np.zeros((ndof, ndof))

        # assemble loads
        for (i, node) in enumerate(self.nodes):
            if node.hasLoad():
                gidx = np.array([2*i, 2*i+1])
                Rsys[gidx] += node.getLoad()

        # assemble element forces and stiffness
        for elem in self.elements:
            # indexing
            (nd0, nd1) = elem.nodes
            K = np.array([2*nd0.index,2*nd0.index+1], dtype=int)
            M = np.array([2*nd1.index,2*nd1.index+1], dtype=int)

            # add element force
            Fe = elem.getForce()
            Rsys[K] -= Fe[0]
            Rsys[M] -= Fe[1]

            # add element stiffness
            Ke = elem.getStiffness()
            Ksys[K[:,np.newaxis],K] += Ke[0][0]
            Ksys[K[:,np.newaxis],M] += Ke[0][1]
            Ksys[M[:,np.newaxis],K] += Ke[1][0]
            Ksys[M[:,np.newaxis],M] += Ke[1][1]

        # apply boundary conditions
        for (i, node) in enumerate(self.nodes):
            for idx in [0,1]:
                if node.isFixed(idx):
                    K = 2*node.index + idx
                    Rsys[K] = 0.0
                    # using the "more correct version" of applying BCs to Ksys
                    Ksys[:,K] = np.zeros(ndof)
                    Ksys[K,:] = np.zeros(ndof)
                    Ksys[K,K] = 1.0

        # stability check for system matrix
        (vals, vecs) = np.linalg.eig(Ksys)
        for (lam, v) in zip(vals, vecs.T):
            if np.abs(lam) < 1.0e-2:
                print(f"lambda = {lam:16.12e}")
                print(v)
        # solve for displacements
        U = np.linalg.solve(Ksys, Rsys)

        # update nodal displacements
        for (i, node) in enumerate(self.nodes):
            gidx = np.array([2*i, 2*i+1])
            node.setDisp(*U[gidx])

        # recompute residual force
        Rsys = np.zeros(ndof)
        for elem in self.elements:
            # indexing
            (nd0, nd1) = elem.nodes
            K = np.array([2*nd0.index,2*nd0.index+1])
            M = np.array([2*nd1.index,2*nd1.index+1])

            # add element force
            Fe = elem.getForce()
            Rsys[K] -= Fe[0]
            Rsys[M] -= Fe[1]

        self.Rsys = Rsys
        self.disp = U

    def plot(self, factor=1.0):

        vertices = [ node.getPos() for node in self.nodes ]
        lines    = [ [ elem.nodes[k].index for k in [0,1] ] for elem in self.elements ]
        self.plotter.setMesh(vertices, lines)

        ndof = len(self.Rsys)
        R = self.Rsys.copy().reshape((ndof//2, 2))
        self.plotter.setReactions(R)

        disp = [ factor * node.getDisp() for node in self.nodes ]
        self.plotter.setDisplacements(disp)
        self.plotter.displacementPlot()

        values = [ elem.getAxialForce() for elem in self.elements ]
        self.plotter.setValues(values)
        self.plotter.valuePlot()

    def report(self):
        s  = "\nTruss Analysis Report\n"
        s += "=====================\n"
        s += "\nNodes:\n"
        s += "---------------------\n"
        for node in self.nodes:
            for ln in str(node).split('\n'):
                s += "  " + ln + "\n"
        s += "\nElements:\n"
        s += "---------------------\n"
        for elem in self.elements:
            for ln in str(elem).split('\n'):
                s += "  " + ln + "\n"
        print(s)


if __name__ == "__main__":
    # testing the System class
    B = 6.0*12
    H = 8.0*12
    params = {'E':1000000., 'A':10., 'nu':0.0, 'fy':1.e30}

    model = System()

    nd0 = Node(0.0, 0.0)
    nd1 = Node(  B, 0.0)
    nd2 = Node(2*B, 0.0)
    nd3 = Node(3*B, 0.0)
    nd4 = Node(4*B, 0.0)
    nd5 = Node(0.5*B, H)
    nd6 = Node(1.5*B, H)
    nd7 = Node(2.5*B, H)
    nd8 = Node(3.5*B, H)

    model.addNode(nd0)
    model.addNode(nd1)
    model.addNode(nd2)
    model.addNode(nd3)
    model.addNode(nd4)
    model.addNode(nd5)
    model.addNode(nd6)
    model.addNode(nd7)
    model.addNode(nd8)

    model.addElement(Element(nd0, nd1, Material(params)))  # bottom 1
    model.addElement(Element(nd1, nd2, Material(params)))  # bottom 2
    model.addElement(Element(nd2, nd3, Material(params)))  # bottom 3
    model.addElement(Element(nd3, nd4, Material(params)))  # bottom 4

    model.addElement(Element(nd5, nd6, Material(params)))  # upper 1
    model.addElement(Element(nd6, nd7, Material(params)))  # upper 2
    model.addElement(Element(nd7, nd8, Material(params)))  # upper 3

    model.addElement(Element(nd0, nd5, Material(params)))  # up right diag 1
    model.addElement(Element(nd1, nd6, Material(params)))  # up right diag 2
    model.addElement(Element(nd2, nd7, Material(params)))  # up right diag 3
    model.addElement(Element(nd3, nd8, Material(params)))  # up right diag 4

    model.addElement(Element(nd1, nd5, Material(params)))  # up left diag 1
    model.addElement(Element(nd2, nd6, Material(params)))  # up left diag 2
    model.addElement(Element(nd3, nd7, Material(params)))  # up left diag 3
    model.addElement(Element(nd4, nd8, Material(params)))  # up left diag 4

    # boundary conditions
    nd0.fixDOF(0)
    nd0.fixDOF(1)
    nd4.fixDOF(1)

    # load upper nodes
    nd5.setLoad(0.0, -1.0)
    nd6.setLoad(0.0, -1.0)
    nd7.setLoad(0.0, -1.0)

    # solve the system
    model.solve()

    print(model)

    # write out report
    model.report()


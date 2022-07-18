import numpy as np


class system:

    def __init__(self):
        self.nodes = []
        self.elements = []
        self.GSM = []

    def addNodes(self,node):
        self.nodes.append(node)
        nl = len(self.nodes)
        self.GSM = np.zeros([2*nl, 2*nl])

    def getGSMSize(self):
        return self.GSM.size

    def getNodes(self):
        return self.nodes

    def assembleGSM(self):
        for element in elements:
            nodeI = node.getID(element.ndi)
            nodeJ = node.getID(element.ndj)
            nodeI_DOFX = nodeI*2-1
            nodeI_DOFY = nodeI*2
            nodeJ_DOFX = nodeJ*2-1
            nodeJ_DOFY = nodeJ*2
            #self.GSM[nodeI_DOFX,nodeI_DOFX] +=
        ## Already forgot how to assemble GSM in an automatic way 
        ## Need to refresh things up

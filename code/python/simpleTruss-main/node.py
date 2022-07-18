import numpy as np

class Node(object):
    def __init__(self, params={'id':1, 'x':0.0, 'y':0.0}):
        self.params = params
        if 'x' not in self.params:
            self.params['x']  = 0.0
        if 'y' not in self.params:
            self.params['y'] = 0.0

        self.id = self.params['id']
        self.pos = np.array([params['x'],params['y']])
        self.disp = np.array([0.0, 0.0])
        self.force = np.array([0.0, 0.0])
        self.fixity = [False,False]

    def __str__(self):
        s = "Node({})".format(self.id)
        return s

    def __repr__(self):
        return str(self)

    def getNode(self):
        return self.id
    def fixdof(self,dof):
        self.fixity[dof] = True

    def isfixed(self,dof):
        return self.fixity[dof]

    def setdisp(self,u,v):
        self.disp = np.array([u,v])

    def getdisp(self):
        return self.disp

    def getpos(self):
        return self.pos

    def getdeformedpos(self,factor):
        return (self.pos + self.disp * factor)

    def addLoad(self,Px,Py):
        self.force += np.array([Px,Py])

    def setLoad(self,Px,Py):
        self.force = np.array([Px,Py])

    def getLoad(self):
        return self.force

if __name__ == "__main__":
    # testing the Node class
    Nodal = Node(params={'x':25.0, 'y':10})

    Nodal.pos
    Nodal.disp
    Nodal.force

    Nodal.addLoad(200,300)
    print(Nodal.getLoad())
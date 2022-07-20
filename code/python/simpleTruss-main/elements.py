import numpy as np
import math
class element:
    def __init__(self,i,j,material):
        self.ndi = i
        self.ndj = j
        self.nodes = [self.ndi, self.ndj]

        self.material = material
        self.force = [np.array([0., 0.]),np.array([0., 0.])]
        self.Kt = np.zeros([2,2])

        xi,yi = self.ndi.pos
        xj,yj = self.ndj.pos
        self.length = math.sqrt((xj-xi)**2 + (yj-yi)**2)
        self.assembleStifness()

    def __str__(self):
        s = "Element with ({})".format(self.nodes)
        return s

    def __repr__(self):
        return str(self)

    def getCoordinates(self):
        return [self.ndi.getpos(), self.ndj.getpos()]

    def getStiffness(self):
        return self.Kt

    def getLength(self):
        return self.length

    def assembleStifness(self):
        E = 200000 # 200 MPa
        A = 100 # 100 mm^2
        xi,yi = self.ndi.pos
        xj,yj = self.ndj.pos
        c = (xj-xi)/self.length
        s = (yj-yi)/self.length
        self.Kt = (E*A)/self.length * np.array([[c*c, c*s, -c*c, -c*s], [c*s, s*s, -c*s, -s*s ], [-c*c, -c*s, c*c, c*s],[-c*s, -s*s, c*s, s*s]])

    def getForce(self):
        return  self.force


import numpy as np
import matplotlib.pyplot as plt
from matplotlib.collections import LineCollection
from matplotlib.colors import ListedColormap, BoundaryNorm


class Plotter():
    """
    class: representing a Plotter object
    """

    def __init__(self):
        self.vertices  = []
        self.lines     = []
        self.disp      = []
        self.values    = []
        self.reactions = []

    def __str__(self):
        return "Plotter() object"

    def __repr__(self):
        return str(self)

    def setMesh(self, vert, lines):
        self.vertices = np.array(vert)
        self.lines    = np.array(lines)

    def setDisplacements(self, disp):
        self.disp = np.array(disp)

    def setValues(self, vals):
        self.values = np.array(vals)

    def setReactions(self, R):
        self.reactions = np.array(R)

    def displacementPlot(self, file=None):
        fig, axs = plt.subplots()

        # plot the undeformed lines
        for line in self.lines:
            vert0 = self.vertices[line[0]]
            vert1 = self.vertices[line[1]]
            x = [vert0[0], vert1[0]]
            y = [vert0[1], vert1[1]]
            axs.plot(x,y,'-k',lw=2)

        # plot the deformed lines
        if len(self.disp) == len(self.vertices):
            for line in self.lines:
                vert0 = self.vertices[line[0]].copy()
                vert1 = self.vertices[line[1]].copy()
                vert0 += self.disp[line[0]]
                vert1 += self.disp[line[1]]
                x = [vert0[0], vert1[0]]
                y = [vert0[1], vert1[1]]
                axs.plot(x,y,'-r',lw=3)

        if self.reactions != []:
            self.addForces(axs)

        axs.set_aspect('equal')
        axs.set_axis_off()

        plt.show()

    def valuePlot(self, deformed=False, file=None):
        fig, axs = plt.subplots()

        # plot the lines
        segments = []

        if len(self.disp) == len(self.vertices):
            for line in self.lines:
                vert0 = self.vertices[line[0]].copy()  # we need a copy since we will be modifying this in the lines below
                vert1 = self.vertices[line[1]].copy()  # we need a copy since we will be modifying this in the lines below
                if deformed:
                    vert0 += self.disp[line[0]]   # it's this += that modifies the vertices if we don't use a copy
                    vert1 += self.disp[line[1]]   # it's this += that modifies the vertices if we don't use a copy
                #x = [vert0[0], vert1[0]]
                #y = [vert0[1], vert1[1]]
                #axis.plot(x,y,'-r',lw=3)
                segments.append(np.array([vert0, vert1]))

        # Create a continuous norm to map from data points to colors
        lc = LineCollection(np.array(segments), cmap='rainbow')
        # Set the values used for colormapping
        lc.set_array(self.values)
        lc.set_linewidth(3)
        line = axs.add_collection(lc)
        fig.colorbar(line, ax=axs)

        if self.reactions != []:
            self.addForces(axs)

        axs.set_aspect('equal')
        axs.set_axis_off()

        plt.autoscale(enable=True, axis='x', tight=False)
        plt.autoscale(enable=True, axis='y', tight=False)
        plt.show()

    def addForces(self, axs):
        if len(self.reactions) == len(self.vertices):
            Fx = []
            Fy = []
            X = []
            Y = []
            for (point, force) in zip(self.vertices, self.reactions):
                if np.linalg.norm(force) > 1.0e-3:
                    X.append(point[0])
                    Y.append(point[1])
                    Fx.append(-force[0])
                    Fy.append(-force[1])

            axs.quiver(X,Y, Fx, Fy, color='green')




if __name__ == "__main__":
    # testing the plotter
    plotter = Plotter()

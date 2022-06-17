import matplotlib.pyplot as plt
import numpy as np


class Plotter():
    """
    class: representing a Plotter object
    """

    def __init__(self):
        pass

    def __str__(self):
        s = "Plotter()"
        return s

    def __repr__(self):
        return str(self)

    def setMesh(self, vert, lines):
        self.vertices = vert
        self.lines = lines

    def setDisplacements(self, disp):
        self.disp = disp

    def setValues(self, vals):
        self.values = vals

    def displacementPlot(self, file=None):
        pass

    def valuePlot(self, deformed=False, file=None):
        pass


if __name__ == "__main__":
    # testing the plotter
    plotter = Plotter()

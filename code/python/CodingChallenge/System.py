import numpy as np

from Node import *
from Element import *


class System():
    """
    class: representing a System model
    """

    def __init__(self):
        pass

    def __str__(self):
        s = "System()"
        return s

    def __repr__(self):
        return str(self)


if __name__ == "__main__":
    # testing the System class
    model = System()

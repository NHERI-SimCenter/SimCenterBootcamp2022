'''
file: point.py

author: Peter Mackenzie-Helnwein, University of Washington, Seattle, WA
created: 07-28-2020
'''

# all import statements go here
import numpy as np

# class definition
class Point(object):
    '''
    class: Point

    variables:
        self.position  ... the point's position stored as a numpay.array for easy computations

    methods:
        def __init__(self, coords=[0.0,0.0]):
        def __str__(self):
        def __repr__(self):
        def __add__(self,p):
        def __sub__(self,p):
    '''

    def __init__(self, coords=[0.0,0.0]):
        self.position = np.array(coords)

    def __str__(self):
        return str(self.position.tolist())

    def __repr__(self):
        return "Point({})".format(self.position.tolist())

    def __add__(self,p):
        pass

    def __sub__(self,p):
        pass

    # more fun methods you could use with a Point object


# your demo code here
def demo():
    print('creating a point object')
    a = Point([2.,4.])
    print(a)
    print(repr(a))

    # more creative demo and testing
    # ...

# run demo if run directly
if __name__ == '__main__':
    demo()

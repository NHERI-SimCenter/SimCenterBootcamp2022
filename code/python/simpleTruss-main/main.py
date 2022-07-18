
# Press the green button in the gutter to run the script.
if __name__ == '__main__':

    from node import *
    from elements import *
    from system import *

    model = system()
    NodeI = Node(params={'id':1,'x':0.0, 'y':0.0})
    NodeJ = Node(params={'id':2,'x':1000.0, 'y':0.0})
    NodeK = Node(params={'id':3,'x':1000.0, 'y':5000.0})

    model.addNodes(NodeI)
    model.addNodes(NodeJ)
    model.addNodes(NodeK)

    elementA = element(NodeI, NodeJ, "Material")
    elementB = element(NodeJ, NodeK, "Material")

    print(elementA.getCoordinates())
    print(elementA.getStiffness())
    print(elementA.getForce())
    print(elementB.getStiffness())


    print(model.getGSMSize())
    print(model.getNodes())
    print(elementA.getLength())

import numpy as np
import matplotlib.pyplot as plt


class Material():
    """
    class: representing a generic material

    """

    def __init__(self, params={'E':1.0, 'A':1.0, 'nu':0.0, 'fy':1.0e30}):
        self.parameters = params

        # make sure all necessary parameters exist
        if 'E' not in self.parameters:
            self.parameters['E']  = 1.0
        if 'A' not in self.parameters:
            self.parameters['A']  = 1.0
        if 'nu' not in self.parameters:
            self.parameters['nu'] = 0.0
        if 'fy' not in self.parameters:
            self.parameters['fy'] = 1.0e30

        self.sig = 0.0
        self.Et  = self.parameters['E']

    def __str__(self):
        s = "{}(Material)({})".format(self.__class__.__name__, self.parameters)
        return s

    def __repr__(self):
        return str(self)

    def getStress(self):
        """
        request axial stress

        :return: sigma
        """
        return self.sig

    def getStiffness(self):
        """
        request axial stiffness

        :return: Et ... tangent material stiffness
        """
        return self.Et

    def setStrain(self, eps):
        """
        update state for a user provided axial strain value

        :param eps:  strain or strain tensor
        :return: n/a
        """
        # update stress state
        E  = self.parameters['E']
        fy = self.parameters['fy']

        # default 1d elasticity
        self.sig = E * eps
        self.Et = E

    def getStrain(self):
        return self.sig / self.parameters['E']


if __name__ == "__main__":
    # testing the Node class
    mat = Material(params={'E':100.0, 'nu':0.0, 'fy':1.0})

    eps = 0.02 * np.sin( np.linspace(0, 2.*np.pi, 100) )

    sig = []
    Et = []
    for strain in eps:
        # update material strain state
        mat.setStrain(strain)
        #collect stress response
        sig.append(mat.getStress())
        #collect material tangent stiffness response
        Et.append(mat.getStiffness())

    fig, (ax1,ax2) = plt.subplots(2,1)

    ax1.plot(eps, sig, '-r', label='stress')
    ax1.grid(True)
    ax1.set_xlabel('strain $\\varepsilon$')
    ax1.set_ylabel('stress $\sigma$')
    ax1.legend()

    ax2.plot(eps, Et, '-.b', label='tangent modulus')
    ax2.grid(True)
    ax2.set_xlabel('strain $\\varepsilon$')
    ax2.set_ylabel('tangent modulus $E_t$')
    ax2.legend()

    plt.show()

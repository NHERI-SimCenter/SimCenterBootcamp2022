import numpy as np
import matplotlib.pyplot as plt


class Material():
    """
    class: representing a generic material
    """

    def __init__(self, params={'E':1.0, 'nu':0.0, 'fy':1.0e30}):
        self.parameters = params

        # make sure all necessary parameters exist
        if 'E' not in self.parameters:
            self.parameters['E']  = 1.0
        if 'nu' not in self.parameters:
            self.parameters['nu'] = 0.0
        if 'fy' not in self.parameters:
            self.parameters['fy'] = 1.0e30

        # initialize strain
        self.plastic_strain = 0.0
        self.setStrain(0.0)

    def __str__(self):
        s = "Material({})".format(self.parameters)
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

        # elastic predictor
        self.sig = E * (eps - self.plastic_strain)
        self.Et = E

        # check yield condition
        f = np.abs(self.sig) - fy

        # plastic corrector as needed
        if f >= 0.0:
            depsP = np.sign(self.sig) * f/E
            self.sig -= E * depsP
            self.plastic_strain += depsP
            self.Et = 0.0

        print(4*'{:12.8e}  '.format(eps, f, self.plastic_strain, self.sig ))

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
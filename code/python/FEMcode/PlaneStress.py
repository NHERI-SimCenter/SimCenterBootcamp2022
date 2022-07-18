import matplotlib.pyplot as plt

from Material import *


class PlaneStress(Material):
    """
    class: representing a 2d Plane Stress Material

    """

    def __init__(self, params={'E':1.0, 't':1.0, 'nu':0.0, 'fy':1.0e30}):
        super().__init__(params = params)

        # make sure all necessary parameters exist
        if 'E' not in self.parameters:
            self.parameters['E']  = 1.0
        if 'A' not in self.parameters:
            self.parameters['t']  = 1.0
        if 'nu' not in self.parameters:
            self.parameters['nu'] = 0.0
        if 'fy' not in self.parameters:
            self.parameters['fy'] = 1.0e30

        # initialize strain
        self.plastic_strain = np.zeros(3)
        self.setStrain({'xx':0.0, 'yy':0.0, 'xy':0.0})

    def setStrain(self, eps):
        """
        update state for a user provided axial strain value

        :param eps:  strain or strain tensor
        :return: n/a
        """
        self.strain = np.array([eps['xx'],eps['yy'],eps['xy']])

        # update stress state
        E  = self.parameters['E']
        t  = self.parameters['t']
        nu = self.parameters['nu']
        fy = self.parameters['fy']

        # default consistency parameter
        gamma = 0.0

        self.Et = E*t/(1. - nu*nu) * np.array([[1.,nu,0.],[nu,1.,0.],[0.,0.,(1.-nu)/2.]])

        Cinv = 1/(E*t) * np.array([[1.,-nu,0.],[-nu,1.,0.],[0.,0.,2.*(1.+nu)]])
        Phi  = np.array([[2.,-1.,0.],[-1.,2.,0.],[0.,0.,6.]])

        # elastic predictor
        self.sig = self.Et @ ( self.strain - self.plastic_strain )

        # check yield condition
        (sxx, syy, sxy) = self.sig
        f = self.sig @ Phi @ self.sig / 2. - (t*fy)**2

        gamma = 0.0
        Xi = self.Et

        # plastic corrector as needed
        if f >= 0.0:
            # loop
            r = Phi @ self.sig
            Xixr = Xi @ r
            gamma += f / (r @ Xixr)
            Xi = (Cinv + gamma * Phi).I
            self.sig = Xi @ ( self.strain - self.plastic_strain )
            self.Et  = Xi

            print("material entering plastic state")

        #print(4*'{:12.8e}  '.format(eps, f, self.plastic_strain, self.sig ))

    def getStrain(self):
        return self.sig / self.parameters['E'] + self.plastic_strain

    def updateState(self):
        # update state now that the global analysis has converged
        E  = self.parameters['E']
        t  = self.parameters['t']
        nu = self.parameters['nu']

        Cinv = 1 / (E * t) * np.array([[1., -nu, 0.], [-nu, 1., 0.], [0., 0., 2. * (1. + nu)]])
        self.plastic_strain = self.strain - Cinv @ self.sig


if __name__ == "__main__":
    # testing the Node class
    mat = PlaneStress(params={'E':100.0, 'nu':0.0, 'fy':1.0})

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

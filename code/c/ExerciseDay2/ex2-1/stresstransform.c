#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void StressTransform(double sigx, double sigy, double tau, 
					double *sigxp, double *sigyp, double *taup, 
					double theta) {

	double pi = 4.0*atan(1.);
	double th = theta * pi/180.;

	double sn = sin(th);
	double cs = cos(th);

	*sigxp = sigx*cs*cs + sigy*sn*sn + 2.*tau*sn*cs;
	*sigyp = sigx*sn*sn + sigy*cs*cs - 2.*tau*sn*cs;
	*taup  = (sigy - sigx)*sn*cs + tau*(cs*cs - sn*sn);
}


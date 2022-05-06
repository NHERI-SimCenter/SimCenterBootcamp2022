#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "stresstransform.h"


// 
// check out the new function header:
// ... much more compact
// ... much easier to adapt to 3d states of stree (just change STRESS)
//

void StressTransform(STRESS s, STRESS *sp, double theta) {

	double pi = 4.0*atan(1.);
	double th = theta * pi/180.;

	double sn = sin(th);
	double cs = cos(th);

	// these next lines need to be adapted to work with the new header ...

	*sigxp = sigx*cs*cs + sigy*sn*sn + 2.*tau*sn*cs;
	*sigyp = sigx*sn*sn + sigy*cs*cs - 2.*tau*sn*cs;
	*taup  = (sigy - sigx)*sn*cs + tau*(cs*cs - sn*sn);
}


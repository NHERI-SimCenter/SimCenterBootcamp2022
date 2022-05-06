#include <stdio.h>
#include <stdlib.h>

#include "stresstransform.h"


int main(int argc, char **argv) {

	STRESS S0;
	STRESS Sp;

	S0.sigx = 12.0;
	S0.sigy = -5.5;
	S0.tau  =  3.5;

	StressTransform(S0, &Sp, 0.0);
	printf("sigx' = %12.6f\nsigy' = %12.6f\ntau'  = %12.6f\n\n", Sp.sigx, Sp.sigy, Sp.tau);

	StressTransform(S0, &Sp, 25.0);
	printf("sigx' = %12.6f\nsigy' = %12.6f\ntau'  = %12.6f\n\n", Sp.sigx, Sp.sigy, Sp.tau);
}



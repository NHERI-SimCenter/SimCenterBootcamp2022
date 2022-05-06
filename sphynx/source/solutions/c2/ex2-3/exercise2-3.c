#include <stdio.h>
#include <stdlib.h>
#include <math.h>    // need this for the constant pi = M_PI

#include "stresstransform.h"

int main(int argc, char **argv) {

	// get dth from the first argument.  This is given in degrees!

	double dth;

	if (argc>1) { dth = atof(argv[1]) ; }
	else { dth = 22.5; }

	// set the initial stress state

	STRESS S0;

	S0.sigx = 12.0;
	S0.sigy = -5.5;
	S0.tau  =  3.5;

	// define  target container for transformed stress

	STRESS Sp;

	// loop to compute transformed states

	for (double th=0.0; th <= 180.; th+=dth) {

	    StressTransform(S0, &Sp, th);
	    printf("%12.6f, %12.6f, %12.6f, %12.6f\n", th, Sp.sigx, Sp.sigy, Sp.tau);
	}
}

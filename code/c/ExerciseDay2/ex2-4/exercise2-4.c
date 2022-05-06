#include <stdio.h>
#include <stdlib.h>

#include "stresstransform.h"

/* ************************************************************************
 * 
 *      writing to a binary file
 *
 * ************************************************************************/

int main(int argc, char **argv) {

	// get dth from the first argument.  This is given in degrees!

	double dth;

	if (argc>1) {
		dth = atof(argv[1]) ;
	}
	else {
		dth = 22.5;
	}

	// open the file for writing 

	FILE *f_ptr;

	f_ptr = ...

	// define a data structure for a single entry in the file

	struct RESULT {
		...
		...
	} result;

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

	    // THIS PRINT STATEMENT NEEDS TO BE REPLACED BY WRITING TO THE FILE
	    printf("%12.6f, %12.6f, %12.6f, %12.6f\n", th, Sp.sigx, Sp.sigy, Sp.tau);

	}

	// done writing data -- close the file
	...
}


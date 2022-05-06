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

	f_ptr = fopen("mohrcircle.dta","wb");

	// define a data structure for a single entry in the file

	struct RESULT {
		double angle;
		STRESS thestress;
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

	    //
	    // note:
	    //
	    // ... result is a structure. fwrite needs a reference to that structure
	    // ... sizeof(result) returns the number of bytes occupied by the ONE copy of result
	    // ... 1 is the number of blocks to write
	    // ... f_ptr is a pointer to the FILE handle

            result.angle = th;
	    result.thestress = Sp;

	    fwrite(&result, sizeof(result), 1, f_ptr);

	}

	// done writing data -- close the file
	fclose(f_ptr);
}



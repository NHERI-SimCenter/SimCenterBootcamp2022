#include <stdio.h>
#include <stdlib.h>


/* ************************************************************************
 * 
 *      read data back from a binary file
 *
 * ************************************************************************/

// we include this for the definition of struct STRESS

#include "stresstransform.h"

int main(int argc, char **argv) {

	// define a data structure for a single entry in the file
	//
	// ... it is very difficult to read a binary file 
	// ... without knowing about its internal structure !!!!

	struct RESULT {
		double angle;
		STRESS thestress;
	} result;

	// open the file for reading

	FILE *f_ptr;
	f_ptr = fopen("mohrcircle.dta","rb");

	// loop to compute transformed states

	while ( fread(&result, sizeof(result), 1, f_ptr) ) {

	    //
	    // note:
	    //
	    // ... result is a structure. fread needs a reference to that structure
	    // ... sizeof(result) returns the number of bytes occupied by the ONE copy of result
	    // ... 1 is the number of blocks to write
	    // ... f_ptr is a pointer to the FILE handle

            double th = result.angle;
	    STRESS Sp = result.thestress;

	    printf("%16.12f, %16.12f, %16.12f, %16.12f\n", th, Sp.sigx, Sp.sigy, Sp.tau);
	}

	// done writing data -- close the file
	fclose(f_ptr);
}



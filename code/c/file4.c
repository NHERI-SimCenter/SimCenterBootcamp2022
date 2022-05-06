
// program to write n random values between 0 and maxVal out
// output is sent to 2 files:
//   1. file.out a binary file
//   2. fileAscii.out an ascii file (i.e. readable by human)

// written: fmk

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {

  if (argc != 3) {
    fprintf(stdout, "ERROR correct usage appName n\n");
    return -1;
  }
  int n = atoi(argv[1]);
  float maxVal = atof(argv[2]);
  
  float *theVector = (float *)malloc(n * sizeof(float));

  FILE *fileBinaryPtr = fopen("file4.out","wb");
  FILE *fileAsciiPtr = fopen("file4Ascii.out","w");  

  srand(100);
  //srand((unsigned int)time(0)); // the usual way to call srand
  rand(); // i like to call it once

  for (int i=0; i<n; i++)
    theVector[i]= ((float)rand()/(float)RAND_MAX) * maxVal;

  //
  // write them one at a time using fprintf to ascii file
  //
  
  for (int i=0; i<n; i++) {
    fprintf(fileAsciiPtr,"%f ",theVector[i]);
  }
  fprintf(fileAsciiPtr,"\n");

  //
  // write in single call to binary file
  //
  
  fwrite(theVector, sizeof(float), n, fileBinaryPtr);  

  fclose(fileBinaryPtr);
  fclose(fileAsciiPtr);  
}

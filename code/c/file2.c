
// program to write n lines, each line containing a csv list of int and two double

// written: fmk

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {

  if (argc != 4) {
    fprintf(stdout, "ERROR correct usage appName n maxVal outputFile \n");
    return -1;
  }
  
  int n = atoi(argv[1]);
  float maxVal = atof(argv[2]);
  
  FILE *filePtr = fopen(argv[3],"w");

  srand(100);
  //srand((unsigned int)time(0)); // the usual way to call srand
  rand(); // i like to call it once

  for (int i=0; i<n; i++) {
    float float1 = ((float)rand()/(float)RAND_MAX) * maxVal;
    float float2 = ((float)rand()/(float)RAND_MAX) * maxVal;
    fprintf(filePtr,"%d, %f, %f\n", i, float1, float2);
  }

  fclose(filePtr);  
}

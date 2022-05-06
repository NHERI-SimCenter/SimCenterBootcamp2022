// program to read a binary file containing unknown number of floats into a vector
// written: fmk

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stdout, "ERROR correct usage appName binaryIn \n");
    return -1;
  }
  FILE *fileBinaryPtr = fopen(argv[1],"rb");

  int vectorSize = 0;  
  int maxVectorSize = 100;
  float *theVector = (float *)malloc(maxVectorSize*sizeof(float));

  // read multiple times until no more data,
  // enlarging vector each time in maxVectorSize chunks
  int numValues = 0;
  long numRead = 0;
  bool allDone = false;
  
  while (allDone == false) {
    
    int numRead = fread(&theVector[vectorSize], sizeof(float), maxVectorSize, fileBinaryPtr);
    
    numValues += numRead;
    vectorSize += numRead;

    if (numRead == maxVectorSize) {
      // not done, enlarge for next time by creating new, copying & then freeing old
      float *newVector = (float *)malloc((vectorSize + maxVectorSize)*sizeof(double));
      for (int i=0; i< vectorSize; i++)
	newVector[i] = theVector[i];
      free(theVector);
      theVector = newVector;
    } else
      allDone = true;
  }

  printf("vectorSize: %d\n",vectorSize);
  
  fclose(fileBinaryPtr);
}

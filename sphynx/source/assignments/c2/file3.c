
/*******************************************************************
 * program to read values from a file, 
 * with each line being csv list of int and two double
 *
 * program fails if num lines > 100
 *    Major flaw will cause data to be overwritten outside array 
 *    bounds if #lines > 100 & will ultimataly lead to a segmentation fault
 *
 * Exerise is to fix flaw WITHOUT just setting maxVectorSize incredibly large
 *
 * written: fmk
 ******************************************************************* */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stdout, "ERROR correct usage appName inputFile\n");
    return -1;
  }
  
  FILE *filePtr = fopen(argv[1],"r"); 

  int i = 0;
  float float1, float2;
  int maxVectorSize = 100;
  double *vector1 = (double *)malloc(maxVectorSize*sizeof(double));
  double *vector2 = (double *)malloc(maxVectorSize*sizeof(double));  
  int vectorSize = 0;
  
  while (fscanf(filePtr,"%d, %f, %f\n", &i, &float1, &float2) != EOF) {
    vector1[vectorSize] = float1;
    vector2[vectorSize] = float2;
    printf("%d, %f, %f\n",i, vector2[i], vector1[i]);
    vectorSize++;

    if (vectorSize == maxVectorSize) {
      /* some code needed here .. programming exercise */
    }
  }

  fclose(filePtr);  
}

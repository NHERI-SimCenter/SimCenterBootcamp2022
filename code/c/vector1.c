#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "myVector.h"

int main(int argc, char **argv) {

  // check argss
  if (argc != 3) {
    fprintf(stderr,"Need 3 args: appName n maxVal\n");
    return -1;
  }
  
  // from input read array size, max random value, and create arrays
  int n = atoi(argv[1]);
  double maxVal = atof(argv[2]);
  
  double *data1 = createMyVector(n);
  double *data2 = createMyVector(n);
  double *data3 = createMyVector(n);  

  // fill in vectors with random numbers

  srand(100);
  //srand((unsigned int)time(0)); // the usual way to call srand
  rand(); // i like to call it once
  
  for (int i=0; i<n; i++) {
    data1[i] = ((float)rand()/(float)RAND_MAX) * maxVal;
    data2[i] = ((float)rand()/(float)RAND_MAX) * maxVal;;   
  }
  
  printMyVector(data1, n, "vector 1");
  printMyVector(data2, n, "vector 2");  
  
  // dotSum the vectors & print result;
  dotSumMyVector(data1, data2, data3, n);
  printMyVector(data3, n, "dotSum");

  return 0;
}


#include <math.h>
#include <stdlib.h>
#include <stdio.h>

double *createMyVector(int size) {
  double *newVector = (double *)malloc(size*sizeof(double));
  return newVector;
}

double normMyVector(double *data, int size) {
  double dot = 0;
  for (int i = 0; i < size; i++) {
    dot += data[i]*data[i];
  }
  return sqrt(dot);
}


double dotMyVector(double *data1, double *data2, int size) {
  double dot = 0;
  for (int i = 0; i < size; i++) {
    dot += data1[i]*data2[i];
  }
  return sqrt(dot);
}

void dotSumMyVector(double *data1, double *data2, double *result, int size) {
  for (int i = 0; i < size; i++) {
    result[i] = data1[i] + data2[i];
  }
}

void printMyVector(double *data, int size, char *name) {

  if (name != 0)
    fprintf(stdout, "%s: ", name);
  
  for (int i = 0; i < size; i++) {
    fprintf(stdout, "%le ", data[i]);
  }
  fprintf(stdout,"\n");
}

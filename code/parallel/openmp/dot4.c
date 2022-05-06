#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DATA_SIZE 100000000

int main(int argc, const char **argv) {
  double dot = 0;
  double a[DATA_SIZE];
  for (int i=0; i<DATA_SIZE; i++) {
    a[i] = i+1;
  }
  int numThread = 0;
  double tdata = omp_get_wtime();

#pragma omp parallel reduction(+:dot)
  {
    int tid = omp_get_thread_num();
    int numT = omp_get_num_threads();
    double sum = 0.;
    if (tid == 0) numThread = numT;
    for (int i=tid; i<DATA_SIZE; i+= numT)
      sum += a[i]*a[i];

    dot += sum;
  }
  
  dot = sqrt(dot);
  tdata = omp_get_wtime() - tdata;
  printf("dot %f in time %f %d\n", dot, tdata, numThread);
  return 0;
}




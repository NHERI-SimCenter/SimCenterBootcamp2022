#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DATA_SIZE 10000

int main(int argc, const char **argv) {
  double dot = 0;
  double a[DATA_SIZE];
  for (int i=0; i<DATA_SIZE; i++) {
    a[i] = i+1;
  }

  double tdata = omp_get_wtime();

#pragma omp parallel reduction(+:dot)
  {
    #pragma parallel for
    for (int i=0; i<DATA_SIZE; i++)
      dot += a[i]*a[i];
  }

  dot = sqrt(dot);
  tdata = omp_get_wtime() - tdata;
  printf("dot %f in time %f \n", dot, tdata);
  return 0;
}




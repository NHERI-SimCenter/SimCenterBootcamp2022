#include <omp.h>
#include <stdio.h>
#include <math.h>

#define DATA_SIZE 10000000

int main(int argc, const char **argv) {
  double a[DATA_SIZE], b[DATA_SIZE], c[DATA_SIZE];
  for (int i=0; i<DATA_SIZE; i++) {
    a[i] = i+1;
    b[i] = i+1;
  }
  double tdata = omp_get_wtime();
#pragma omp parallel for
    for (int i=0; i<DATA_SIZE; i++)
      c[i] = a[i]+b[i];

  tdata = omp_get_wtime() - tdata;
  printf("first %f last %f in time %f using %d\n",c[0], c[DATA_SIZE-1], tdata);
  return 0;
}



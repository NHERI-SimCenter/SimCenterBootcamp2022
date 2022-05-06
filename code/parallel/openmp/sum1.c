#include <omp.h>
#include <stdio.h>

#define DATA_SIZE 10000000

void sumVectors(int N, double *A, double *B, double *C, int tid, int numT);

int main(int argc, const char **argv) {
  double a[DATA_SIZE], b[DATA_SIZE], c[DATA_SIZE];
  int num;
  for (int i=0; i<DATA_SIZE; i++) {
    a[i] = i+1;
    b[i] = i+1;
  }
  double tdata = omp_get_wtime();
#pragma omp parallel
  {
    int tid = omp_get_thread_num();
    int numT = omp_get_num_threads();
    num = numT;
    sumVectors(DATA_SIZE, a, b, c, tid, numT);
  }
  tdata = omp_get_wtime() - tdata;
  printf("first %f last %f in time %f using %d threads\n",c[0], c[DATA_SIZE-1], tdata, num);
  return 0;
}

void sumVectors(int N, double *A, double *B, double *C, int tid, int numT) {

  // determine start & end for each thread
  int start =   tid * N / numT;
  int end = (tid+1) * N / numT;
  if (tid == numT-1) 
    end = N;

  // do the vector sum for threads bounds
  for(int i=start; i<end; i++) {
    C[i] = A[i]+B[i];
  }
}



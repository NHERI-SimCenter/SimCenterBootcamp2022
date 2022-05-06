#include <omp.h>
#include <stdio.h>

int main(int argc, const char **argv) {

  int id, numP;

#pragma omp parallel num_threads(4)
  {
    id = omp_get_thread_num();
    numP = omp_get_num_threads();
    printf("Hello World from %d of %d threads\n",id,numP);
  }

  return(0);
}


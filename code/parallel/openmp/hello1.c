#include <omp.h>
#include <stdio.h>

int main(int argc, char **argv) {

#pragma omp parallel
  {
    int id = omp_get_thread_num();
    int numP = omp_get_num_threads();
    printf("Hello World, I am  %d of %d\n",id,numP);
  }
  return(0);
}

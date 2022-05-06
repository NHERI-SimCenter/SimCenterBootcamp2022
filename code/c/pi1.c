#include <stdio.h>
#include <time.h>

static long int numSteps = 1000000000;

int main(int argc, char **argv) {

  // perform calculation
  double pi   = 0;
  double x  = dx*0.50;
  double dx = 1./(double)numSteps;

  for (int i=0; i<numSteps; i++) {
    pi += 4./(1.+x*x);
    x += dx;
  }
  
  pi *= dx;
  
  printf("PI = %16.14f\n",pi);
  return 0;
}

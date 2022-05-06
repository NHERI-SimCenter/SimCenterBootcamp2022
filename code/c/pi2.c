#include <stdio.h>
#include <time.h>

static long int numSteps = 1000000000;

int main(int argc, char **argv) {

  double pi   = 0;
  double stepSize = 1.0/(double) numSteps;

  for (int i=0; i<numSteps; i++) {
    double x = (i+0.5)*stepSize;
    pi += 4./(1.+x*x);
  }
  
  pi *= stepSize;
  
  printf("PI = %16.14f\n",pi);
  return 0;
}

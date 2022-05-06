
#include <stdio.h>

int main(int argc, char **argv) {
  int    i1 = 5;
  float  f1 = 1.23456789012;
  double d1 = 1.2345678901234567890123e6;
  char   c1 = 'A';
  printf("int %d, float %f, double %lf, char %c \n", i1, f1, d1, c1);
  printf("int %d, float %e, double %le, char %c \n", i1, f1, d1, c1);
  printf("int %3d, float %16.3e, double %23.8le, char %2c \n", i1, f1, d1,

  return(0);
}




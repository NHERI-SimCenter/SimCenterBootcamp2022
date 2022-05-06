#include <stdio.h>

int main(int argc, char **argv) {
  int n = 1;
  float a = 1.1e15;
  float c = 1.234567e-3;
  float val1 = (5*a - 5*a) + c;  
  float val2 = (5*a + c) - 5*a;
  printf("If Exact All would be equal %f  %f  %f \n", c, val1, val2);
}

#include <stdio.h>
#include <stdlib.h>
int factorial(int n);

int main(int argc, const char **argv) {
  if (argc < 2) {
    printf("Program needs an integer argument\n");
    return(-1);
  }

  int n = atoi(argv[1]);
  int fact = factorial(n);
  printf("factorial(%d) is %d\n",n, fact);
  return 0;
}

// recursive dunction factorial, i.e. it calls itself
int factorial(int n) {
  if (n == 1) 
    return 1;
  else 
    return n*factorial(n-1);
}
	       

// purpose: to show operators: +,-,*,/,+=,-=,++,--

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int a = 5;
  int b = 2;

  c = a+b;
  printf("%d and %d is %d  \n", a, b, c);

  c = a-b;
  printf("%d minus %d is %d  \n", a, b, c);

  c = a*b;
  printf("%d times %d is %d  \n", a, b, c);

  c = a/b;
  printf("%d divide %d is %d  \n",a,b, c);

  // special increment and decrement operators
  a+=2;
  a-=2;
  a++;
  a--;

  return(0);
}




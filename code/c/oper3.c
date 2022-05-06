#include <stdio.h>

int main(int argc, char **argv) {
  int a = 5;
  int b = 2;

  int c = a + b * 2;

  printf("%d + %d * 2 is %d  \n",a,b,c);

  c = a * 2 + b * 2;

  printf("%d * 2 + %d * 2 is %d  \n",a,b,c);

  // use paranthesis
  c = ((a * 2) + b ) * 2;

  printf("((%d * 2) + %d ) * 2; is %d  \n",a,b,c);

  return(0);
}




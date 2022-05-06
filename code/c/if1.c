#include <stdio.h>

int main(int argc, char **argv) {
  int a = 15;

  if (a < 10) {
    printf("%d is less than 10 \n", a);
  }

  if (a <= 10) {
    printf("%d is less than or equal to 10 \n", a);
  }

  if (a > 10) {
    printf("%d is greater than 10 \n", a);
  }

  return(0);
}




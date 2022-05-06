// written: fmk

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int intArray[5] = {19, 12, 13, 14, 50};
  int sum;
  for (int count = 0; count < 5; count++) {
    sum += intArray[count];
  }
  printf("Sum is %d \n", sum);

  return(0);
}

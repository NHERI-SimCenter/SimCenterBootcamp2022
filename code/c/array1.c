#include <stdio.h>

int main(int argc, char **argv) {
  int intArray[5] = {1, 2, 3, 4, 5};
  intArray[0] = 21;
  int first = intArray[0];
  int last = intArray[4];
  printf("First element, %d, last element %d \n", first, last);

  return(0);
}




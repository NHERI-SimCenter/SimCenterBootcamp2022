#include <stdio.h>

int main(int argc, char **argv) {
  int intArray[6] = {19, 12, 13, 14, 50, 0};
  int sum = 0;
  for (int i = 0, j = 1; i < 6; i+=2, j+=2) {
    sum += intArray[i] + intArray[j];
  }
  printf("Sum is %d \n", sum);

  return(0);
}

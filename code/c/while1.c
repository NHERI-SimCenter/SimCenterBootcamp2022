#include <stdio.h>

int main(int argc, char **argv) {
  int intArray[5] = {19, 12, 13, 14, 50};
  int sum = 0, count = 0;
  while (count < 5) {
    sum += intArray[count];
    count++;
  }
  printf("Sum is %d \n", sum);

  return(0);
}

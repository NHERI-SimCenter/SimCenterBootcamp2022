#include <stdio.h>

// function to evaluate vector sum
int sumArray(int *data, int size);

int main(int argc, const char **argv) {
  int intArray1[6] = {19, 12, 13, 14, 50, 0};
  int intArray2[5] = {21, 22, 23};
  int sum1 = sumArray(intArray1, 6);
  int sum2 = sumArray(intArray2, 3);
  printf("Sums are %d and %d \n", sum1, sum2);
  return 0;
}

// function to evaluate vector sum
int sumArray(int *data, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++, data++) {
    sum += *data;
  }
  return sum;
}


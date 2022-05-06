#include <stdio.h> 

void sumInt(int a, int b, int *sum);

int main() { 
  int int1, int2, sum=0;

  printf("Enter first integer: ");
  scanf("%d", &int1); 
  printf("Enter second integer: "); 
  scanf("%d", &int2); 

  sumInt(int1, int2, &sum);
  printf("%d + %d = %d \n", int1, int2, sum);
  return 0;
}

void sumInt(int a, int b, int *sum) {
  *sum = a+b;
}





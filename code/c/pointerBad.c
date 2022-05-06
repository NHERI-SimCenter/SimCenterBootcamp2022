#include <stdio.h>
int main() {
  int x=10, y=20;
  int *ptrX = 0;

  ptrX = &x;
  y = *ptrX + x;
  printf("%d + %d = %d \n",x,x,y);

  x = 20;
  printf("*Ptrx: %d  xPtr %d\n",*ptrX, ptrX);
  return(0);
}

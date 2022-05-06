#include <stdio.h>
int main() {
  int x=10, y=20;
  int *ptrX = 0;
  
  printf("ptrX %p address of x %p\n",ptrX, &x);  
  //  printf("value of what xPtr points to: %d\n",*ptrX);  

  ptrX = &x;
  y = *ptrX + x;
  printf("%d + %d = %d \n",*ptrX, x, y);
  printf("ptrX %p address of x %p\n",ptrX, &x);

  *ptrX = 50;
  printf("x %d == *ptrX %d \n",*ptrX, x);
  
  return(0);
}

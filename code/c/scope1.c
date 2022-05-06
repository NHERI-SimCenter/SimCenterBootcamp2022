#include <stdio.h>
int sum(int, int);
int x = 20;
int main(int argc, char **argv) {
  printf("LINE 5: x = %d\n",x);

  int x = 5;
  printf("LINE 8: x = %d\n",x);
  
  if (2 > 1) {
    int x = 10;
    printf("LINE 12: x = %d\n",x);    
  }
  printf("LINE 14: x = %d\n",x);    

  x = sum(x,x);
  printf("LINE 17: x = %d\n",x);    
}

int sum(int a, int b) {
  printf("LINE 21: x = %d\n",x);    
  return a+b;
}

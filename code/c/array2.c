#include <stdio.h>

int main(int argc, const char **argv) {
  double dArray[2][4]= {{19.1, 12, 13, 14e2},
		       {21.2, 22, 23, 24.2e-3}};
  dArray[0][0] = 101.5;
  double first = dArray[0][0];
  double last =  dArray[1][3]; 
  printf("First %.4f, last %.4f \n", first, last);
  return(0);
}




#include <stdio.h>

int main(int argv, char **argc) {
  int nDigit = 0, nOther = 0;
  char c;
  while ((c=getchar()) != EOF) {
    switch(c) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      nDigit++;
      break;
    default:
      ;
    }

  printf("Num Digit: %d Num Other: %d\n",nDigit, nOther);
  return 0;
}

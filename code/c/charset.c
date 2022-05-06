#include <stdio.h>
int main(int argv, const char **argc) {
  for (int i=-127; i<127; i++)
    printf("%d -> %c \n",i,i);
}

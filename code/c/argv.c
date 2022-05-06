#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

  fprintf("Number of arguments: %d\n", argc);

  // print out each argument
  for (int i=0; i<argc; i++) {
    int length = strlen(argv[i]);
    printf("%d %d %s\n", i, length, argv[i]);
  }
  
  return 0;
}

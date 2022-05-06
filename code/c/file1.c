
// program to write string "Hello World" to a file named file1.out
// written: fmk

#include <stdio.h>

int main(int argc, char **argv) {

  FILE *filePtr = fopen("file1.out","w");
  fprintf(filePtr, "Hello World\n");
  fclose(filePtr);
}

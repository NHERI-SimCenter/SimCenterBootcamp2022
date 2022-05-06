#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  char greeting[] = "Hello";
  int length = strlen(greeting);
  printf("%s a string of length %d\n",greeting, length);

  char *greetingCopy = (char *)malloc((length+1)*sizeof(char));
  strcpy(greetingCopy, greeting);
  printf("%s a string of length %d\n",greetingCopy, strlen(greetingCopy));

  return(0);
}


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  /* check args */
  if (argc != 2) {
    fprintf(stderr,"Need 3 args: appName n\n");
    return -1;
  }
  
  double *array1 = 0;
  
  /* from input read array size, max random value, and create arrays */
  int n = atoi(argv[1]);
  if (n <= 0) {
    fprintf(stdout,"N needs to be greater than 0\n");
    return -2;
  }

  /* allocate memory & set the data */
  array1 = (double *)malloc(n*sizeof(double));
  
  for (int i=0; i<n; i++) {
    array1[i] = i;
  }

  for (int i=0; i<n; i++) {
    double value = array1[i];
    printf("%.4lf  %p \n", value, &array1[i]);
  }
  
  /* free the array */
  free(array1);
}

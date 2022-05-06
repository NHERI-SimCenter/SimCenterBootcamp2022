#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) { 
  /* check args */
  if (argc != 2) {
    fprintf(stderr,"Need 3 args: appName n\n");
    return -1;
  }
  /* from input read array size, max random value, and create arrays */
  int n = atoi(argv[1]);
  if (n <= 0) {
    fprintf(stdout,"N needs to be greater than 0\n");
    return -2;
  }
  
  double **matrix1 =0;
  
  // allocate memory & set the data
  matrix1 = (double **)malloc(n*sizeof(double *));
  for (int i=0; i<n; i++) {
    matrix1[i] = (double *)malloc(n*sizeof(double));
    for (int j=0; j<n; j++)
      matrix1[i][j] = i;
  }
  
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++)
      printf("(%d,%d) %.4f\n", i,j, matrix1[i][j]);
  }

  // free the data
  for (int i=0; i<n; i++)
    free(matrix1[i]);
  free(matrix1);

}

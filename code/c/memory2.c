#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  /* check args */
  if (argc != 2) {
    fprintf(stderr,"Need 3 args: appName n\n");
    return -1;
  }
  
  double *array1 =0, *array2 = 0, *array3 =0;
  
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
  
  array2 = array1;
  array3 = &array1[0];
  
  for (int i=0; i<n; i++, array2++, array3++) {
    double value1 = array1[i];
    double value2 = *array2;
    double value3 = *array3;
    printf("%.4lf %.4lf %.4lf %p %p %p\n", value1, value2, value3,
    	   &array1[i], array2, array3);
  }
  
  /* free the array */
  free(array1);
}

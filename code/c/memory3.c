#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int n;
  double *matrix1 =0;
  double *matrix2 =0;

  printf("enter n: ");
  scanf("%d", &n);
  
  int numRows = n; 
  int numColumns=n;

  // allocate memory & set the data: ROW MAJOR ORDER
  matrix1 = (double *)malloc(numRows*numCols*sizeof(double *));
  
  for (int i=0; i<numRows; i++) {
    for (int j=0; j<numCols; j++)
      matrix1[i*numCols + j] = i;  // matrix1[i][j]=i;
  }

  free(matrix1);

  // allocate memory & set the data: COLUMN MAJOR ORDER
  matrix1 = (double *)malloc(n*n*sizeof(double *));
  
  for (int i=0; i<numRows; i++) {
    for (int j=0; j<numCols; j++)
      matrix1[i+j*numCols] = i;  // matrix1[i][j]=i;
  }

  // but above has likely poor cache performance
  for (int j=0; j<numCols; j++)
    for (int i=0; i<numRows; i++) {
      matrix1[i+j*numCols] = i;  // matrix1[i][j]=i;
  }

  // while above has good ordering, below may be faster
  double dataPtr = matrix1;
  for (int j=0; j<numCols; j++)
    for (int i=0; i<numRows; i++) {
      *dataPtr++ = i;
  }

  // free the data
  free(matrix2);

}

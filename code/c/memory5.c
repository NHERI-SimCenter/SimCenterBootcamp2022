#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int n = 3;

  double matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
  double *matrix1 =0;
  double *matrix2 =0;

  int numRows = n; 
  int numCols =n;

 // ORIGINAL MATRIX
  printf("Original 2d Matrix\n");
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++)   {
      printf("%f ",matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // allocate memory & set the data: ROW MAJOR ORDER
  matrix1 = (double *)malloc(numRows*numCols*sizeof(double));

  for (int i=0; i<numRows; i++) {
    for (int j=0; j<numCols; j++)
      matrix1[i*numCols + j] = matrix[i][j];  
  }

 // ORIGINAL MATRIX
  printf("Row Major Order\n");  
  for (int i=0; i<n*n; i++)
    printf("%f ",matrix1[i]);
  printf("\n");
  
  free(matrix1);

  // allocate memory & set the data: COLUMN MAJOR ORDER
  matrix1 = (double *)malloc(n*n*sizeof(double));

  for (int i=0; i<numRows; i++) {
    for (int j=0; j<numCols; j++)
      matrix1[i+j*numCols] = matrix[i][j];  // matrix1[i][j]=i;
  }
  printf("Row Major Order - Version1\n");  
  for (int i=0; i<n*n; i++)
    printf("%f ",matrix1[i]);
  printf("\n");
  
  // but above has likely poor cache performance
  for (int j=0; j<numCols; j++)
    for (int i=0; i<numRows; i++) {
      matrix1[i+j*numCols] = matrix[i][j];  // matrix1[i][j]=i;
  }

  printf("Row Major Order - Version2\n");    
  for (int i=0; i<n*n; i++)
    printf("%f ",matrix1[i]);
  printf("\n");
  
  // while above has good ordering, below may be faster
  double *dataPtr = matrix1;
  for (int j=0; j<numCols; j++)
    for (int i=0; i<numRows; i++) {
      *dataPtr++ = matrix[i][j];
  }
  printf("Row Major Order - Version3\n");  
  for (int i=0; i<n*n; i++)
    printf("%f ",matrix1[i]);
  printf("\n");  

  // free the data
  free(matrix1);
}

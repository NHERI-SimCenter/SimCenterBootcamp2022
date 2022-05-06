#include "Matrix.h"
#include "Vector.h"
#include <new>

double Matrix::MATRIX_NOT_VALID_ENTRY(0);

Matrix::Matrix(int rows, int cols)
:numRows(rows), numCols(cols), data(0)
{
  int size = numRows * numCols;
  
  if (size > 0) {
    data = new (std::nothrow) double[size];
    if (data == 0) {
      std::cerr << "WARNING:Matrix::Matrix(int,int): Ran out of memory on init "
		<< "of size " << size << "\n";
      numRows = 0; numCols =0; size =0;
    } else {
      double *dataPtr = data;
      for (int i=0; i<size; i++)
	*dataPtr++ = 0.0;
    }
  } else {
    std::cerr << "WARNING:Matrix::Matrix(int,int): need pos integers\n";
    exit(-1);
  }
}

Matrix::~Matrix()
{
  if (data != 0 ) {
    delete [] data; 
  }
}

Vector
Matrix::operator*(const Vector &V) const
{
  Vector result(numRows);
    
  if (V.Size() != numCols) {
    std::cerr << "Matrix::operator*(Vector): incompatable sizes\n";
    return result;
  } 
    
  double *dataPtr = data;
  for (int i=0; i<numCols; i++)
    for (int j=0; j<numRows; j++)
      result(j) += *dataPtr++ * V(i);
  
  return result;
}

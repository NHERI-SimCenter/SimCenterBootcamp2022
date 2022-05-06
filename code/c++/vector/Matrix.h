#ifndef _SIMCENTER_MATRIX
#define _SIMCENTER_MATRIX

#include <iostream>
#include "Vector.h"

class Matrix {
 public:
    Matrix(int nrows, int ncols);
    ~Matrix();

    inline double &operator()(int row, int col);
    inline double operator()(int row, int col) const;

    Vector operator*(const Vector &V) const;

 private:
    int numRows, numCols;
    double *data;
    static double MATRIX_NOT_VALID_ENTRY;
};

inline double &
Matrix::operator()(int row, int col)
{ 
#ifdef _DEBUG
  if ((row < 0) || (row >= numRows)) {
    std::cerr << "Matrix::operator() - row " << row << " our of range [0, " <<  numRows-1 << "\n";
    return data[0];
  } else if ((col < 0) || (col >= numCols)) {
    std::cerr << "Matrix::operator() - row " << col << " our of range [0, " <<  numCols-1 << "\n";
    return MATRIX_NOT_VALID_ENTRY;
  }
#endif
  return data[col*numRows + row];
}


inline double 
Matrix::operator()(int row, int col) const
{ 
#ifdef _DEBUG
  if ((row < 0) || (row >= numRows)) {
    std::cerr << "Matrix::operator() - row " << row << " our of range [0, " <<  numRows-1 << "\n";
    return data[0];
  } else if ((col < 0) || (col >= numCols)) {
    std::cerr << "Matrix::operator() - row " << col << " our of range [0, " <<  numCols-1 << "\n";
    return MATRIX_NOT_VALID_ENTRY;
  }
#endif
  return data[col*numRows + row];
}

#endif // _SIMCENTER_MATRIX

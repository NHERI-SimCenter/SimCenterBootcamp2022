#include <iostream>

#include "Vector.h"
#include "Matrix.h"

int main(int argc, char **argv) {

  // create 2 vectors
  Vector a(4);
  Vector b(4);

  std::cerr << "a: "; a.print();

  //
  // set a = 1, b = 20+i
  //

  a += 1;
  for (int i=0; i<4; i++) {
    b(i) = 20+i;
  }

  //
  // print a and b
  //

  std::cout << "a: "; a.print();
  std::cout << "b: "; b.print();

  // error check
  b(4) = 24;

  std::cout << "b: "; b.print();

  //
  // new vector c = a + b, print c and norm of c
  //

  Vector c = a + b;
  double norm = c.norm();  
  
  std::cout << "c = a + b: "; c.print();
  std::cout << "norm(c): " << norm << "\n";

  //
  // new vector d of size 3, e = c + d; print e
  // 

  Vector d(3);
  d += 2;
  std::cout << "d: "; d.print();

  Vector e = c + d;
  std::cout << "e = c + d: "; e.print();

  Matrix m(4,4);
  for (int i=0; i<4; i++)
    m(i,i)=2;

  m(0,3) = 2;

  Vector f =  m * a;

  std::cout << "f = A*a: "; f.print();  
}

#include "Square.h"

int Square::numSquare = 0;

Square::~Square() {
  numSquare--;
  std::cout << "Square Destructor\n";
}

Square::Square(double w)
  :Shape(),width(w)
{
  //  width = w;
  numSquare++;
}

double
Square::GetArea(void) {
  return width*width;
}


void 
Square::PrintArea(std::ostream &s) {
  s << "Square: " << width*width  << " numSquare: " << numSquare << "\n";
}


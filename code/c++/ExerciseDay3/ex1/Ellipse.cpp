#include "Ellipse.h"

Ellipse::~Ellipse() {
  std::cout << "Ellipse Destructor\n";
}

Ellipse::Ellipse(double a, double b, string color)
  :ColoredShape(color)
{
  ax1 = a;
  ax2 = b;
}

double
Ellipse::getArea(void) {
  return ax1*ax2*getPI();
}

double
Ellipse::getPI(void) {
  return 3.14159;
}

void 
Ellipse::printArea(std::ostream &s) {
  s << "Ellipse: color: " << this->getColor() << ", area: " << this->getArea() << "\n";
}


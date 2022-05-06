#include "Circle.h"

Circle::~Circle() {
  std::cout << "Circle Destructor\n";
}

Circle::Circle(double radius, string color)
  :ColoredShape(color)
{
  r = radius;
}

double
Circle::getArea(void) {
  return r*getPI();
}

double
Circle::getPI(void) {
  return 3.14159;
}


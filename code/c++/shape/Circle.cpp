#include "Circle.h"

Circle::~Circle() {
  std::cout << "Circle Destructor\n";
}

Circle::Circle(double d) {
  diameter = d;
}

double
Circle::GetArea(void) {
  return this->GetPI() * diameter * diameter/4.0;
}

double
Circle::GetPI(void) {
  return 3.14159;
}

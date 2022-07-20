#include "Rectangle.h"

int Rectangle::numRect = 0;

Rectangle::~Rectangle() {
  numRect--;
  std::cout << "Rectangle Destructor " << this->getColor() << "\n";
}

Rectangle::Rectangle(double w, double d, string color)
  :ColoredShape(color), width(w), height(d)
{
  numRect++;
}

double
Rectangle::getArea(void) {
  return width*height;
}

void 
Rectangle::printArea(std::ostream &s) {
  s << "Rectangle: color: " << this->getColor() << ", area: "
    << width * height << " numRect: " << numRect << "\n";
}


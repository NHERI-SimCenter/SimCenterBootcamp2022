#include "Rectangle.h"

int Rectangle::numRect = 0;

Rectangle::~Rectangle() {
  numRect--;
  std::cout << "Rectangle Destructor\n";
}

Rectangle::Rectangle(double w, double d)
  :Shape(), width(w), height(d)
{
  numRect++;
}

double
Rectangle::GetArea(void) {
  return width*height;
}

void 
Rectangle::PrintArea(std::ostream &s) {
  s << "Rectangle: " << width * height << " numRect: " << numRect << "\n";
}


#include "ColoredShape.h"

ColoredShape::ColoredShape(string col)
  : color(col)
{

}

ColoredShape::~ColoredShape() {
  std::cout << "ColoredShape Destructor\n";
}

const string &
ColoredShape::getColor() {
  return color;
}

void
ColoredShape::printArea(std::ostream &s) {
  s << "Color: " << color << "UNKOWN area: " << this->getArea() << "\n";
}
  


#include "Shape.h"

Shape::Shape() {

}

Shape::~Shape() {
  std::cout << "Shape Destructor\n";
  std::cout << "Shape Destructor\n";
  std::cout << "Shape Destructor\n";
}

void
Shape::PrintArea(std::ostream &s) {
  s << "UNKOWN area: " << this->GetArea() << "\n";
}
  


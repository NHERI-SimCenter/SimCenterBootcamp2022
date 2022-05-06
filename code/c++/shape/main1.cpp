#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"

int main(int argc, char **argv) {
  Circle s1(2.0);
  Shape *s2 = new Rectangle(1.0, 2.0);
  Shape *s3 = new Rectangle(3.0,2.0);
  Shape *s4 = new Square(3.0);

  s1.PrintArea(std::cout);
  s2->PrintArea(std::cout);
  s3->PrintArea(std::cout);
  s4->PrintArea(std::cout);

  return 0;
}



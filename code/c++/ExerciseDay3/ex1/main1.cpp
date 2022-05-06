#include "Rectangle.h"
#include "Ellipse.h"

int main(int argc, char **argv) {
  Rectangle s1(1.0, 2.0, "red");
  ColoredShape *s2 = new Rectangle(3.0, 1.0, "blue");  
  ColoredShape *s3 = new Ellipse(3.0,2.0,"purple");
  //  Shape *s4 = new Square(3.0, "pink");

  s1.printArea(std::cout);
  s2->printArea(std::cout);
  s3->printArea(std::cout);
  //  s4->printArea(std::cout);

  delete s2;
  delete s3;
  return 0;
}



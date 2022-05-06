#include "Rectangle.h"
#include "Circle.h"

int main(int argc, char **argv) {
  Circle s1(2.0, "red");
  ColoredShape *s2 = new Rectangle(1.0, 2.0, "blue");
  ColoredShape *s3 = new Rectangle(3.0,2.0, "green");

  s1.printArea(std::cout);
  s2->printArea(std::cout);
  s3->printArea(std::cout);

  delete s2;
  delete s3;
  return 0;
}



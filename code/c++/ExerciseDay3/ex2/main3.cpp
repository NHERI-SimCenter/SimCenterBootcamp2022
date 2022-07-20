#include "Rectangle.h"
#include "Circle.h"

#include <list>

int main(int argc, char **argv) {
  Circle s1(2.0, "red");
  ColoredShape *s2 = new Rectangle(1.0, 2.0, "blue");
  ColoredShape *s3 = new Rectangle(3.0,2.0, "green");

  std::list<ColoredShape*> theShapes;

  theShapes.push_front(&s1);
  theShapes.push_front(s2);
  theShapes.push_front(s3);

  std::list<ColoredShape *>::iterator it;  
  for (it = theShapes.begin(); it != theShapes.end(); it++) {
    (*it)->printArea(std::cout);
  }

  delete s2;
  delete s3;
  return 0;
}



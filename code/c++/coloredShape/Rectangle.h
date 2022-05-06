#ifndef _RECTANGLE
#define _RECTANGLE

#include "ColoredShape.h"

class Rectangle: public ColoredShape {
 public:
  Rectangle(double w, double h, string color);
  ~Rectangle();
  double getArea(void);
  void printArea(std::ostream &s);  

 protected:

 private:
  double width, height;
  static int numRect;
};

#endif // _RECTANGLE

  

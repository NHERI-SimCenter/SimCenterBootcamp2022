#ifndef _RECTANGLE
#define _RECTANGLE

#include "Shape.h"

class Rectangle: public Shape {
 public:
  Rectangle(double w, double h);
  ~Rectangle();
  double GetArea(void);
  void PrintArea(std::ostream &s);  

 protected:

 private:
  double width, height;
  static int numRect;
};

#endif // _RECTANGLE

  

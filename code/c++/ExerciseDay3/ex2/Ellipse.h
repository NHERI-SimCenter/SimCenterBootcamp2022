#ifndef _ELLIPSE_H
#define _ELLIPSE_H

#include "ColoredShape.h"

class Ellipse: public ColoredShape {
 public:
  Ellipse(double a, double b, string color);
  ~Ellipse();
  double getArea(void);
  void printArea(std::ostream &s);  

 protected:

 private:
  double ax1;
  double ax2;
  double getPI(void);
};

#endif // _ELLIPSE_H

  

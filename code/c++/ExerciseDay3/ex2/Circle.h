#ifndef _CIRCLE
#define _CIRCLE

#include "ColoredShape.h"

class Circle: public ColoredShape {
 public:
  Circle(double r, string color);
  ~Circle();
  double getArea(void);

 protected:

 private:
  double r;
  double getPI(void);
};

#endif // _CIRCLE

  

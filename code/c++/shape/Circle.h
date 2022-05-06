#ifndef _CIRCLE
#define _CIRCLE

#include "Shape.h"

class Circle: public Shape {
 public:
  Circle(double d);
  ~Circle();
  double GetArea(void);

 private:
  double diameter;
  double GetPI(void);
};

#endif // _CIRCLE
  

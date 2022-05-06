#ifndef _SQUARE
#define _SQUARE

#include "Shape.h"

class Square: public Shape {
 public:
  Square(double w);
  ~Square();
  double GetArea(void);
  void PrintArea(std::ostream &s);  

 protected:

 private:
  double width;
  static int numSquare;
};

#endif // _SQUARE

  

#ifndef _COLORED_SHAPE
#define _COLORED_SHAPE

#include <iostream>
#include <string>
using std::string;

class ColoredShape {
 public:
  ColoredShape(string color);
  virtual ~ColoredShape();

  const string &getColor();
  virtual double getArea(void) =0;
  virtual void printArea(std::ostream &s);
  
private:
  string color;
};

#endif // _COLORED_SHAPE



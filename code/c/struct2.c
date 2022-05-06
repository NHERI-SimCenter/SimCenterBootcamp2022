#include <stdio.h>

typedef	float numType;

typedef struct point {
  numType x;
  numType y;
} Point;



int main(int argc, char **argv) {

  numType value = 20.;
  
  Point p1 = {1.0, 50};
  Point p2;
  p2.x = 100 + p1.x;
  p2.y = value;

  printf(" Point1: x %10f y%10f\n", p1.x, p1.y);
  printf(" Point2: x %10f y%10f\n", p2.x, p2.y);  	 
}

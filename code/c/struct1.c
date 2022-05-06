#include <stdio.h>

struct point {
  float x;
  float y;
};

int main(int argc, char **argv) {
  struct point p1 = {1.0, 50};
  struct point p2;
  p2.x = 100 + p1.x;
  p2.y = 50;

  printf(" Point1: x %10f y%10f\n", p1.x, p1.y);
  printf(" Point2: x %10f y%10f\n", p2.x, p2.y);  	 
}

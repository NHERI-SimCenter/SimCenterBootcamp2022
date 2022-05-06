#include <iostream>

void sum1(int a, int b, int *c);
void sum2(int a, int b, int &c);

int main(int argc, char **argv) {
  int x = 10;
  int y = 20;
  int z;
  sum1(x,y, &z);
  std::cout << x << " + " << y << " = " << z << "\n";

  x=20;
  sum2(x, y, z);
  std::cout << x << " + " << y << " = " << z << "\n";  
}
// c by value
void sum1(int a, int b, int *c) {
  *c = a+b;
}

// c by ref
void sum2(int a, int b, int &c) {
  c = a + b;
}

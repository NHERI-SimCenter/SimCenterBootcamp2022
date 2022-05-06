#ifndef _NODE
#define _NODE 

#include <iostream>

class Node {
 public:
  Node(int tag, double crd1, double crd2);
  int GetTag(void); 
  const double *GetCoord();
  const double *GetDisp();
  void Print(ostream &s);
 private:
  int tag;
  double coord[2];
  double disp[3];
};

#endif

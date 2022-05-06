#include "Node.h"

Node::Node(int id, double x, double y)
  :tag(id)
{
  coord[0] = x;
  coord[1] = y;
  disp[0] = 0.;
  disp[1] = 0.;
  disp[2] = 0.;
}

int
Node::GetTag(void) {
  return tag;
}

const double *
Node::GetCoord() {
  return coord;
}

const double *
Node::GetDisp() {
  return disp;
}

void 
Node::Print(ostream &s){
  s << "Node : " << tag;
  s << " Crds: " << coord[0] << " " << coord[1];
  s << " Disp: " << disp[0] << " " <<  disp[1] << " " <<  disp[2] << "\n";;
}


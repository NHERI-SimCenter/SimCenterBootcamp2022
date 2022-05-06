#include <stdio.h>
struct node {
  int tag;
  double coord[2];
  double disp[3];
};

void nodePrint(struct node *);

int main(int argc, char **argv) {
  struct node n1;
  struct node n2;

  n1.tag = 1;
  n1.coord[0] = 0.0;
  n1.coord[0] = 1.0;

  n2.tag = 2;
  n2.coord[0] = n1.coord[0];
  n2.coord[0] = 2.0;

  nodePrint(&n1);
  nodePrint(&n2);
}

void nodePrint(struct node *theNode){
  printf("Node : %d ", theNode->tag);
  printf("Crds: %f %f ", theNode->coord[0], theNode->coord[1]);
  printf("Disp: %f %f %f \n", theNode->disp[0], theNode->disp[1], theNode->disp[2]);
}

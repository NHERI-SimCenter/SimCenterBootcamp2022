#include <stdio.h>
typedef struct node {
  int tag;
  double coord[2];
  double disp[3];
} Node;

void nodePrint(Node *);
void nodeSetup(Node *, int tag, double crd1, double crd2);

int main(int argc, char **argv) {
  Node n1;
  Node n2;

  nodeSetup(&n1, 1, 0., 1.);
  nodeSetup(&n2, 2, 0., 2.); 

  nodePrint(&n1);
  nodePrint(&n2);
}

void nodePrint(Node *theNode){
  printf("Node : %d ", theNode->tag);
  printf("Crds: %f %f ", theNode->coord[0], theNode->coord[1]);
  printf("Disp: %f %f %f \n", theNode->disp[0], theNode->disp[1], theNode->disp[2]);
}

void nodeSetup(Node *theNode, int tag, double crd1, double crd2) {
  theNode->tag = tag;
  theNode->coord[0] = crd1;
  theNode->coord[1] = crd2;
}

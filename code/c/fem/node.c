#include <stdio.h>
#include "node.h"

void nodePrint(Node *theNode){
  printf("Node : %d ", theNode->tag);
  printf("Crds: %f %f ", theNode->coord[0], theNode->coord[1]);
  printf("Disp: %f %f %f \n", theNode->disp[0], theNode->disp[1], theNode->disp[2]);
}

void nodeSetup(Node *theNode, int tag, double crd1, double crd2) {
  theNode->tag = tag;
  theNode->coord[0] = crd1;
  theNode->coord[1] = crd2;
  theNode->next = NULL;
}

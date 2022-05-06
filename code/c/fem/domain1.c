#include <stdio.h>
#include <stdlib.h>
#include "domain1.h"
#include "node.h"

void domainPrint(Domain *theDomain) {
  printf("The Nodes:\n");
  domainPrintNodes(theDomain);
}


void domainAddNode(Domain *theDomain, int tag, double crd1, double crd2) {

  // create the new node
  Node *theNextNode = (Node *)malloc(sizeof(Node));
  nodeSetup(theNextNode, tag, crd1, crd2);

  // get size of current array and max size
  int numNodes = theDomain->numNodes;
  int maxNumNodes = theDomain->maxNumNodes;

  // if current size = maxSize, we need to increase storage capacity
  if (numNodes == maxNumNodes) {
    Node **theNextNodes = (Node **)malloc((maxNumNodes+10)*sizeof(Node*));
    for (int i=0; i<numNodes; i++) 
      theNextNodes[i] = theDomain->theNodes[i];
    for (int i=numNodes; i<maxNumNodes+10; i++)
      theNextNodes[i] = 0;
    if (maxNumNodes != 0)
      free(theDomain->theNodes);
    theDomain->maxNumNodes = maxNumNodes+10;
    theDomain->theNodes= theNextNodes;
  }

  // add the node
  theDomain->theNodes[numNodes] = theNextNode;
  theDomain->numNodes++;
}

void domainPrintNodes(Domain *theDomain) {
  int numNodes = theDomain->numNodes;
  for (int i=0; i<theDomain->numNodes; i++)
    nodePrint(theDomain->theNodes[i]);
}

Node *domainGetNode(Domain *theDomain, int nodeTag) {
  int numNodes = theDomain->numNodes;
  for (int i=0; i<numNodes; i++) {
    Node *theCurrentNode = theDomain->theNodes[i];
    if (theCurrentNode->tag == nodeTag) {
      return theCurrentNode;
    } 
  }
  return NULL;
}

#include <iostream>
#include "Domain.h"
#include "Node.h"

Domain::Domain() {
  theNodes.empty();
}

Domain::~Domain() {
  theNodes.empty();
}

Node *
Domain::getNode(int tag){
  Node *res = NULL;

  // create iterator & iterate over all elements
  std::map<int, Node *>::iterator it = theNodes.find(tag);

  if (it != theNodes.end()) {
      Node *theNode = it->second;
      return theNode;
  }
  return res;
}

void 
Domain::Print(ostream &s){
  // create iterator & iterate over all elements
  std::map<int, Node *>::iterator it = theNodes.begin();

  while (it != theNodes.end()) {
      Node *theNode = it->second;
      theNode->Print(s);
      it++;

    }
}
//function.insert(std::map<int, int>::value_type(0, 42));
int
Domain::AddNode(Node *theNode) {
  if (theNodes.insert (std::map<int, Node *>::value_type(theNode->GetTag(), theNode)).second == false)
    return false;
  else
    return true;
}


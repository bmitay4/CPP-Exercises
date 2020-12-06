#ifndef _FamilyTree_H
#define _FamilyTree_H

#include <iostream>

#include "Node.hpp"

namespace family {
class Tree {
   private:
    Node* itsRoot;

   public:
    //Constructor
    Tree(string name);

    //Destructor
    ~Tree();

    //Exercise methods
    string find(string);
    string relation(string);
    Tree& addFather(string, string);
    Tree& addMother(string, string);
    void display();
    void remove(string);

    //Addons methods
    Node* getNodeByName(Node*, string);
    Node* getNodeByRelation(Node*, string);
    bool isEqual(string, string);
    bool isExist(Node*);
    void destroyTreeByNode(Node*);
    void disconnectParent(Node*);
    void printPostOrder(Node*, int);
    void print(string);
};
}  // namespace family
#endif
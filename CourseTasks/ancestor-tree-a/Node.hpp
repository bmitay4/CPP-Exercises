#ifndef _NODE_H
#define _NODE_H

#include <iostream>

using namespace std;

class Node {
   private:
    string itsValue, itsRelation;
    Node *itsParent, *itsLeft, *itsRight;
    const int itsDistance = 1;

   public:
    //Constructor
    Node(string, Node*, string);  //Initial constructor: value, parent node and its relation

    //Destructor
    ~Node();

    //Getters
    Node* getParent();       //Return parent node
    Node* getLeft();         //Return left node
    Node* getRight();        //Return right node
    string getValue();       //Return node's value (its name)
    string getRelation();    //Return node's relation
    int getDistance(Node*);  //Return node's distance from root

    //Setters
    void setLeft(Node*);   //Set left node
    void setRight(Node*);  //Set right node
    void setRelation();    //Set node's relation
};

#endif
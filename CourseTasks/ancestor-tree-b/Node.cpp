//BY ITBM

#include "Node.hpp"

//Constructor
Node::Node(string value, Node* parent, string relation) {
    itsValue = value;
    itsParent = parent;
    itsRelation = relation;
    itsLeft = itsRight = nullptr;
}

//Destructor
Node::~Node() {
    cout << "Node destructor called: " << getValue() << " is deleted" << endl;
    itsLeft = itsRight = nullptr;
}

//Getters
Node* Node::getParent() {
    return itsParent;
}
Node* Node::getLeft() {
    return itsLeft;
}
Node* Node::getRight() {
    return itsRight;
}
string Node::getValue() {
    return itsValue;
}
string Node::getRelation() {
    return itsRelation;
}
int Node::getDistance(Node* node) {
    if (node == NULL) return 0;
    return getDistance(node->getParent()) + 1;
}

//Setters
void Node::setLeft(Node* node) {
    itsLeft = node;
}
void Node::setRight(Node* node) {
    itsRight = node;
}
void Node::setRelation() {
    int relationLevel = getDistance(this) - 1;
    if (relationLevel == 2)
        itsRelation = "grand" + itsRelation;
    else if (relationLevel > 2) {
        string tempStr;
        while (relationLevel > 0) {
            tempStr += +"great-";
            relationLevel -= 3;
        }
        itsRelation = tempStr + "grand" + itsRelation;
    }
}
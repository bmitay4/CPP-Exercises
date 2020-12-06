#include "FamilyTree.hpp"

#include <iomanip>

#include "myException.hpp"

//Constructor
family::Tree::Tree(string name) {
    itsRoot = new Node(name, nullptr, "me");
}
//Destructor
family::Tree::~Tree() {
    destroyTreeByNode(itsRoot);
}
void family::Tree::destroyTreeByNode(Node* n) {
    if (n != nullptr) {
        destroyTreeByNode(n->getLeft());
        destroyTreeByNode(n->getRight());
        delete n;
    }
}
string family::Tree::find(string givenRelation) {
    Node* n = getNodeByRelation(itsRoot, givenRelation);
    if (n != nullptr) return n->getValue();
    throw Exception("The tree cannot handle the '" + givenRelation + "' relation");
}
string family::Tree::relation(string givenName) {
    Node* n = getNodeByName(itsRoot, givenName);
    if (n != nullptr) return n->getRelation();
    return "unrelated";
}
Node* family::Tree::getNodeByName(Node* node, string currentValue) {
    if (node != nullptr) {
        if (isEqual(node->getValue(), currentValue))
            return node;
        else {
            Node* n = getNodeByName(node->getLeft(), currentValue);
            if (n == nullptr)
                n = getNodeByName(node->getRight(), currentValue);
            return n;
        }
    } else
        return nullptr;
}
Node* family::Tree::getNodeByRelation(Node* node, string currentValue) {
    if (node != nullptr) {
        if (isEqual(node->getRelation(), currentValue))
            return node;
        else {
            Node* n = getNodeByRelation(node->getLeft(), currentValue);
            if (n == nullptr)
                n = getNodeByRelation(node->getRight(), currentValue);
            return n;
        }
    } else
        return nullptr;
}
bool family::Tree::isEqual(string str1, string str2) {
    if (str1.compare(str2) == 0) return true;
    return false;
}
bool family::Tree::isExist(Node* n) {
    if (n == nullptr) return false;
    return true;
}
family::Tree& family::Tree::addMother(string targetNode, string addedNode) {
    Node* node = getNodeByName(itsRoot, targetNode);
    if (node == nullptr)
        throw Exception("Error,'" + targetNode + "' was not found in the tree");
    else if (isExist(node->getLeft()))
        throw Exception("Error,'" + targetNode + "' already has a mother");
    else {
        Node* n = new Node(addedNode, node, "mother");
        n->setRelation();
        node->setLeft(n);
    }
    return *this;
}
family::Tree& family::Tree::addFather(string targetNode, string addedNode) {
    Node* node = getNodeByName(itsRoot, targetNode);
    if (node == nullptr)
        throw Exception("Error,'" + targetNode + "' was not found in the tree");
    else if (isExist(node->getRight()))
        throw Exception("Error,'" + targetNode + "' already has a father");
    else {
        Node* n = new Node(addedNode, node, "father");
        n->setRelation();
        node->setRight(n);
    }
    return *this;
}
void family::Tree::remove(string givenName) {
    Node* n = getNodeByName(itsRoot, givenName);
    if (n == nullptr)
        throw Exception("Error,'" + givenName + "' was not found in the tree");
    else if (n == itsRoot)
        throw Exception("Error, tree root cannot be deleted");
    else {
        disconnectParent(n);
        destroyTreeByNode(n);
    }
}
void family::Tree::disconnectParent(Node* n) {
    Node* leftParent = n->getParent()->getLeft();
    Node* rightParent = n->getParent()->getRight();
    if (leftParent == n) n->getParent()->setLeft(nullptr);
    if (rightParent == n) n->getParent()->setRight(nullptr);
}
void family::Tree::display() {
    printPostOrder(itsRoot, 0);
}
void family::Tree::printPostOrder(Node* n, int indent = 0) {
    if (n != nullptr) {
        if (n->getRight()) printPostOrder(n->getRight(), indent + 4);
        if (indent) cout << setw(indent) << ' ';
        if (n->getRight()) cout << " /\n"
                                << setw(indent) << ' ';
        print(n->getValue() + "[" + n->getRelation() + "]");
        if (n->getLeft()) {
            cout << setw(indent) << ' ' << " \\\n";
            printPostOrder(n->getLeft(), indent + 4);
        }
    }
}
void family::Tree::print(string value) {
    cout << value << endl;
}
#ifndef LAB8_NODE_H
#define LAB8_NODE_H
#include "NodeInterface.h"
#include <iostream>

class Node: public NodeInterface {
public:
    Node(int data);
    ~Node() {};
    int getData() const;
    NodeInterface * getLeftChild() const;
    NodeInterface * getRightChild() const;
    int getHeight();

    Node *& getLeft();
    Node *& getRight ();
    void setData(int data);
    int balance();

protected:
    int data;
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;
};


#endif //LAB8_NODE_H
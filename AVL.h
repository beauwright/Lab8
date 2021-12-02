#ifndef LAB8_AVL_H
#define LAB8_AVL_H

#include "AVLInterface.h"
#include "Node.h"

#include <iostream>

class AVL: public AVLInterface {
public:
    AVL() {};
    ~AVL();
    NodeInterface * getRootNode() const;
    bool add(int data);
    bool remove(int data);
    void clear();


private:
    void recursiveClear(Node *node);
    bool add(Node*& currentNode, int data);
    void rotateRight(Node *&root);
    void rotateLeft(Node *&root);
    void balanceLeft(Node*& currentNode);
    void balanceRight(Node*& currentNode);
    void balanceRemove(Node*& currentNode);
    bool remove(Node*& topNode, int data);

protected:
    Node *root = nullptr;
};

#endif //LAB8_AVL_H
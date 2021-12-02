#include "AVL.h"

AVL::~AVL() {
    AVL::clear();
}

NodeInterface * AVL::getRootNode() const {
    return this->root;
}

bool AVL::add(int data){
    //cout << "reached add, value is " << data << endl;
    return add(root, data);
}

bool AVL::add(Node*& node, int data) {
    //cout << "reached addHelper" << endl;
    if(node == nullptr) {
        node = new Node(data);
        node->getLeft() = nullptr;
        node->getRight() = nullptr;
        return true;
    }
    else if(data == node->getData()) {
        return false;
    }
    else if(data < node->getData()) {
        if(add(node->getLeft(), data) == true) {
            if(node->balance() > 1){
                balanceLeft(node);
            }
            else if(node->balance() < -1) {
                balanceRight(node);
            }
            return true;
        }
        return false;
    }
    else if(data > node->getData()) {
        if(add(node->getRight(), data) == true){
            if(node->balance() > 1) {
                balanceLeft(node);
            }
            else if(node->balance() < -1) {
                balanceRight(node);
            }
            return true;
        }
        return false;
    }
    if(node->balance() > 1) {
        balanceLeft(node);
    }
    else if(node->balance() < -1) {
        balanceRight(node);
    }
    return false;
}


bool AVL::remove(int data){
    return remove(root, data);
}


void AVL::clear() {
    recursiveClear(this->root);
    this->root = nullptr;
}

void AVL::recursiveClear(Node *node) {
    if (node != nullptr) {
        recursiveClear(node->getLeft());
        recursiveClear(node->getRight());
        delete node;
    }
}

void AVL::rotateRight(Node *&rRRoot) {
    Node * temp = rRRoot->getLeft();
    rRRoot->getLeft() = temp->getRight();
    temp->getRight() = rRRoot;
    rRRoot = temp;
}

void AVL::rotateLeft(Node *&rLRoot) {
    Node * temp = rLRoot->getRight();
    rLRoot->getRight() = temp->getLeft();
    temp->getLeft() = rLRoot;
    rLRoot = temp;
}

void AVL::balanceLeft(Node*& currentNode) {
    if(currentNode == nullptr){
        return;
    }
    if(currentNode->getRight()->balance() <= -1){
        rotateRight(currentNode->getRight());
    }
    rotateLeft(currentNode);
}

void AVL::balanceRight(Node*& currentNode){
    if(currentNode == nullptr) {
        return;
    }
    if(currentNode->getLeft()->balance() >= 1){
        rotateLeft(currentNode->getLeft());
    }
    rotateRight(currentNode);
}

void AVL::balanceRemove(Node*& currentNode){
    if(currentNode == nullptr) {
        return;
    }
    if(currentNode->balance() > 1) {
        balanceLeft(currentNode);
        int tempReadout = currentNode->getData();
    }
    if(currentNode->balance() < -1) {
        balanceRight(currentNode);
        int tempReadout = currentNode->getData();
    }
    balanceRemove(currentNode->getLeft());
    balanceRemove(currentNode->getRight());
}

bool AVL::remove(Node*& topNode, int data){
    if(topNode == nullptr) {
        balanceRemove(root);
        return false;
    }

    Node* tempNode = topNode;
    Node* tempLeft = topNode->getLeft();

    if(data < topNode->getData()){
        balanceRemove(root);
        return remove(topNode->getLeft(), data);
    }
    if(data > topNode->getData()){
        balanceRemove(root);
        return remove(topNode->getRight(), data);
    }

    if(topNode->getLeft() == nullptr && topNode->getRight() == nullptr){
        delete topNode;
        topNode = nullptr;
        balanceRemove(root);
        return true;
    }
    if(topNode->getLeft() == nullptr || topNode->getRight() == nullptr) {
        tempLeft = topNode->getLeft();

        if(tempLeft == nullptr){
            tempLeft = topNode->getRight();
        }

        delete topNode;
        topNode = tempLeft;
        balanceRemove(root);
        return true;
    }
    while(tempLeft->getRight() != nullptr){
        tempNode = tempLeft;
        tempLeft = tempLeft->getRight();
    }
    if(topNode->getData() != tempNode->getData()){
        tempNode->getRight() = tempLeft->getLeft();
    }
    else {
        tempNode->getLeft() = tempLeft->getLeft();
    }
    topNode->setData(tempLeft->getData());
    delete tempLeft;
    balanceRemove(root);
    return true;
}
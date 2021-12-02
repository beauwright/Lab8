#include "Node.h"
Node::Node(int data) {
    setData(data);
}

int Node::getData() const {
    return data;
}

NodeInterface * Node::getLeftChild() const {
    return leftChild;
}

NodeInterface * Node::getRightChild() const {
    return rightChild;
}

Node *& Node::getLeft() {
    return leftChild;
}

Node *& Node::getRight() {
    return rightChild;
}

void Node::setData(int data) {
    this->data = data;
}

int Node::getHeight() {
    int leftVal = 0;
    int rightVal = 0;
    int returnVal;

    if(rightChild != nullptr) {
        rightVal = rightChild->getHeight();
    }
    if(leftChild != nullptr) {
        leftVal = leftChild->getHeight();
    }
    if(leftVal > rightVal) {
        returnVal = leftVal + 1;
        return returnVal;
    }
    else {
        returnVal = rightVal + 1;
        return returnVal;
    }
}

int Node::balance(){
    int leftVal;
    int rightVal;
    int returnVal;

    if(leftChild != nullptr) {
        leftVal = leftChild->getHeight();
    } else leftVal = 0;

    if(rightChild != nullptr) {
        rightVal = rightChild->getHeight();
    }
    else rightVal = 0;
    returnVal = rightVal - leftVal;
    return returnVal;
}
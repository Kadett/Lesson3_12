#pragma once

#include <iostream>

class BinTree {
    struct Node {
        int key;
        Node *left;
        Node *right;
    };
    Node *tr;
    int size;

    void printTree(Node *root);
    Node* getSuccessor(Node *node);
    int isBalance(Node *node);
    bool search(Node *node, int val);



public:
    BinTree() : size(0), tr(nullptr) {}
    void insert(int data);
    bool del(int key);
    void printTree();
    int getSize();
    bool isBalance();
    bool search(int val);
};


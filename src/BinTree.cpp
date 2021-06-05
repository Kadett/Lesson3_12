#include "BinTree.h"
#include <cmath>

void BinTree::insert(int data) {
    {
        Node *newNode = new Node();
        newNode->key = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        Node *current = tr;
        Node *parent = tr;
        if (tr == nullptr) {
            tr = newNode;
            size++;
        } else {
            while (current->key != data) {
                parent = current;
                if (current->key > data) {
                    current = current->left;
                    if (current == nullptr) {
                        parent->left = newNode;
                        size++;
                        break;
                    }
                } else {
                    current = current->right;
                    if (current == nullptr) {
                        parent->right = newNode;
                        size++;
                        break;
                    }
                }
            }
        }
    }
}


void BinTree::printTree(BinTree::Node *root) {
    if (root) {
        std::cout << root->key;
        if (root->left || root->right) {
            std::cout << "(";
            if (root->left) printTree(root->left);
            else std::cout << "NULL";
            std::cout << ",";
            if (root->right) printTree(root->right);
            else std::cout << "NULL";
            std::cout << ")";
        }
    }

}

void BinTree::printTree() {
    printTree(tr);
}

bool BinTree::del(int key) {
    Node *current = tr;
    Node *parent = tr;
    bool isLeftChild = true;

    while (current->key != key) {
        parent = current;
        if (key < current->key) {
            current = current->left;
            isLeftChild = true;
        } else {
            current = current->right;
            isLeftChild = false;
        }
        if (current == nullptr) return false;
    }

    if (current->left == nullptr && current->right == nullptr) {
        if (current == tr) {
            delete tr;
            tr = nullptr;
        } else if (isLeftChild) {
            delete parent->left;
            parent->left = nullptr;
        } else {
            delete parent->right;
            parent->right = nullptr;
        }
    } else if (current->right == nullptr) {
        if (isLeftChild) {
            parent->left = current->left;
            delete current;
        } else {
            parent->right = current->left;
            delete current;
        }
    } else if (current->left == nullptr) {
        if (isLeftChild) {
            parent->left = current->right;
            delete current;
        } else {
            parent->right = current->right;
            delete current;
        }
    } else {
        Node *successor = getSuccessor(current);
        if (current == tr) {
            tr = successor;
        } else if (isLeftChild) {
            parent->left = successor;
        } else {
            parent->right = successor;
        }
        successor->left = current->left;
        delete current;
    }
    return true;

}

BinTree::Node *BinTree::getSuccessor(BinTree::Node *node) {
    Node *current = node->right;
    Node *parent = node;
    Node *s = node;

    while (current != nullptr) {
        parent = s;
        s = current;
        current = current->left;
    }
    if (s != node->right) {
        parent->left = s->right;
        s->right = node->right;
    }
    return s;
}

bool BinTree::isBalance() {
    return isBalance(this->tr) != -1;

}

int BinTree::isBalance(BinTree::Node *node) {
    if (node == nullptr) return 0;
    int left = isBalance(node->left);
    if (left == -1)
        return -1;

    int right = isBalance(node->right);
    if (right == -1)
        return -1;

    int hd = left - right;
    if (abs(hd) > 1)
        return -1;
    else return (1 + std::max(left, right));


}

int BinTree::getSize() {
    return size;
}

bool BinTree::search(int val) {
    return search(tr, val);
}

bool BinTree::search(BinTree::Node *node, int val) {
    bool res = false;
    if(node == nullptr) return false;
    if (node->key == val) return true;
    else {
        if(val <= node->key) res = search(node->left, val);
        else res = search(node->right, val);
    }
    return res;
}










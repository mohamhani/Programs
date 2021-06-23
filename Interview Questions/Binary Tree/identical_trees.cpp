#include <iostream>

using namespace std;

// Data structure to store a binary tree node
struct Node {
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->right = this->left = nullptr;
    }
};

/*
* Recursive function to check if two given
* binary trees are identical or not
*/
int isIdentical(Node *x, Node *y) {
    // If both trees are empty, return true
    if(x == nullptr && y == nullptr) {
        return 1;
    }

    return (x && y) && (x->data == y->data) &&
            isIdentical(x->left, y->left) &&
            isIdentical(x->right, y->right);
}

int main() {

    // construct the first tree
    Node *x = new Node(15);
    x->left = new Node(10);
    x->right = new Node(20);
    x->left->left = new Node(8);
    x->left->right = new Node(12);
    x->right->left = new Node(16);
    x->right->right = new Node(25);
 
    // construct the second tree
    Node *y = new Node(15);
    y->left = new Node(10);
    y->right = new Node(20);
    y->left->left = new Node(8);
    y->left->right = new Node(12);
    y->right->left = new Node(16);
    y->right->right = new Node(250);
 
    if (isIdentical(x, y)) {
        cout << "The given binary trees are identical";
    }
    else {
        cout << "The given binary trees are not identical";
    }
 
    return 0;
}
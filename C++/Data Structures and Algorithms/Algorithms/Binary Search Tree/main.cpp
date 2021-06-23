#include <iostream>

using std::cout;
using std::endl;

class BST {
    int data;
    BST *left, *right;

    public:
    // Default constructor
    BST();

    // Parameterized constructor
    BST(int value);

    // Insert method
    BST* insert(BST *root, int value);

    // Delete a node
    BST* deleteNode(BST *root, int value);

    // Given a non-empty binary search tree, return the min value in that tree
    BST* minValue(BST *root);

    // Inorder traversal
    void inorder(BST *root);
};

// Default constructor definition
BST::BST() : data(0), left(NULL), right(NULL){}

// Parameterized constructor definition
BST::BST(int value) {
    data = value;
    left = right = NULL;
}

// Insert data 
BST* BST::insert(BST *root, int value) {
    if(!root) {
        return new BST(value);
    }

    // Insert data
    if(value > root->data) {
        root->right = insert(root->right, value);
    }
    else {
        root->left = insert(root->left, value);
    }

    return root;
}

BST* BST::deleteNode(BST *root, int value) {
    if(!root) {
        return root;
    }

    if(value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if(value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        if(root->left == NULL) {
            BST *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL) {
            BST *temp = root->left;
            delete root;
            return temp;
        }

        BST *temp = minValue(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

BST* BST::minValue(BST *root) {
    while(root->left != NULL) {
        root = root->left;
    }

    return root;
}

void BST::inorder(BST *root) {
    if(!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}


int main(int argc, const char* argv[]) {

    BST b, *root = NULL; 
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);
  
    b.inorder(root);

    b.deleteNode(root, 70);

    cout << endl;
    b.inorder(root);

    b.insert(root, 70);

    cout << endl;
    b.inorder(root);



    return 0;
}

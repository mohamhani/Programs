#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;

BST::BST() {
    root = NULL;
}

BST::nodePtr BST::createLeaf(int data) {
    
    nodePtr n = new node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

BST::~BST() {
    removeSubtree(root);
}

// This is post order traversial
void BST::removeSubtree(nodePtr ptr) {
    if(ptr != NULL) {
        if(ptr->left != NULL){
            removeSubtree(ptr->left);
        }
        if(ptr->right != NULL){
            removeSubtree(ptr->right);
        }
        cout << "Deleting the node containing data " << ptr->data << endl;
        delete ptr;
    }   
}

void BST::addLeaf(int data) {
    addLeafPrivate(data, root);
}

void BST::addLeafPrivate(int data, nodePtr ptr) {
    if(root == NULL) {
        root = createLeaf(data);
    }
    else if(data < ptr->data) {
        if(ptr->left != NULL) {
            addLeafPrivate(data, ptr->left);
        }
        else {
            ptr->left = createLeaf(data);
        }
    }
    else if(data > ptr->data) {
        if(ptr->right != NULL) {
            addLeafPrivate(data, ptr->right);
        }
        else {
            ptr->right = createLeaf(data);
        }
    }
    else {
        cout << "The data: " << " has already been added to the tree" << endl;
    }
}

void BST::printInOrder() {
    printInOrderPrivate(root);
}

void BST::printInOrderPrivate(nodePtr ptr) {
    if(root != NULL) {
        if(ptr->left != NULL) {
            printInOrderPrivate(ptr->left);
        }
        cout << ptr->data << " ";
        if(ptr->right != NULL) {
            printInOrderPrivate(ptr->right);
        }
    }
    else {
        cout << "The tree is empty" << endl;
    }
}

BST::nodePtr BST::returnNode(int data, nodePtr ptr) {
    if(ptr != NULL) {
        if(ptr->data == data) {
            return ptr;
        }
        else {
            if(data < ptr->data) {
                return returnNode(data, ptr->left);
            }
            else {
                return returnNode(data, ptr->right);
            }
        }
    }
    else {
        return NULL;
    }
}

int BST::returnRootData() {
    if(root != NULL) {
        return root->data;
    }
    else {
        return -1;
    }
}

void BST::PrintChildren(int data) {
    nodePtr ptr = returnNode(data, root); 

    if(ptr != NULL) {
        cout << "Parent Node = " << ptr->data << endl;

        ptr->left == NULL ? 
        cout << "Left Chile = NULL" << endl : 
        cout << "Left Child = " << ptr->left->data << endl;

        ptr->right == NULL ? 
        cout << "Right Chile = NULL" << endl : 
        cout << "Right Child = " << ptr->right->data << endl;
    }
    else {
        cout << "Data " << data << " is not in the tree" << endl;
    }
}

int BST::findSmallest() {

    return findSmallestPrivate(root);
    
}


int BST::findSmallestPrivate(nodePtr ptr) {

    if(root == NULL) {
        cout << "The tree is empty" << endl;
        return -1;
    }
    else {
        if(ptr->left != NULL) {
            return findSmallestPrivate(ptr->left);
        }
        else {
            return ptr->data;
        }
    }

    return 0;
}

void BST::removeNode(int data) {
    removeNodePrivate(data, root);
}

void BST::removeNodePrivate(int data, nodePtr parent) {

    if(root != NULL) {
        if(root->data == data) {
            removeRootMatch();
        }
        else {
            if(data < parent->data && parent->left != NULL) {
                parent->left->data == data ?
                removeMatch(parent, parent->left, true) :
                removeNodePrivate(data, parent->left);
            }
            else if(data > parent->data && parent->right != NULL) {
                parent->right->data == data ?
                removeMatch(parent, parent->right, false) :
                removeNodePrivate(data, parent->right);
            }
            else {
                cout << "The data " << data << " was not found in the tree" << endl;
            }
        }
    }
    else {
        cout << "The tree is empty" << endl;
    }
}

void BST::removeRootMatch() {
    if(root != NULL) {
        nodePtr delPtr = root;
        int data = root->data;
        int smallestDataInRightSubtree;

        // Case 0 - 0 children
        if(root->left == NULL && root->right == NULL) {
            root = NULL;
            delete delPtr;
        }
        // Case 1 - 1 child
        else if(root->left == NULL && root->right != NULL) {
            root = root->right;
            delPtr->right = NULL;
            delete delPtr;
            cout << "The root node with data " << data << " was deleted. " <<
                    "The new root contains data " << root->data << endl;
        }
        else if(root->left != NULL && root->right == NULL) {
            root = root->left;
            delPtr->left = NULL;
            delete delPtr;
            cout << "The root node with data " << data << " was deleted. " <<
                    "The new root contains data " << root->data << endl;
        }
        // Case 2 - 2 children
        else {
            smallestDataInRightSubtree = findSmallestPrivate(root->right);
            removeNodePrivate(smallestDataInRightSubtree, root);
            root->data = smallestDataInRightSubtree;
            cout << "The root data containing data " << data << 
                    " was overwritten with data " << root->data << endl;
        }

    }
    else {
        cout << "Can not remove root. The tree is empty" << endl;
    }
}

void BST::removeMatch(nodePtr parent, nodePtr match, bool left) {
    if(root != NULL){
        nodePtr delPtr;
        int matchData = match->data;
        int smallestInRightSubTree;

        // Case 0 - 0 Children
        if(match->left == NULL && match->right == NULL) {
            delPtr = match;
            left == true ? parent->left = NULL : parent->right = NULL;
            delete delPtr;
            cout << "The node containing data " << matchData << " was removed" << endl;
        }
        // Case 1 - 1 Child
        else if(match->left == NULL && match->right != NULL) {
            left == true ? parent->left = match->right : parent->right = match->right;
            match->right = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The node containing data " << matchData << " was removed" << endl;
        }
        else if(match->left != NULL && match->right == NULL) {
            left == true ? parent->left = match->left : parent->right = match->left;
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The node containing data " << matchData << " was removed" << endl;
        }
        // Case 2 - 2 Children
        else {
            smallestInRightSubTree = findSmallestPrivate(match->right);
            removeNodePrivate(smallestInRightSubTree, match);
            match->data = smallestInRightSubTree;
        }
    }
    else {
        cout << "Cannot remove match. The tree is empty" << endl;
    }
}
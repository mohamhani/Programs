#include <iostream>
#include <iomanip>
#include <ctime>

using std::cout;
using std::endl;

class AVLTree {
    // A private subclass for the nodes of the tree
    private:
        class Node {
            private:
                int data;
                int height;
                Node *parent;
                Node *rightChild;
                Node *leftChild;

            public:
                Node(int value);
                int getBalance();
                int getHeight();
                int getData();
                Node *getParent();
                Node *getRightChild();
                Node *getLeftChild();
                Node *setRightChild(Node *newRightChild);
                Node *setLeftChild(Node *newLeftChild);
                void removeParent();
                int updateHeight();
                void inorder(Node *n);
        };

        Node *root;

        void balanceAtNode(Node *n);
        Node *findNode(int value);
        void printSubtree(Node *subree, int depth, int offset, bool first);
        void rotateRight(Node *n);
        void rotateLeft(Node *n);
        void setRoot(Node *n);
        int spacing(int offset);

    public:
        AVLTree();
        AVLTree(int value);
        int getHeight();
        bool insert(int value);
        void print();
        bool remove(int value);
};

/**
 * ---------------------------------------------------
 * AVLTree's Node subclass methods
 * ---------------------------------------------------
 * */

AVLTree::Node::Node(int value) {
    data = value;
    height = 0;
    parent = NULL;
    rightChild = NULL;
    leftChild = NULL;
}

void AVLTree::Node::inorder(Node *n) {
    if(n != NULL) {
        inorder(n->getLeftChild());
        cout << n->getData() << ", ";
        inorder(n->getRightChild());
    }
}

/**
 * Calculate the balance point. Negative, when the 
 * right side is deeper. Zero, when both sides are
 * the same. Positive, when the left side is deeper
 **/
int AVLTree::Node::getBalance() {
    int result;

    if(leftChild == NULL) {
        if(rightChild == NULL) {
            result = 0;
        }
        else {
            result = -rightChild->height - 1;
        }
    }
    else if(rightChild == NULL) {
        result = leftChild->height + 1;
    }
    else {
        result = leftChild->height - rightChild->height;
    }

    return result;
}

int AVLTree::Node::getData() {
    return data;
}

int AVLTree::Node::getHeight() {
    return height;
}

AVLTree::Node *AVLTree::Node::getParent() {
    return parent;
}

AVLTree::Node *AVLTree::Node::getRightChild() {
    return rightChild;
}

AVLTree::Node *AVLTree::Node::getLeftChild() {
    return leftChild;
}

void AVLTree::Node::removeParent() {
    parent = NULL;
}

/**
 * very object in C++ has access to its own address through an important pointer called this pointer.
 * */
AVLTree::Node *AVLTree::Node::setRightChild(Node *newRightChild) {
    if(newRightChild != NULL) {
        newRightChild->parent = this;
    }
    rightChild = newRightChild;
    updateHeight();
    return rightChild;
}

AVLTree::Node *AVLTree::Node::setLeftChild(Node *newLeftChild) {
    if(newLeftChild != NULL) {
        newLeftChild->parent = this;
    }
    leftChild = newLeftChild;
    updateHeight();
    return leftChild;
}

int AVLTree::Node::updateHeight() {
    if(leftChild == NULL) {
        if(rightChild == NULL) {
            height = 0;
        }
        else {
            height = rightChild->height + 1;
        }
    }
    else if(rightChild == NULL) {
        height = leftChild->height + 1;
    }
    else if(leftChild->height > rightChild->height) {
        height = leftChild->height + 1;
    }
    else {
        height = rightChild->height + 1;
    }

    return height;
}

/**
 * ---------------------------------------------------
 * AVLTree class methods
 * ---------------------------------------------------
 * */

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::AVLTree(int value) {
    root = new Node(value);
}

AVLTree::Node *AVLTree::findNode(int value) {
    Node *temp = root;
    while(temp != NULL) {
        if(value == temp->getData()) {
            break;
        }
        else if(value < temp->getData()) {
            temp = temp->getLeftChild();
        }
        else {
            temp = temp->getRightChild();
        }
    }

    return temp;
}

void AVLTree::balanceAtNode(Node *n) {
    int bal = n->getBalance();

    // Heavy on the left
    if(bal > 1) {
        if(n->getLeftChild()->getBalance() < 0) {
            rotateLeft(n->getLeftChild());
        }
        rotateRight(n);
    }
    else if(bal < -1) {
        if(n->getRightChild()->getBalance() > 0) {
            rotateRight(n->getRightChild());
        }
        rotateLeft(n);
    }
}

void AVLTree::print() {
    root->inorder(root);
}

int AVLTree::getHeight() {
    return root->getHeight();
}

bool AVLTree::insert(int value) {
    if(root == NULL) {
        root = new Node(value);
    }
    else {
        Node *addedNode = NULL;
        Node *temp = root;
        while(temp != NULL && addedNode == NULL) {
            if(value < temp->getData()) {
                if(temp->getLeftChild() == NULL) {
                    addedNode = temp->setLeftChild(new Node(value));
                }
                else {
                    temp = temp->getLeftChild();
                }
            }
            else if(value > temp->getData()) {
                if(temp->getRightChild() == NULL) {
                    addedNode = temp->setRightChild(new Node(value));
                }
                else {
                    temp = temp->getRightChild();
                }
            }
            else {
                return false;
            }
        }

        temp = addedNode;
        while(temp != NULL) {
            temp->updateHeight();
            balanceAtNode(temp);
            temp = temp->getParent();
        }
    }
    return true;
}

void AVLTree::rotateRight(Node *n) {
    enum{right, left} side;

    Node *p = n->getParent();
    if(p != NULL && p->getLeftChild() == n) {
        side = left;
    }
    else {
        side = right;
    }

    Node *temp = n->getLeftChild();
    n->setLeftChild(temp->getRightChild());
    temp->setRightChild(n);

    if(p == NULL) {
        setRoot(temp);
    }
    else if(side == left) {
        p->setLeftChild(temp);
    }
    else {
        p->setRightChild(temp);
    }
}

void AVLTree::rotateLeft(Node *n) {
    enum{right, left} side;

    Node *p = n->getParent();
    if(p != NULL && p->getLeftChild() == n) {
        side = left;
    }
    else {
        side = right;
    }

    Node *temp = n->getRightChild();
    n->setRightChild(temp->getLeftChild());
    temp->setLeftChild(n);

    if(p == NULL) {
        setRoot(temp);
    }
    else if(side == left) {
        p->setLeftChild(temp);
    }
    else {
        p->setRightChild(temp);
    }
}

void AVLTree::setRoot(Node *n) {
    root = n;
    
    if(root != NULL) {
        root->removeParent();
    }
}

/**
 * AVLTree();
   AVLTree(int value);
   int getHeight();
   bool insert(int value);
   void print();
   bool remove(int value);
 * */

int main() {

    srand(time(0));
    int values[10];

    AVLTree *tree = new AVLTree();

    for(int i = 0; i < 10; i++) {
        while(!tree->insert(values[i] = rand()%100));
        cout << "Adding: " << values[i] << endl;
    }

    tree->print();

    return 0;
}
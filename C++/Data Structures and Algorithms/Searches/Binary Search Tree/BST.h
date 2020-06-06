#ifndef BST_H
#define BST_H

class BST {

    private:

        struct node {
            int data;
            node* left;
            node* right;
        };

        typedef struct node* nodePtr;

        nodePtr root;

        void addLeafPrivate(int data, nodePtr ptr);
        void printInOrderPrivate(nodePtr ptr);
        int findSmallestPrivate(nodePtr ptr);
        void removeNodePrivate(int data, nodePtr parent);
        void removeRootMatch();
        void removeMatch(nodePtr parent, nodePtr match, bool left);
        void removeSubtree(nodePtr ptr);

    public:

        BST();
        ~BST();
        nodePtr createLeaf(int data);
        void addLeaf(int data);
        void printInOrder();
        nodePtr returnNode(int data, nodePtr ptr);
        int returnRootData();
        void PrintChildren(int data);
        int findSmallest();
        void removeNode(int data);

};


#endif
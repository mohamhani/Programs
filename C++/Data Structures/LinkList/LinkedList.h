
#ifndef LIST_H
#define LIST_H

class LinkedList {
    private:

        struct node {
            int data;
            node* next;
        };

        typedef struct node* nodePtr;
        
        nodePtr head;
        nodePtr curr;
        nodePtr temp;

    public: 
        LinkedList();
        void AddNode(int data);
        void DeleteNode(int data);
        void DisplayList();
};

#endif
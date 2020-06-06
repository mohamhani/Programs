#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

class DoublyLinkedList {

    private:
        struct node {
            int data;
            node* next;
            node* prev;
        };

        typedef struct node* nodePtr;

        nodePtr head;
        nodePtr tail;
        nodePtr currNode;
        nodePtr prevNode;
        nodePtr nextNode;

        nodePtr createNode(int data);


    public:
        DoublyLinkedList();
        void insertAtHead(int data);
        void insertAtTail(int data);
        void deleteNode(int data);
        void print();
};
#endif

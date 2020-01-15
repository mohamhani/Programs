#include <iostream>
#include <cstdlib>
#include "DoublyLinkedList.h"


using namespace std;

DoublyLinkedList::DoublyLinkedList() {
    head = NULL;
    tail = NULL;
    currNode = NULL;
    prevNode = NULL;
}

DoublyLinkedList::nodePtr DoublyLinkedList::createNode(int data) {
    nodePtr newNode = new node;

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void DoublyLinkedList::insertAtHead(int data) {
    nodePtr newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void DoublyLinkedList::insertAtTail(int data) {
    nodePtr newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DoublyLinkedList::deleteNode(int data) {
    nodePtr delPtr = NULL;

    if(head == NULL) {
        cout << "The doubly linked list is empty" << endl;
    }
    else if(head->data == data && head->next == NULL) {
        delPtr = head;
        delete delPtr;
        return;
    }
    else if(head->data == data && head->next != NULL) {
        delPtr = head;
        head = head->next;
        head->prev = NULL;

        delete delPtr;

        return;
    }
    else if(tail->data == data) {
        delPtr = tail;
        tail = delPtr->prev;
        tail->next = NULL;

        delete delPtr;

        return;
    }
    else {
        delPtr = head;
        while(delPtr != NULL && delPtr->data != data) {
            delPtr = delPtr->next;
        }

        if(delPtr == NULL) {
            cout << "The element: " << data << " Couldn't be found in the doubly linked list." << endl;
            return;
        }
        else {
            prevNode = delPtr->prev;
            nextNode = delPtr->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            delete delPtr;

            return;
        }
    }
}

void DoublyLinkedList::print() {
    currNode = head;
    while(currNode != NULL) {
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
}


#include <iostream>
#include <cstdlib>
#include "LinkedList.h"


using namespace std;

LinkedList::LinkedList() {
    head = NULL;
    curr = NULL;
    temp = NULL;
}

void LinkedList::AddNode(int data) {
    nodePtr newNode = new node;
    newNode->next = NULL;
    newNode->data = data;

    if(head != NULL) {
        curr = head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    else {
        head = newNode;
    }
}

void LinkedList::DeleteNode(int data) {
    nodePtr delPtr = NULL;
    temp = head;
    curr = head;

    while(curr != NULL && curr->data != data) {
        temp = curr;
        curr = curr->next;
    }
    if(curr == NULL) {
        cout << data << " sas not in the list" << endl;
        delete delPtr;
    }
    else {
        delPtr = curr;
        curr = curr->next;
        temp->next = curr;
        if(delPtr == head) {
            head = head->next;
            temp = NULL;
        }
        delete delPtr;
        cout << data <<" was deleted" << endl;
    }
}

void LinkedList::DisplayList() {
    curr = head;
    cout << "Here is the created linked list: " << endl;
    while(curr != NULL) {
        cout << curr->data << endl;
        curr = curr -> next;
    }
}
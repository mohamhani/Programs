#include <iostream>
#include <cstdlib>

#include "Stack.h"

using namespace std;


Stack::Stack() {
    head = NULL;
}

Stack::~Stack() {
    stackPtr p1;
    stackPtr p2;

    p1 = head;

    while( p1 != NULL) {
        p2 = p1;
        p1 = p1->prevItem;
        p2->prevItem = NULL;

        delete p2;
    }
}

void Stack::Push(string name, int value) {
    stackPtr newItem = new item;

    newItem->name = name;
    newItem->value = value;

    if(head == NULL) {
        head = newItem;
        head->prevItem = NULL;
    }
    else {
        newItem->prevItem = head;
        head = newItem;

    }
}

void Stack::ReadItem(stackPtr r) {
    cout << "-----------------------" << endl;

    cout << "name: " << r->name << endl;
    cout << "value: " << r->value << endl;

    cout << "-----------------------" << endl;
}

void Stack::Pop() {
    if(head == NULL) {
        cout << "There is nothing on the stack" << endl;
    }
    else {
        stackPtr p = head;
        ReadItem(p);

        head = head->prevItem;

        p->prevItem = NULL;

        delete p;
    }
}

void Stack::Display() {
    stackPtr p = head;

    if(head == NULL) {
        cout << "Stack is empty" << endl;
    }

    while(p != NULL) {
        ReadItem(p);

        p = p->prevItem;
    }
}
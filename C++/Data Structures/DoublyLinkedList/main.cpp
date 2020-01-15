#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

using namespace std;

int generateRandomNumber() {
    int randomNumber = rand() %100 + 1;

    cout << randomNumber << " ";

    return randomNumber;
}

int main(int argc, char** argv) {

    DoublyLinkedList DoublyList;
    int size, randomNumber;
    cout << "Enter the size of the doubly linked list: ";
    scanf("%d", &size);
    cout << endl;

    for(int i = 0; i < size; i++) {
        randomNumber = generateRandomNumber();
        DoublyList.insertAtHead(randomNumber);
    }
    cout << endl;

    DoublyList.print();
    cout << endl;

    DoublyList.deleteNode(200);

    DoublyList.print();
    cout << endl;

    return 0;
}
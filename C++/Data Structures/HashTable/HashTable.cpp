#include <cstdlib>
#include <iostream>
#include <string>

#include "HashTable.h"

using namespace std;

Hash::Hash() {
    for(int i = 0; i < tableSize; i++) {
        HashTable[i] = new item;
        HashTable[i]->name = "";
        HashTable[i]->drink = "";
        HashTable[i]->next = NULL;
    }
}

int Hash::hashKey(string key) {
    int hash = 0, index;

    for(int i = 0; i < key.length(); i++) {
        hash += (int)key[i];
    }
    index = hash % tableSize;

    return index;
}

void Hash::addItem(string name, string drink) {
    int index = hashKey(name);

    if(HashTable[index]->name.empty()) {
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }
    else {
        item* itemPtr = HashTable[index];
        while(itemPtr->next != NULL) {
            itemPtr = itemPtr->next;
        }
        
        itemPtr->next = new item;

        itemPtr->next->name = name;
        itemPtr->next->drink = drink;
        itemPtr->next->next = NULL;
    }
}

int Hash::numberOfItemsInIndex(int index) {
    int count = 0;

    if(HashTable[index]->name.empty()) {
        return 0;
    }
    else {
        count++;

        item* itemPtr = HashTable[index];

        while(itemPtr->next != NULL) {
            itemPtr = itemPtr->next;
            count++;
        }
    }

    return count;
}

void Hash::printTable() {
    int number;

    for(int i = 0; i < tableSize; i++) {
        number = numberOfItemsInIndex(i);
        cout << "---------------------------------" << endl;
        cout << "index = " << i << endl;
        cout << "name = " << HashTable[i]->name << endl;
        cout << "drink = " << HashTable[i]->drink << endl;
        cout << "number of items = " << number << endl; 
        cout << "---------------------------------" << endl;

        if(number > 1) {
            printItemsInIndex(i);
        }
    }
}

void Hash::printItemsInIndex(int index) {
    item* itemPtr = HashTable[index];

    if(itemPtr->name.empty()) {
        cout << "index = " << index << " is empty" << endl;
    }
    else {
        cout << "index " << index << " contains the following items" << endl;
        while(itemPtr != NULL) {
            cout << "-------------------------" << endl;
            cout << "name = " << itemPtr->name << endl;
            cout << "name = " << itemPtr->drink << endl;
            cout << "-------------------------" << endl;
            
            itemPtr = itemPtr->next;
        }
    }
}

void Hash::findDrink(string name) {
    int index = hashKey(name);

    bool foundName = false;

    string drink;

    item* itemPtr = HashTable[index];

    while(itemPtr != NULL) {

        if(itemPtr->name == name) {
            foundName = true;
            drink = itemPtr->drink;
        }
        itemPtr = itemPtr->next;
    }

    if(foundName) {
        cout << name << "'s favorite drink is " << drink << endl;
    }
    else {
        cout << name << "'s isn't in the table" << endl;
    }
}

void Hash::removeItem(string name) {
    int index = hashKey(name);

    item* delPtr;
    item* itemPtr1;
    item* itemPtr2;

    if(HashTable[index]->name.empty() && HashTable[index]->drink.empty()) {
        cout << name << " wasn't found in the Hash Table" << endl;
    }
    else if(HashTable[index]->name == name && HashTable[index]->next == NULL) {
        HashTable[index]->name = "";
        HashTable[index]->drink = "";
    }
    else if(HashTable[index]->name == name) {
        delPtr = HashTable[index];
        HashTable[index] = HashTable[index]->next;
        delete delPtr;

        cout << name << " was removed from the Hash Table" << endl;
    }
    else {
        itemPtr1 = HashTable[index]->next;
        itemPtr2 = HashTable[index];

        while(itemPtr1 != NULL && itemPtr1->name != name) {
            itemPtr2 = itemPtr1;
            itemPtr1 = itemPtr1->next;
        }
        
        if(itemPtr1 == NULL) {
            cout << name << " wasn't found in the Hash Table" << endl;
        }
        else {
            delPtr = itemPtr1;
            itemPtr1 = itemPtr1->next;
            itemPtr2->next = itemPtr1;

            delete delPtr;

            cout << name << " was removed from the Hash Table" << endl;
        }
    }
}
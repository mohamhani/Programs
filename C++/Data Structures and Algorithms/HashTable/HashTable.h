#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Hash {

    private:
        static const int tableSize = 5;

        struct item {
            string name;
            string drink;
            item* next;
        };

        item* HashTable[tableSize];

    public:
        Hash();
        int hashKey(string key);
        void addItem(string name, string drink);
        int numberOfItemsInIndex(int index);
        void printTable();
        void printItemsInIndex(int index);
        void findDrink(string name);
        void removeItem(string name);
};




#endif

#ifndef STACK_H
#define STACK_H

#include <string>

using namespace std;

class Stack {

    private:

        struct item {
            string name;
            int value;
            item* prevItem;
        };

        typedef struct item* stackPtr; 

        stackPtr head;

    public:

        void Push(string name, int value);
        void Pop();
        void ReadItem(stackPtr readItem);
        void Display();

        Stack();
        ~Stack();

};


#endif
#include <cstdlib>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>
#include <string>
#include <sstream>

#include "Stack.h"


using namespace std;

int generateRandomNumber() {
    int randomNumber = rand() %100 + 1;

    return randomNumber;
}

int main(int argc, char** argv) {
    
     Stack stack;

     int size, randomNumber;
     cout << "Enter the size of the linked list: " << endl;
     scanf("%d", &size);

     for(int i = 0; i < size; i++) {
         randomNumber = generateRandomNumber();
         ostringstream ss;
         ss << randomNumber;
         stack.Push(ss.str(), randomNumber);
     }

     stack.Display();

     cout << "Before the pop" << endl;

     stack.Pop();

     cout << "After the pop" << endl;

     stack.Display();


     return 0;
}
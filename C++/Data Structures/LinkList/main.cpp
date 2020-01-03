#include <iostream>
#include <cstdlib>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "LinkedList.h"

using namespace std;

int generateRandomNumber() {
    int randomNumber = rand() %100 + 1;

    return randomNumber;
}

int main(int argc, char** argv) {

    LinkedList List;
    int size, randomNumber;
    cout << "Enter the size of the linked list: " << endl;
    scanf("%d", &size);

    for(int i = 0; i < size; i++) {
        randomNumber = generateRandomNumber();
        List.AddNode(randomNumber);
    }

    List.DisplayList();

    return 0;
}
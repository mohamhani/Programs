#include <iostream>
#include <cstdlib>

using namespace std;

void sort(int array[], int length) {
    int zeros = 0;

    for(int i = 0; i < length; i++) {
        if(array[i] == 0) {
            zeros++;
        }
    }

    int n = 0;
    while(zeros--) {
        array[n++] = 0;
    }

    while(n < length) {
        array[n++] = 1;
    }
}

void displayArray(int array[], int length) {
    
    for(int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}



int main(int argc, const char* argv[]) {

    int array[] = {0, 0, 1, 0, 1, 1, 0, 1, 0, 0};

    int length = sizeof(array) / sizeof(array[0]);

    sort(array, length);

    displayArray(array, length);


    return 0;
}
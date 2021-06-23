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

    for(int i = 0; i < length; i++) {
        if(i < zeros) {
            array[i] = 0;
        }
        else {
            array[i] = 1;
        }
    }
}



int main(int argc, char** argv) {

    int array[] = {0, 0, 1, 0, 1, 1, 0, 1, 0, 0};
    int length = sizeof(array)/sizeof(array[0]);

    sort(array, length);

    for(int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
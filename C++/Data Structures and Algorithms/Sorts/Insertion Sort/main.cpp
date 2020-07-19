#include <iostream>

using namespace std;

void insertionSort(int array[], int length) {

    int key, j, i;
    
    for(i = 1; i < length; i++) {
        key = array[i];
        j = i - 1;

        while(j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j -= 1;
        }
        array[j + 1] = key;
    }

}

void printArray(int array[], int length) {
    
    for(int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(int argc, const char* argv[]) {

    int array[] = {12, 11, 13, 5, 6};
    int length = sizeof(array) / sizeof(array[0]);

    insertionSort(array, length);
    printArray(array, length);

    return 0;
}
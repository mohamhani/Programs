#include <iostream>

using std::cout;
using std::endl;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int index = low-1; // Index of the smaller element

    for(int j = low; j <= high - 1; j++) {
        if(array[j] < pivot) {
            index++;
            swap(&array[index], &array[j]);
        }
    }
    swap(&array[index + 1], &array[high]);
    return (index + 1);
}

void quickSort(int array[], int low, int high) {
    if(low < high) {
        int pv = partition(array, low, high);

        quickSort(array, low, pv - 1);
        quickSort(array, pv + 1, high);
    }
}

void printArray(int array[], int length) {
    for(int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(int argc, const char* argv[]) {
    
    int array[] = {10, 7, 8, 9, 1, 5, 45, 58, 100, 23, 59, 76, 42, 35};
    int length = sizeof(array) / sizeof(array[0]);

    quickSort(array, 0, length - 1);

    printArray(array, length);

    return 0;
}
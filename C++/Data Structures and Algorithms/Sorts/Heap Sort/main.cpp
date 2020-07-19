#include <iostream>

using std::cout;
using std::endl;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}



void heapify(int array[], int length, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < length && array[left] > array[largest]) {
        largest = left;
    }

    if(right < length && array[right] > array[largest]) {
        largest = right;
    }

    if(largest != index) {
        swap(&array[index], &array[largest]);

        heapify(array, length, largest);
    }
}

void heapSort(int array[], int length) {
    int i;
    // Build heap (rearrange array)
    for(i = (length / 2) - 1; i >= 0; i--) {
        heapify(array, length, i);
    }

    // One by one extract largest elements from the heap
    for(i = length - 1; i > 0; i--) {
        swap(&array[0], &array[i]);

        heapify(array, i, 0);
    }

}


void printArray(int array[], int length) {
    for(int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}


int main(int argc, const char* argv[]) {

    int array[] = {12, 11, 13, 5, 6, 7};
    int length = sizeof(array) / sizeof(array[0]);

    heapSort(array, length);

    printArray(array, length);

    return 0;
}
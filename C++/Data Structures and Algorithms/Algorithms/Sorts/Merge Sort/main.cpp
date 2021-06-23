#include <iostream>

using namespace std;

void merge(int array[], int left, int mid, int right) {
    int i, j, k;
    int temp1 = mid - left + 1;
    int temp2 = right - mid;

    int leftArray[temp1], rightArray[temp2];

    for(i = 0; i < temp1; i++) {
        leftArray[i] = array[left + i];
    }
    for(j = 0; j < temp2; j++) {
        rightArray[j] = array[mid+1 + j];
    }

    i = 0, j = 0, k = left;
    while(i < temp1 && j < temp2) {
        if(leftArray[i] <+ rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        }
        else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while(i < temp1) {
        array[k] = leftArray[i];
        i++, k++;
    }
    while(j < temp2) {
        array[k] = rightArray[j];
        j++, k++;
    }
}

void mergeSort(int array[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

void printArray(int array[], int length) {
    
    for(int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(int argc, const char* argv[]) {

    int array[] = {12, 11, 13, 5, 6, 7, 8, 21, 33, 50, 0, 1, 2, 27, 56, 100, 3};
    int length = sizeof(array) / sizeof(array[0]);
    cout << length << endl;

    cout << "Given array is" << endl;
    printArray(array, length);
    cout << endl;

    cout << "Sorted array is" << endl;
    mergeSort(array, 0, length-1);
    printArray(array, length);

    return 0;
}
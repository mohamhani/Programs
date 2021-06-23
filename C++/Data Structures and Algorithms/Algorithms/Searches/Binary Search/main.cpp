#include <iostream>

using namespace std;

void binarySearch(int array[], int left, int right, int x) {
    if(right >= left) {
        int mid = left + (right - left) / 2;

        if(array[mid] == x) {
            cout << "Element is present in the array" << endl;
            return;
        }

        if(array[mid] > x) {
            return binarySearch(array, left, mid - 1, x);
        }

        return binarySearch(array, mid + 1, right, x);

    }
    cout << "Element is not present in the array" << endl;
}


int main(int argc, const char* argv[]) {

    int array[] = {2,3, 4, 10, 40};
    int length = sizeof(array) / sizeof(array[0]);
    int x = 10;

    binarySearch(array, 0, length - 1, x);

    return 0;
}
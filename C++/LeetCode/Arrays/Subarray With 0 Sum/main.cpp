#include <iostream>
#include <cstdlib>
#include <unordered_map>

using namespace std;


void zeroSumSubArray(int array[], int length) {

    int sum;

    for(int i = 0; i < length; i++) {
        sum = 0;

        // Consider all sub-arrays starting from i
        for(int j = i; j < length; j++) {
            sum += array[j];

            if(sum == 0) {
                cout << "Subarray [" << i << ".." << j << "]" << endl;
            }
        }
    }
}

void generateRandomNumbers(int array[], int size) {
    
    for(int i = 0; i < size; i++) {
        array[i] = rand() %21 + (-10);
    }
}

void displayArray(int array[], int size) {
    
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(int argc, const char* argv[]) {

    int size = 10;

    int array[] = {3, 4, -7, 3, 1, 3, 1, -4, -2, -2};

    zeroSumSubArray(array, size);

    return 0;
}
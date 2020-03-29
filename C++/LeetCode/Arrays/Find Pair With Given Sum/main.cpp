#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

// Function to find a pair in an array with given sum using sorting
void findPair(int array[], int length, int sum) {
    sort(array, array + length);

    int low = 0;
    int high = length - 1;

    while(low < high) {
        if(array[low] + array[high] == sum) {
            cout << "Pair found" << endl;
            return;
        }

        (array[low] + array[high] < sum) ? low++ : high--;
    }

    cout << "Pair not found" << endl;
}

void generateRandomNumbers(int array[], int size) {
    
    for(int i = 0; i < size; i++) {
        array[i] = rand() %100 + 1;
    }
}

void displayArray(int array[], int size) {
    
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(int argc, const char* argv[]) {

    int size, sum = 0;;
    cout << "Enter the size of the array: ";
    cin >> size;

    int array[size];

    generateRandomNumbers(array, size);

    displayArray(array, size);

    while(sum != -1) {
        cout << "Enter the sum: ";
        cin >> sum;
        cout << endl;
        findPair(array, size, sum);
    }
    


    return 0;
}
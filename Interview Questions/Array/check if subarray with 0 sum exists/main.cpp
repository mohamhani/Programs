#include <iostream>
#include <cstdlib>

using namespace std;

void zeroSumSubarray(int array[], int length) {
    for(int i = 0; i < length; i++) {
        int sum = array[i];
        for(int j = i + 1; j < length; j++) {
            sum += array[j];
            if(sum == 0) {
                cout << "Subarray exits" << endl;
            }
        }
    }
}


int main(int argc, char** argv) {

    int array[] = {3, 4, -7, 3, 1, 3, 1, -4, -2, -2};
    int length = sizeof(array)/sizeof(array[0]);

    zeroSumSubarray(array, length);

    return 0;
}
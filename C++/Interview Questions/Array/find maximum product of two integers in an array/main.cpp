#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

void findMaximumProduct(int array[], int length) {
    int max_product = 0;
    int max_i, max_j;

    for(int i = 0; i < length; i++) {
        for(int j = i + 1; j < length; j++) {
            if(array[i] * array[j] > max_product) {
                max_product = array[i] * array[j];
                max_i = i;
                max_j = j;
            }
        }
    }

    cout << "Pair is " << array[max_i] << " " << array[max_j] << endl;
}

int main(int argc, char** argv) {

    int array[] = {10, 3, 5, 6, 2};
    int length = sizeof(array)/sizeof(array[0]);

    findMaximumProduct(array, length);

    return 0;
}
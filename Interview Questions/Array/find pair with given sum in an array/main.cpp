#include <iostream>
#include <cstdlib>


using namespace std;

void findPair(int array[], int length, int sum) {
    for(int i = 0; i < length; i++) {
        for(int j = i + 1; j < length; j++) {
            if (array[i] + array[j] == sum) {
                cout << "Pair find at index " << i << " and index " << j << endl;
                return;
            }
        }
    }
    cout << "Pair not found" << endl;
    return;
}


int main(int argc, char** argv) {

    int array[] = {8, 7, 2, 5, 3, 1};
    int sum = 70;

    int length = sizeof(array)/sizeof(array[0]);

    findPair(array, length, sum);


    return 0;
}
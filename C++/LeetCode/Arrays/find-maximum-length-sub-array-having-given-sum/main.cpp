#include <iostream>

using namespace std;

void maxLengthSubArray(int array[], int length, int S) {

    int len = 0;

    int ending_index = -1;

    for(int i = 0; i < length; i++) {
        int sum = 0;

        for(int j = i; j < length; j++) {
            sum += array[j];

            if(sum == S) {
                if(len < j - i + 1) {
                    len = j - i + 1;
                    ending_index = j;
                }
            }
        }
    }
    int start_index = ending_index - len + 1;
    cout << "[" << start_index << ", "<< ending_index << "]" << endl;
}


int main(int argc, const char* argv[]) {

    int array[] = {5, 6, -5, 5, 3, 5, 3, -2, 0};
    int sum = 8;

    int length = sizeof(array) / sizeof(array[0]);

    maxLengthSubArray(array, length, sum);   

    return 0;
}
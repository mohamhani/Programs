#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> addArrayToInteger(int array[], int len, int k) {
    int sum = 0, remainder;
    vector<int> result;

    for(int i = 0; i < len; i++) {
        sum += array[i];
        sum = sum * 10;
    }
    sum /= 10;

    sum = sum + k;

    while(sum != 0) {
        remainder = sum % 10;
        sum /= 10;
        result.push_back(remainder);
    }

    reverse(result.begin(), result.end());

    return result;
}

void printVector(vector<int> arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, const char* argv[]) {
    int array[] = {1, 2, 0, 0};
    int k = 34;
    int len = sizeof(array) / sizeof(array[0]);

    vector<int> result = addArrayToInteger(array, len, k);

    printVector(result);

    return 0;
}
#include <iostream>
#include <unordered_map>

using namespace std;

// Function to find a pair in an array with a given sum using hashing
void findPair(int arr[], int n, int sum) {
    // Create an empty unordered_map
    unordered_map<int, int> map;

    bool found = false;

    for(int i = 0; i < n; i++) {
        if(map.find(sum - arr[i]) != map.end()) {
            cout << "Pair found (" << arr[map[sum - arr[i]]] << "," << arr[i] << ")" << endl;
            found = true;
        }
        map[arr[i]] = i;
    }

    if(found) {
        return;
    }
    else {
        cout << "Pair not found" << endl;
        return;
    }
    
}

int main() {
    int arr[] = {8, 7, 2, 5, 3, 1};
    int sum = 10;

    int n = sizeof(arr)/sizeof(arr[0]);

    findPair(arr, n, sum);

    return 0;
}


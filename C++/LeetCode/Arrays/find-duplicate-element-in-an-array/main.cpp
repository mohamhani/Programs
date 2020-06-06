#include <iostream>

using namespace std;

int findDuplicate(int arr[], int size) {
    bool visited[size];
    fill(visited, visited + size, 0); // set every element to 0

    for(int i = 0; i < size; i++) {
        if(visited[arr[i]]) {
            return arr[i];
        }

        visited[arr[i]] = true;
    }

    return -1;
}

int main(int argc, const char* argv[]) {

    int arr[] = {1, 2, 3, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int duplicateElement = findDuplicate(arr, size);

    cout << "Duplicate element is " << duplicateElement << endl;

    


    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

bool isConsecutive(int array[], int startOfArray, int endOfArray, int minElement, int maxElement) {
    /**
     * In order for an array to contain consecutive integers, the difference between maximum and minimum elements in it should be exactly j - i
     * */
    if(maxElement - minElement != endOfArray - startOfArray) {
        return false;
    }

    vector<bool> visitedElement(endOfArray - startOfArray + 1);

    for(int k = startOfArray; k <= endOfArray; k++) {
        if(visitedElement[array[k] - minElement]) {
            return false;
        }

        visitedElement[array[k] - minElement] = true;
    }

    return true;
}

void findMaxSubarray(int array[], int size) {
    int start = 0, end = 0;
    int len = 1;

    for(int i = 0; i < size - 1; i++) {
        int max_val = array[i], min_val = array[i];
        for(int j = i + 1; j < size; j++) {
            max_val = max(max_val, array[j]);
            min_val = min(min_val, array[j]);

            if(isConsecutive(array, i, j, min_val, max_val)) {
                // Making sure to get the largest sub-array
                if(len < max_val - min_val + 1) {
                    len = max_val - min_val + 1;
                    start = i;
                    end = j;
                }
            }
        }
    }

    cout << "The largest consecutive sub-array is:" << endl;
    for(int k = start; k <= end; k++) {
        cout << array[k] << "\t";
    }
    cout << endl;
}


int main(int argc, const char* argv[]) {

    int array[] = {2, 0, 2, 1, 4, 3, 1, 0};

    int size = sizeof(array) / sizeof(array[0]);

    findMaxSubarray(array, size);

    return 0;
}
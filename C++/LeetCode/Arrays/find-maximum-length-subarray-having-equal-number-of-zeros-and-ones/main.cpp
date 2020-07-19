#include <iostream>
#include <unordered_map>


using namespace std;

void max_len_subarray(int array[], int length) {

    unordered_map<int, int> un_map;

    un_map[0] = -1;

    int ending_index = -1, sum = 0, len = 0;

    for(int i = 0; i < length; i++) {
        sum += (array[i] == 0) ? -1 : 1;

        if(un_map.find(sum) != un_map.end()) {
            if(len < i - un_map[sum]) {
                len = i - un_map[sum];
                ending_index = i;
            }
        }
        else {
            un_map[sum] = i;
        }
    }

    if(ending_index != -1) {
        cout << "[" << ending_index - len + 1 << ", " << ending_index << "]" << endl;
    }
    else {
        cout << "sub-array exists" << endl;
    }

}


int main(int argc, const char* argv[]) {

    int array[] = {0, 0, 1, 0, 1, 0, 0};

    int length = sizeof(array) / sizeof(array[0]);

    max_len_subarray(array, length);

    return 0;
}
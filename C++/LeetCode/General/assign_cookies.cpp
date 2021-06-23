#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findContentChildren(vector<int> children, vector<int> cookies) {
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());

    int i = children.size() - 1;
    int j = cookies.size() - 1;
    int count = 0;

    while(i >= 0 && j >= 0) {
        if(cookies[j] >= children[i--]) {
            count++;
            j--;
        }
    }

    return count;
}

int main(int argc, const char* argv[]) {
    vector<int> children = {1, 2}; // Each element in this vector represents children's greed
    vector<int> cookies = {1, 2, 3};

    int count = findContentChildren(children, cookies);

    cout << count << endl;


    return 0;
}
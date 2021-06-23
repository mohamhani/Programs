#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

double average(vector<int>& salary) {
    double sum = 0, size;

    sort(salary.begin(), salary.end());

    for(int i = 1; i < salary.size() - 1; i++) {
        sum += salary[i];
    }

    size = salary.size() - 2;

    return sum/size;
}

int main(int argc, const char* argv[]) {

    vector<int> salary = {4000, 3000, 1000, 2000};

    int ave = average(salary);

    cout << ave << endl;

    return 0;
}
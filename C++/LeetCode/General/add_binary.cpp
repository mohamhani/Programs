#include <iostream>

//using namespace std;
using std::cout;
using std::endl;
using std::string;

string addBinary(string a, string b) {

    string result = "";
    int sum = 0;

    int i = a.length() - 1, j = b.length() - 1;

    while(i >= 0 || j >= 0 || sum == 1) {

        // Converting characters into integers and then adding them up
        sum += ((i >= 0) ? a[i] - '0' : 0);
        sum += ((j >= 0) ? b[j] - '0' : 0);

        result = char(sum % 2 + '0') + result;

        // Compute the carry over
        sum /= 2;

        i--;
        j--;
    }

    return result;
}

int main(int argc, const char* argv[]) {

    string a = "1101", b = "100";

    string result = addBinary(a, b);

    cout << result << endl; 

    return 0;
}
#include <iostream>
#include <cstdlib>

using namespace std;

void isPalindrome(string str) {
    int low = 0;
    int high = str.length() - 1;
    
    while(low < high) {
        if(str[low] != str[high]) {
            cout << "Not palindrome" << endl;
            return;
        }
        low++;
        high--;
    }

    cout << "Palindrome" << endl;
}


int main(int argc, char** argv) {

    string str = "racecar";

    isPalindrome(str);

    return 0;
}
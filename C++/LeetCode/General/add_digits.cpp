#include <iostream>

using std::cout;
using std::endl;
//using std::string;

int addDigits(int num) {
    int num2 = num % 10;
    int num1 = num / 10;
    
    int sum = num1 + num2;

    return sum < 10 ? sum : addDigits(sum);
}


int main(int agrc, const char* argv[]) {


    cout << addDigits(38) << endl;

    return 0;
}
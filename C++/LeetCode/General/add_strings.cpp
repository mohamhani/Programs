#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

int stringToInteger(string num) {
    int result = 0, len;

    len = num.length();

    for(int i = 0; i < len; i++) {
        result += num[i] - '0';
        result = result * 10;
    }

    result /= 10;


    return result;
}

string addStrings(string num1, string num2) {
    string result = "";
    stringstream ss;
    int sum, number1, number2;

    number1 = stringToInteger(num1);
    number2 = stringToInteger(num2);

    sum = number1 + number2;

   ss << sum;

   result = ss.str();

    return result;
}

int main(int argc, const char* argv[]) {

    string num1 = "6", num2 = "3";

    string result = addStrings(num1, num2);

    cout << result << endl; 

    return 0;
}
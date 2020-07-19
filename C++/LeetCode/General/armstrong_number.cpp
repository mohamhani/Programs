#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

bool isArmstrongNumber(int num) {
    int originalNum, remainder, power, n = 0, sum = 0;

    originalNum = num;

    while(originalNum != 0) {
        originalNum /= 10;
        n++;
    }

    originalNum = num;

    while(originalNum != 0) {
        remainder = originalNum % 10;

        power = round(pow(remainder, n));
        sum += power;
        originalNum /= 10;
    }

    return sum == num ? true : false;
}

int main(int argc, const char* argv[]) {

    bool result = isArmstrongNumber(153);

    cout << result << endl;

    return 0;
}
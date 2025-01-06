#include <iostream>
using namespace std;

int divide(int dividend, int divisor) {
    if (dividend == 0) return 0;
    if (divisor == 1) return dividend;
    if (divisor == -1) {
        if (dividend == INT_MIN) return INT_MAX;
        return -dividend;
    }

    int quotient = 0;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    dividend = abs(dividend);
    divisor = abs(divisor);

    while (dividend >= divisor) {
        int temp = divisor, multiple = 1;
        while (dividend >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        dividend -= temp;
        quotient += multiple;
    }

    return sign * quotient;
}

int main() {
    int dividend, divisor;
    cin >> dividend >> divisor;
    cout << divide(dividend, divisor) << endl;
    return 0;
}

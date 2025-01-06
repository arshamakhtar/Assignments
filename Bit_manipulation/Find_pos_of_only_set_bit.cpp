#include <iostream>
using namespace std;

int findPos(int n) {
    if (n <= 0 || (n & (n - 1)) != 0) {
        return -1; 
    }

    int pos = 1; 
    while ((n & 1) == 0) {
        n >>= 1; 
        pos++;
    }
    return pos;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int pos = findPos(num);
    if (pos == -1) {
        cout << "The number is either not a power of two or invalid" << endl;
    } else {
        cout << "The position of the only set bit is: " << pos << endl;
    }

    return 0;
}

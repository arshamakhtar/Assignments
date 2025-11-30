#include <iostream>
using namespace std;

int square(int n) {
    int result = 0;
    int x = n;

    while (x) {
        if (x & 1) result += n;
        n <<= 1;
        x >>= 1;
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    cout <<"square of the number will be"<< square(n) << endl;
    return 0;
}

//assignment

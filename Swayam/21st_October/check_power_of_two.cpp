#include <bits/stdc++.h>
using namespace std;

// Ye function check karta hai ki n ek power of two hai ya nahi
bool isPowerOfTwo(int n) {
    // Power of two ka ek hi set bit hota hai (n > 0 aur n & (n-1) == 0)
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int n;
    cin >> n; // Input value lo

    if (isPowerOfTwo(n))
        cout << "Yes" << endl;   // n power of two hai
    else
        cout << "No" << endl;    // n power of two nahi hai
    return 0;
}

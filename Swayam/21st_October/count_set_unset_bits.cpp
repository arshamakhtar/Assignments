#include <bits/stdc++.h>
using namespace std;

// Ye function 1 se n tak total set bits count karta hai
int countSetBits(int n) {
    if (n == 0) return 0;

    // Sabse bada power of 2 jo n se chota ya equal ho
    int x = log2(n);

    // 2^x tak set bits count
    int bitsTill2x = x * (1 << (x - 1));

    // 2^x se n tak leftmost bits add karo
    int msbRest = n - (1 << x) + 1;

    // Baaki ke numbers ke liye recursive call karo
    int rest = countSetBits(n - (1 << x));
    
    return bitsTill2x + msbRest + rest;
}

int main() {
    int n;
    cin >> n; // Input n
    cout << countSetBits(n) << endl; // Total set bits print karo
    return 0;
}

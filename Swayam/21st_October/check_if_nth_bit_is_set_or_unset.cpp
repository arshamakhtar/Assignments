#include <bits/stdc++.h>
using namespace std;

// Ye function check karta hai ki n ka k-th bit set hai ya nahi
bool isKthBitSet(int n, int k) {
    // k-th bit check karne ke liye mask use karo (1-based indexing)
    return (n & (1 << (k - 1))) != 0;
}

int main() {
    int n, k;
    cin >> n >> k; // Input number aur k (which bit check karni hai)

    if (isKthBitSet(n, k))
        cout << "Yes" << endl; // k-th bit set hai
    else
        cout << "No" << endl;  // k-th bit set nahi hai
    return 0;
}

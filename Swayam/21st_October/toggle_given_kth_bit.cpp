#include <bits/stdc++.h>
using namespace std;

// Ye function l se r range tak n ke bits toggle karta hai
int toggleBitsInRange(int n, int l, int r) {
    // Mask banao jisme sirf l se r position tak bits set ho
    int mask = 0;

    // l to r (1-based index) tak sare bits set karo
    for (int i = l; i <= r; i++) {
        mask |= (1 << (i - 1)); // ith position per bit set karo
    }

    // n ko mask ke saath XOR karo, toggle ho jayenge
    return n ^ mask;
}

int main() {
    int n, l, r;
    cin >> n >> l >> r; // n (original number), l (start), r (end) input lo
    cout << toggleBitsInRange(n, l, r) << endl; // Result print karo
    return 0;
}

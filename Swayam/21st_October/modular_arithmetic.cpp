#include <bits/stdc++.h>
using namespace std;

// Sabse chhota number 111... (kuch 1s) jo k se divide ho, uska length batao
int smallestRepunitDivByK(int k) {
    // Agar 2 ya 5 se divisible hai, kabhi nahi hoga
    if (k % 2 == 0 || k % 5 == 0) return -1;
    int num = 1, len = 1;
    set<int> seen; // check for cycles if necessary but not needed for this range
    while (num % k != 0) {
        num = (num * 10 + 1) % k; // next number bhi % k
        len++;
        // Infinite loop se bachne ke liye
        if (seen.count(num)) return -1;
        seen.insert(num);
    }
    return len;
}

int main() {
    int k;
    cin >> k; // Input value lo
    cout << smallestRepunitDivByK(k) << endl; // Output print karo
    return 0;
}

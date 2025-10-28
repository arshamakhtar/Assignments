// Fibonacci DP Memoization approach
#include <bits/stdc++.h>
using namespace std;

// Recursion + DP array mein answer store karte hain (memoization)
int fibMemo(int n, vector<int> &dp) {
    // Base case - pehle do terms fix hain
    if (n <= 1) return n;

    // Agar dp[n] already calculate ho chuka hai toh direct return karo
    if (dp[n] != -1) return dp[n];

    // Nahin hai toh recursion se calculate karo aur store karo
    dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
    return dp[n];
}

int main() {
    int n;
    cout << "Kaunsa n chahiye Fibonacci mein? "; // User se input lo
    cin >> n;
    vector<int> dp(n + 1, -1); // DP array bana lo, -1 se fill karo
    cout << "Memoization se Fibonacci " << n << "th term: " << fibMemo(n, dp) << endl;
    return 0;
}

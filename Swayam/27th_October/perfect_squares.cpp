#include <bits/stdc++.h>
using namespace std;

// Har number ke liye minimum perfect squares DP se calculate karo
int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0; // 0 banane ke liye koi square nahi chahiye

    for (int i = 1; i <= n; ++i) {
        // Har possible perfect square ko try karo
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Minimum number of perfect squares: " << numSquares(n) << endl;
    return 0;
}

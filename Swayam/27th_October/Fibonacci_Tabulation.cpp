// Fibonacci DP Tabulation approach
#include <bits/stdc++.h>
using namespace std;

// Iterative tariqe se DP array mein sab answer fill karo
int fibTab(int n) {
    if (n == 0) return 0;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    // Loop chala ke sare answer calculate karo
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2]; // Do pehle term ka sum daal do
    }
    return dp[n]; // Last mein nth term return karo
}

int main() {
    int n;
    cout << "Kaunsa n chahiye Fibonacci mein? "; // User se input lo
    cin >> n;
    cout << "Tabulation se Fibonacci " << n << "th term: " << fibTab(n) << endl;
    return 0;
}

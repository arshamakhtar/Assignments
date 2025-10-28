#include <bits/stdc++.h>
using namespace std;

// Base case - agar 0 ya 1 step hai, ek hi tareeka hai chadne ka
int rec(int i, vector<int>& dp) {
    if (i <= 1) return 1;

    // Agar pehle se solve ho chuka hai toh direct return kar do
    if (dp[i] != -1) return dp[i];

    // Nahin solve hua toh dono options ka sum store kar do
    return dp[i] = rec(i - 1, dp) + rec(i - 2, dp);
}

int main() {
    int n;
    cout << "Enter number of steps: "; // String output normal English mein rakhi hai
    cin >> n;
    vector<int> dp(n + 1, -1); // DP array, pehle -1 se fill karo

    // Total ways batane wala output
    cout << "Total ways to climb the stairs: " << rec(n, dp) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Har step se minimum cost calculate karo DP ke sath
int rec(int i, int n, vector<int>& cost, vector<int>& dp) {
    // Agar n se aage chala gaya toh koi cost nahi
    if (i > n) return 0;
    // Pehle se solve hua toh wahi return karo
    if (dp[i] != -1) return dp[i];
    // Ek step aur do step aage jaane ka minimum le lo
    int one = cost[i] + rec(i + 1, n, cost, dp);
    int two = cost[i] + rec(i + 2, n, cost, dp);
    return dp[i] = min(one, two);
}

int main() {
    int n;
    cout << "Enter number of steps: ";
    cin >> n;
    vector<int> cost(n);
    cout << "Enter cost array: ";
    for (int i = 0; i < n; ++i) cin >> cost[i];
    vector<int> dp(n + 1, -1);

    // 0th ya 1st se start kar sakte hai, dono ka minimum ans hai
    cout << "Minimum cost to reach the top: " << min(rec(0, n - 1, cost, dp), rec(1, n - 1, cost, dp)) << endl;
    return 0;
}

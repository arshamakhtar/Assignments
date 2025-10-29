#include<iostream>
#include<vector>
using namespace std;
 int solve(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {
    {    // Base case
        if (idx == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
              
        }

        if (dp[idx][amount] != -1) return dp[idx][amount];

        int notTake = solve(idx - 1, amount, coins, dp);
        int take = 1e9;
        if (coins[idx] <= amount)
            take = 1 + solve(idx, amount - coins[idx], coins, dp);

        return dp[idx][amount] = take+notTake;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(n - 1, amount, coins, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};
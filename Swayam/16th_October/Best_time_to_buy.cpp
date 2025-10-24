#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // ab tak ka minimum price
        int maxProfit = 0;       // ab tak ka maximum profit

        for (int price : prices) {
            // har din ka price compare karo minimum ke sath
            minPrice = min(minPrice, price);

            // profit nikalke maximum me store karo
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];

    Solution sol;
    cout << sol.maxProfit(prices);
}

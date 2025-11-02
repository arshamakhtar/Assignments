#include <bits/stdc++.h>

using namespace std;

int maxScoreWithJumps(vector<int>& buildings, int k) {
    int n = buildings.size();
    vector<int> dp(n, 0); // dp[i] = max score reaching building i
    dp[0] = buildings[0];

    // Deque to keep track of max dp values in the sliding window
    deque<int> dq;
    dq.push_back(0);

    for (int i = 1; i < n; i++) {
        // Remove indices outside the window of size k
        while (!dq.empty() && dq.front() < i - k) {
            dq.pop_front();
        }
        // dp[i] is current building's points + max dp from allowed window
        dp[i] = buildings[i] + dp[dq.front()];

        // Maintain decreasing order of dp values in deque
        while (!dq.empty() && dp[i] >= dp[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    return dp[n - 1]; // maximum score reaching last building
}

int main() {
    vector<int> buildings = {2, 5, 6, 1, 4, 5};
    int k = 2;
    cout << "Max score Alice can get: " << maxScoreWithJumps(buildings, k) << endl;
    // Output: 16 (5 + 6 + 5)

    return 0;
}

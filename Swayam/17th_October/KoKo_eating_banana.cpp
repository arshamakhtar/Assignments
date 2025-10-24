#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canEat(vector<int>& piles, int h, int speed) {
        long long time = 0;
        for (int p : piles) {
            // har pile ko eat karne ka time ceil(p / speed)
            time += (p + speed - 1) / speed;
        }
        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canEat(piles, h, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    int n, h;
    cin >> n >> h;

    vector<int> piles(n);
    for (int i = 0; i < n; i++) cin >> piles[i];

    Solution sol;
    cout << sol.minEatingSpeed(piles, h);
}

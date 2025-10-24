#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;

        // two pointer approach
        while (left < right) {
            // current area calculate karo
            int width = right - left;
            int ht = min(height[left], height[right]);
            int currWater = width * ht;

            maxWater = max(maxWater, currWater);

            // chhoti height wale pointer ko move karo
            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxWater;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++) cin >> height[i];

    Solution sol;
    cout << sol.maxArea(height);
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i=0;i<n;i++) cin >> nums[i];

    int currSum = nums[0];
    int maxSum = nums[0];

    for(int i=1;i<n;i++) {
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);
    }

    cout << "Maximum Subarray Sum: " << maxSum << endl;
    return 0;
}

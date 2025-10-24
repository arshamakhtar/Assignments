#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i=0;i<n;i++) cin >> nums[i];

    int maxProd = nums[0], minProd = nums[0], result = nums[0];

    for(int i=1;i<n;i++) {
        if(nums[i] < 0) swap(maxProd, minProd);
        maxProd = max(nums[i], maxProd*nums[i]);
        minProd = min(nums[i], minProd*nums[i]);
        result = max(result, maxProd);
    }

    cout << "Maximum Product Subarray: " << result << endl;
    return 0;
}

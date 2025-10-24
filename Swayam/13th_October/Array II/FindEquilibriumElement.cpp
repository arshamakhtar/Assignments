#include <bits/stdc++.h>
using namespace std;


    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);

        // prefix[i] = sum of all elements before index i
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        // suffix[i] = sum of all elements after index i
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + nums[i + 1];
        }

        // check for pivot index
        for (int i = 0; i < n; i++) {
            if (prefix[i] == suffix[i]) 
                return i;
        }

        return -1;
    }

int main() {
    Solution obj;
    int n;

    cout << "Enter size of array: ";
    cin >> n; // user se array ka size lena

    vector<int> nums(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; // array elements input lena
    }

    int ans = obj.pivotIndex(nums);

    if (ans != -1)
        cout << "Pivot index is: " << ans << endl;
    else
        cout << "No pivot index found." << endl;

    return 0;
}

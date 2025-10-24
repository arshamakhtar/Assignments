#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size(); // agar element nahi mila, to end position

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // agar mid element target se bada ya barabar hai
        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << lowerBound(arr, target);
}

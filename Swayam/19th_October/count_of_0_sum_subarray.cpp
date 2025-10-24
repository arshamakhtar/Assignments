#include <bits/stdc++.h>
using namespace std;

// Ye function zero sum subarrays ka count return karta hai
int countZeroSumSubarrays(vector<int>& arr) {
    int n = arr.size();

    unordered_map<int, int> prefixCount; // prefix sum frequency map
    int prefixSum = 0;
    int count = 0; // zero sum subarrays ka count

    // prefix sum 0 ki frequency 1 se initialize karo
    prefixCount[0] = 1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i]; // running sum update karo

        // Agar running sum pehle dekha gaya hai,
        // iska matlab between those indices zero sum subarray hai
        if (prefixCount.find(prefixSum) != prefixCount.end()) {
            count += prefixCount[prefixSum]; // jitni baar prefix sum aya, utne zero sum subarrays
        }

        // prefix sum count update karo
        prefixCount[prefixSum]++;
    }

    return count; // total zero sum subarrays return karo
}

int main() {
    int n;
    cin >> n; // array ka size input lo
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i]; // array elements input lo
    cout << countZeroSumSubarrays(arr); // zero sum subarrays ka count print karo
    return 0;
}

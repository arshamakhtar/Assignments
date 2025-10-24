#include <bits/stdc++.h>
using namespace std;

// Ye function top k frequent elements return karta hai
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> counter; // frequency count karne ke liye
    for (int n : nums) {
        counter[n]++; // element ka count update karo
    }

    // Frequency ke hisaab se elements ko vector me daalo
    vector<vector<int>> freq(nums.size() + 1);
    for (auto& entry : counter) {
        freq[entry.second].push_back(entry.first); // freq i par saare elements daalo
    }

    vector<int> res;
    // Highest frequency se lowest tak jao
    for (int i = freq.size() - 1; i >= 0; i--) {
        for (int num : freq[i]) {
            res.push_back(num); // Result me daalo
            if (res.size() == k) {
                return res; // Agar k elements ho gaye toh return karo
            }
        }
    }

    return {}; // Default case (kabhi nahi aayega)
}

int main() {
    int n, k;
    cin >> n >> k; // Pehle array ka size aur k lo
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i]; // Array input lo

    vector<int> result = topKFrequent(nums, k); // Function call karo

    // Result print karo
    for (int num : result) cout << num << " ";
    cout << endl;
    return 0;
}

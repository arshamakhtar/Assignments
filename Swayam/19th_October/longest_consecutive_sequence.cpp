#include <bits/stdc++.h>
using namespace std;

// Ye function longest consecutive sequence find karta hai
int longestConsecutive(vector<int>& nums) {
    int longest = 1;
    int n = nums.size();
    if (n == 0) return 0; // Agar array empty hai toh 0 return karo
    
    unordered_set<int> st;
    // Sab elements ko set me daal do (unique elements ke liye)
    for (int i = 0; i < n; i++) {
        st.insert(nums[i]);
    }
    
    // Har element ke liye check karo ki kya usse ek chhota element set me nahi hai
    // Agar nahi hai toh is element se sequence start ho sakta hai
    for (auto it : st) {
        if (st.find(it - 1) == st.end()) {
            int count = 1;
            int x = it;
            // Consecutive elements ka count badhao
            while (st.find(x + 1) != st.end()) {
                count++;
                x++;
            }
            longest = max(longest, count); // Maximum length update karo
        }
    }
    return longest;
}

int main() {
    int n;
    cin >> n; // Input array ka size lo
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i]; // Array ke elements input lo
    
    cout << longestConsecutive(nums); // Result print karo
    return 0;
}

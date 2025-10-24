#include <bits/stdc++.h>
using namespace std;

// Ye function longest subarray ke length batata hai jiska sum 0 hota hai
int maxLength(vector<int>& arr) {
    int n = arr.size();

    unordered_map<int, int> firstSeen; // prefix sum -> first index
    int prefixSum = 0;  // ab tak ka sum
    int maxLen = 0;     // maximum length store karne ke liye

    firstSeen[0] = -1; // Agar starting se hi sum 0 ho jaye toh handle karne ke liye

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i]; // running sum update karo

        // Agar same prefix sum pehle dekha hai toh subarray ka sum 0 hai
        if (firstSeen.find(prefixSum) != firstSeen.end()) {
            int prevIndex = firstSeen[prefixSum];
            int length = i - prevIndex;
            maxLen = max(maxLen, length); // max length update karo
        } 
        else {
            // Pehli baar ye prefix sum mila hai, toh uska index store karo
            firstSeen[prefixSum] = i;
        }
    }

    return maxLen; // longest subarray length return karo
}

int main() {
    int n;
    cin >> n; // Input array ka size lo
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i]; // Array elements input lo
    cout << maxLength(arr); // Output result print karo
    return 0;
}

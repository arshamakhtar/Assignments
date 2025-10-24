#include <bits/stdc++.h>
using namespace std;

// Ye function s ke andar p ke anagrams ke starting index return karta hai
vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    int n = s.size(), k = p.size();
    if (n < k) return ans;

    vector<int> cntP(26, 0), cntS(26, 0);

    // p ke saare characters count karo
    for (char ch : p) cntP[ch - 'a']++;

    // Sliding window technique use karo
    for (int i = 0; i < n; i++) {
        cntS[s[i] - 'a']++; // Window me current char add karo

        // Window ki size zyada ho jaaye toh leftmost char hatao
        if (i >= k) cntS[s[i - k] - 'a']--;

        // Window ki size k ho gayi, ab counts match check karo
        if (i >= k - 1 && cntS == cntP)
            ans.push_back(i - k + 1);
    }
    return ans;
}

int main() {
    string s, p;
    cin >> s >> p; // Input main string aur pattern string lo

    vector<int> res = findAnagrams(s, p); // Function call
    for (int idx : res) cout << idx << " "; // Results print karo
    cout << endl;
    return 0;
}

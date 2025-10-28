#include <bits/stdc++.h>
using namespace std;

// Har number mein kitne 1-bits hai, DP se find karo
vector<int> countBits(int n) {
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        // Last bit hatane ke baad wale ka ans + 1 agar last bit 1 hai toh
        ans[i] = ans[i >> 1] + (i & 1);
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> result = countBits(n);
    cout << "Number of 1-bits from 0 to n: ";
    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}

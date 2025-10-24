#include <bits/stdc++.h>
using namespace std;

// Ye function 0 se n tak har number ke set bits count karta hai
vector<int> countBits(int n) {
    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        // i ka set bit count: i/2 ke result pe 1 add karo agar last bit set ho toh
        res[i] = res[i >> 1] + (i & 1);
    }
    return res;
}

int main() {
    int n;
    cin >> n; // Input number lo

    vector<int> ans = countBits(n); // Function call

    for (int x : ans) cout << x << " "; // Output print karo
    cout << endl;
    return 0;
}

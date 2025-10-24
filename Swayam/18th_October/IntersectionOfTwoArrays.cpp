#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr1[1000], arr2[1000]; // simple arrays
    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < m; i++) cin >> arr2[i];

    map<int,int> count; // number -> count in arr1
    for (int i = 0; i < n; i++) count[arr1[i]] = 1;

    vector<int> ans;
    for (int i = 0; i < m; i++) {
        if (count[arr2[i]] == 1) {
            ans.push_back(arr2[i]);
            count[arr2[i]] = 0; // avoid duplicate in answer
        }
    }

    for (int x : ans) cout << x << " ";
}

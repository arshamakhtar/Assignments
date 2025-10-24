#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cout << "Enter size of first sorted array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements: ";
    for(int i=0;i<n;i++) cin >> a[i];

    cout << "Enter size of second sorted array: ";
    cin >> m;
    vector<int> b(m);
    cout << "Enter elements: ";
    for(int i=0;i<m;i++) cin >> b[i];

    vector<int> uni, inter;
    int i=0, j=0;

    while(i<n && j<m) {
        if(a[i]<b[j]) uni.push_back(a[i++]);
        else if(b[j]<a[i]) uni.push_back(b[j++]);
        else {
            uni.push_back(a[i]);
            inter.push_back(a[i]);
            i++; j++;
        }
    }

    while(i<n) uni.push_back(a[i++]);
    while(j<m) uni.push_back(b[j++]);

    cout << "Union: ";
    for(int x:uni) cout << x << " ";
    cout << "\nIntersection: ";
    for(int x:inter) cout << x << " ";
    cout << endl;

    return 0;
}

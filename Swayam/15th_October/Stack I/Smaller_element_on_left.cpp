#include <bits/stdc++.h>
using namespace std;

vector<int> smallerOnLeft(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        // Jab tak stack ke top pe bada ya equal element hai -> pop
        while (!st.empty() && st.top() >= arr[i])
            st.pop();

        // Agar stack empty nahi hai -> uska top hi smaller element hai
        if (!st.empty())
            ans[i] = st.top();

        // Current element ko stack me daal do
        st.push(arr[i]);
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> result = smallerOnLeft(arr);

    cout << "Smaller element on left:\n";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}

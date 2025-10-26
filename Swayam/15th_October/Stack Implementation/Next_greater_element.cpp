#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st; // stack to store elements

    for (int i = n - 1; i >= 0; i--) {
        // remove smaller elements from stack
        while (!st.empty() && st.top() <= arr[i])
            st.pop();

        // if stack not empty → next greater = st.top()
        if (!st.empty())
            ans[i] = st.top();

        // push current element
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

    vector<int> result = nextGreaterElement(arr);

    cout << "Next Greater Elements:\n";
    for (int x : result)
        cout << x << " ";

    cout << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            // Jab tak stack me koi right-moving asteroid hai aur current left-moving hai
            while (!st.empty() && a < 0 && st.top() > 0) {
                if (abs(st.top()) < abs(a)) {
                    // Agar stack top chhota hai -> destroy it
                    st.pop();
                    continue;
                } else if (abs(st.top()) == abs(a)) {
                    // Dono equal size -> dono destroy
                    st.pop();
                }
                destroyed = true;
                break;
            }

            if (!destroyed)
                st.push(a);
        }

        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution sol;
    vector<int> ans = sol.asteroidCollision(arr);

    for (int x : ans) cout << x << " ";
}

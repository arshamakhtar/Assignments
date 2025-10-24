#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
    stack<pair<int, int>> st; // {price, span}
public:
    int next(int price) {
        int span = 1;

        // Jab tak stack ke top ka price chhota hai, span add karte jao
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // Push current price aur uska span
        st.push({price, span});
        return span;
    }
};

int main() {
    int n;
    cin >> n;
    StockSpanner sp;

    while (n--) {
        int price;
        cin >> price;
        cout << sp.next(price) << " ";
    }
}

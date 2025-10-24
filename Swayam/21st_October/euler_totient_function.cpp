#include <bits/stdc++.h>
using namespace std;

// Euler's Totient Function n ke liye — O(sqrt(n))
int phi(int n) {
    int result = n;
    // Sab prime divisors ko factor out karo
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            // Prime divisor mila, usse result me se subtract karo
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n; // Agar n ab bhi prime hai, subtract its part
    return result;
}

int main() {
    int n;
    cin >> n; // Input number lo
    cout << phi(n) << endl; // Euler's Totient result print karo
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Ye function n se chote sare primes ko count karta hai
int countPrimes(int n) {
    if (n <= 2) return 0;
    vector<bool> isPrime(n, true); // Initially saare numbers prime maano
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++; // Ye prime hai count badhao
            // iske multiples ko prime se hatao
            for (int j = 2 * i; j < n; j += i)
                isPrime[j] = false;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n; // Input upper limit lo
    cout << countPrimes(n) << endl; // Prime count print karo
    return 0;
}

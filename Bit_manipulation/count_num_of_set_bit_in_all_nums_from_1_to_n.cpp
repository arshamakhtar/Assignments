#include <iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        int num = i;
        while (num) {
            count += (num & 1);
            num >>= 1;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << countSetBits(n) << endl;
    return 0;
}

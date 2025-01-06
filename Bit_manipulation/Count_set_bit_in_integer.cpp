#include <iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        count += (n & 1); 
        n >>= 1;        
    }
    return count;
}

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    cout << "Number of set bits in " << num << " is: " << countSetBits(num) << endl;
    return 0;
}

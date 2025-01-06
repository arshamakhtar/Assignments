#include <iostream>
using namespace std;

int countFlips(int A, int B) {
    int diff = A ^ B;
    int count = 0;
    while (diff) {
        count += (diff & 1);
        diff >>= 1;
    }
    return count;
}

int main() {
    int A, B;
    cin >> A >> B;
    cout <<"minimum number of flips req are:"<< countFlips(A, B) << endl;
    return 0;
}

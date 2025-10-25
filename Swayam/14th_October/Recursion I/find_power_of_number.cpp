#include<iostream>
using namespace std;
int power(int base, int exponent){
    if(exponent == 0){
        return 1;
    }
    return base * power(base, exponent - 1);
}int main(){
    int base, exponent;
    cout << "Enter base and exponent: ";
    cin >> base >> exponent;
    int result = power(base, exponent);
    cout << base << " raised to the power of " << exponent << " is: " << result << endl;
    return 0;
}
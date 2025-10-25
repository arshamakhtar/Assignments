#include<iostream>
using namespace std;
int countDigit(int n, int digit){
    if(n == 0){
        return 0;
    }
    int count = (n % 10 == digit) ? 1 : 0;
    return count + countDigit(n / 10, digit);
}int   

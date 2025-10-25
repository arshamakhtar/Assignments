#include<iostream>
using namespace std;    
int towerOfHanoi(int n, char source, char destination, char auxiliary){
    if(n == 1){
        cout << "Move disk 1 from rod " << source << " to rod " << destination << endl;
        return 0;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;
    towerOfHanoi(n - 1, auxiliary, destination, source);
    return 0;
}
int main(){
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}
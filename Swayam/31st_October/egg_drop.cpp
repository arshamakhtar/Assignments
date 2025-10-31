#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function with memoization, calculates minimum attempts needed
    int solve(int k, int n, vector<vector<int>>& t){
        // Base case: If only 1 egg left, or floors 0 or 1, steps = floors (linear search)
        if(k == 1 || n == 0 || n == 1) return n;

        // If already calculated, return from memo
        if(t[k][n] != -1) return t[k][n];

        int mn = INT_MAX;
        int low = 1, high = n;

        // Binary search to find the floor which minimizes the worst attempts
        while(low <= high){
            int mid = (low + high) / 2;

            // Agar egg tut gaya toh neeche ke floors ko dekho, eggs - 1
            int left = solve(k - 1, mid - 1, t);

            // Agar egg nahi tuta toh upar ke floors ko dekho, same eggs
            int right = solve(k, n - mid, t);

            int temp = 1 + max(left, right);  // worst case attempts

            mn = min(mn, temp);

            // Binary search adjustment
            if(left < right) low = mid + 1;  // right wale part me attempts zyada hain
            else high = mid - 1;              // left wale part me attempts zyada hain
        }
        // Memoize the answer and return
        return t[k][n] = mn;
    }

    int superEggDrop(int k, int n) {
        // Initialize memo with -1 indicating not calculated subproblems
        vector<vector<int>> t(k+1, vector<int>(n+1, -1));
        return solve(k, n, t);
    }
};

// Driver code
int main(){
    vector<int> k = {1, 2, 2, 3, 10};  // Eggs count testcases
    vector<int> n = {2, 100, 6, 14, 10};  // Floors count testcases

    for(int i = 0; i < 5 ; ++i ){
        cout << "Eggs: " << k[i] << ", Floors: " << n[i]
        << " => Minimum attempts: " << Solution().superEggDrop(k[i], n[i]) << endl;
    }
    return 0;
}
    
// output:
// Eggs: 1, Floors: 2 => Minimum attempts: 2
// Eggs: 2, Floors: 100 => Minimum attempts: 14
// Eggs: 2, Floors: 6 => Minimum attempts: 3
// Eggs: 3, Floors: 14 => Minimum attempts: 4
// Eggs: 10, Floors: 10 => Minimum attempts: 4
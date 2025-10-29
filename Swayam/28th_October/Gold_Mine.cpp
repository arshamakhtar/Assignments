#include <bits/stdc++.h>

using namespace std;

// Yeh function ek particular cell se maximum gold collect karta hai
int collectGold(int x, int y, vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();

    // Agar cell matrix ki boundary ke bahar hai toh 0 return karo (base case)
    if (x < 0 || x >= n || y >= m) {
        return 0;
    }

    // Right-upper cell mein move karo
    int rightUpper = collectGold(x - 1, y + 1, mat);

    // Direct right cell mein move karo
    int right = collectGold(x, y + 1, mat);

    // Right-lower cell mein move karo
    int rightLower = collectGold(x + 1, y + 1, mat);

    // Teenon moves mein se jo max hai woh choose karo, usko current cell ke gold ke saath add karo
    return mat[x][y] + max(max(rightUpper, right), rightLower);
}

// maxGold function har row se starting karke max gold calculation karta hai
int maxGold(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    int result = 0;

    // Har row se start karte hue first column se recur karo
    for (int i = 0; i < n; i++) {
        int gold = collectGold(i, 0, mat);
        result = max(result, gold);
    }

    return result;
}

// Driver code to test the function
int main() {
    vector<vector<int>> mat = {
        {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };

    cout << maxGold(mat) << endl;
    return 0;
}

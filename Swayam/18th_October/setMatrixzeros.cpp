#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int mat[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    bool rowZero[100] = {0};
    bool colZero[100] = {0};

    // pehle identify rows and columns jaha 0 hai
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mat[i][j] == 0) {
                rowZero[i] = true;
                colZero[j] = true;
            }

    // set rows and columns to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (rowZero[i] || colZero[j])
                mat[i][j] = 0;

    // print matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

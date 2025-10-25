#include<iostream>
using namespace std;    
int spiraltraversal(int matrix[][100], int rows, int cols){
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    cout << "Spiral Traversal of the matrix is: ";
    while(top <= bottom && left <= right){
        // Traverse from left to right
        for(int i = left; i <= right; i++){
            cout << matrix[top][i] << " ";
        }
        top++;

        // Traverse from top to bottom
        for(int i = top; i <= bottom; i++){
            cout << matrix[i][right] << " ";
        }
        right--;

        // Traverse from right to left
        if(top <= bottom){
            for(int i = right; i >= left; i--){
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }

        // Traverse from bottom to top
        if(left <= right){
            for(int i = bottom; i >= top; i--){
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
    return 0;
}
int main(){
    int rows, cols;
    cout << "Enter the number of rows and columns in the matrix: ";
    cin >> rows >> cols;

    int matrix[100][100];
    cout << "Enter the elements of the matrix:" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> matrix[i][j];
        }
    }

    spiraltraversal(matrix, rows, cols);
    return 0;
}
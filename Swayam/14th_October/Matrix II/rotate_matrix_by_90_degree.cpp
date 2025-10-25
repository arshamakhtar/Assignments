#include<iostream>
using namespace std;
int rotateMatrixBy90Degree(int matrix[][100], int rows, int cols){
    // Transpose the matrix
    for(int i = 0; i < rows; i++){
        for(int j = i; j < cols; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Reverse each row
    for(int i = 0; i < rows; i++){
        int left = 0, right = cols - 1;
        while(left < right){
            int temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;
            left++;
            right--;
        }
    }

    cout << "Matrix after rotating by 90 degrees:" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
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

    rotateMatrixBy90Degree(matrix, rows, cols);
    return 0;
}
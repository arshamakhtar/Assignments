#include<iostream>
using namespace std;
int identifyRowsAndColumnsWithMaxOnes(int matrix[][100], int rows, int cols){
    int maxRowIndex = -1;
    int maxColIndex = -1;
    int maxRowCount = -1;
    int maxColCount = -1;

    // Identify the row with maximum 1s
    for(int i = 0; i < rows; i++){
        int rowCount = 0;
        for(int j = 0; j < cols; j++){
            if(matrix[i][j] == 1){
                rowCount++;
            }
        }
        if(rowCount > maxRowCount){
            maxRowCount = rowCount;
            maxRowIndex = i;
        }
    }


    // Identify the column with maximum 1s
    for(int j = 0; j < cols; j++){
        int colCount = 0;
        for(int i = 0; i < rows; i++){
            if(matrix[i][j] == 1){
                colCount++;
            }
        }
        if(colCount > maxColCount){
            maxColCount = colCount;
            maxColIndex = j;
        }
    }

    cout << "Row with maximum 1s: " << maxRowIndex << " (Count: " << maxRowCount << ")" << endl;
    cout << "Column with maximum 1s: " << maxColIndex << " (Count: " << maxColCount << ")" << endl;

    return 0;
}int main(){
    int rows, cols;
    cout << "Enter the number of rows and columns in the matrix: ";
    cin >> rows >> cols;

    int matrix[100][100];
    cout << "Enter the elements of the matrix (0s and 1s only):" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> matrix[i][j];
        }
    }

    identifyRowsAndColumnsWithMaxOnes(matrix, rows, cols);
    return 0;
}
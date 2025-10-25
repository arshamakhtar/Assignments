#include<iostream>
using namespace std;
int medianrowwiseSortedMatrix(int matrix[][100], int rows, int cols){
    int minElement = matrix[0][0];
    int maxElement = matrix[0][cols - 1];

    // Find the global minimum and maximum elements in the matrix
    for(int i = 1; i < rows; i++){
        if(matrix[i][0] < minElement){
            minElement = matrix[i][0];
        }
        if(matrix[i][cols - 1] > maxElement){
            maxElement = matrix[i][cols - 1];
        }
    }

    int desiredCount = (rows * cols + 1) / 2;

    while(minElement < maxElement){
        int midElement = minElement + (maxElement - minElement) / 2;
        int count = 0;

        // Count number of elements less than or equal to midElement
        for(int i = 0; i < rows; i++){
            int left = 0, right = cols - 1;
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(matrix[i][mid] <= midElement){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            count += left;
        }

        if(count < desiredCount){
            minElement = midElement + 1;
        } else {
            maxElement = midElement;
        }
    }

    return minElement;
}int main(){
    int rows, cols;
    cout << "Enter the number of rows and columns in the matrix: ";
    cin >> rows >> cols;
    
    
    int matrix[100][100];
    cout << "Enter the elements of the matrix (row-wise sorted):" << endl;  
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> matrix[i][j];
        }
    
}
    int median = medianrowwiseSortedMatrix(matrix, rows, cols);
    cout << "The median of the row-wise sorted matrix is: " << median << endl;
    return 0;
}
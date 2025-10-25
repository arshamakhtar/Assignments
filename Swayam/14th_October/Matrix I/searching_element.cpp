#include<iostream>
using namespace std;
int main (){
    int rows, cols, element;
    cout << "Enter the number of rows and columns in the matrix: ";
    cin >> rows >> cols;

    int matrix[100][100];
    cout << "Enter the elements of the matrix:" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> matrix[i][j];
        }
    }

    cout << "Enter the element to search for: ";
    cin >> element;

    bool found = false;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i][j] == element){
                found = true;
                break;
            }
        }
        if(found){
            break;
        }
    }

    if(found){
        cout << "Element " << element << " found in the matrix." << endl;
    } else {
        cout << "Element " << element << " not found in the matrix." << endl;
    }

    return 0;
}

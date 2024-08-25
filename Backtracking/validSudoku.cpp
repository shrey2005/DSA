#include <iostream>

using namespace std;

bool isValid(int row, int col, int ele, int matrix[9][9]) {

    if(row < 0 || row >= 9 || col < 0 || col >= 9) return false;

    //each row
    for (int i = 0; i < 9; i++){
        if(matrix[row][i] == ele){
            return false;
        }
    }

    //each column
    for(int i = 0; i < 9; i++){
        if(matrix[i][col] == ele){
            return false;
        }
    }

    //each 3 * 3 sub-matrices
    int startRow = (row / 3 ) * 3;
    int startCol = (col / 3 ) * 3;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(matrix[startRow + i][startCol + j] == ele){
                return false;
            }
        }
    } 
    return true;
}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(matrix[i][j] == 0){
                for(int k = 1; k <= 9; k++){
                    if(isValid(i, j, k, matrix)){
                        matrix[i][j] = k;
                        if(isItSudoku(matrix)){
                            return true;
                        }
                        else{
                            matrix[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}


int main() {
    int t;
    cin >> t;
    while(t--){
        int matrix[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cin >> matrix[i][j];
        }
        bool ans = isItSudoku(matrix);
        if (ans) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

}

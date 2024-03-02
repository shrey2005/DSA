#include <iostream>
using namespace std;

void print2DArray(int input[][1000], int row, int col) {
	// Write your code here
	for(int i = 0; i < row ; i++){
        for(int k = 0; k < row - i; k++){
            for(int j = 0; j < col ;j++){
                cout<<input[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

 bool isUniqueRow(char c,vector<vector<bool>>& board, int n, int i){
        int jth =  c - '0' - 1;
        if(!board[i][jth]){
            board[i][jth] = true;
            return true;
        }
        return false;
    }

    bool isUniqueCol(char c,vector<vector<bool>>& board, int n, int j){
        int ith = c - '0' - 1;
        if(!board[ith][j]){
            board[ith][j] = true;
            return true;
        }
        return false;
    }

    bool isUniqueGrid(vector<bool>& uniqeGrid, char c, int i, int j){
        if(c == '.'){
           return true;
        }
        int value = c - '0';
        if(!uniqeGrid[value]){
            uniqeGrid[value] = true;
            return true;
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
	    vector<vector<bool>> copysuoku(n, vector<bool>(n, false));
	    vector<vector<bool>> copysuokuCol(n, vector<bool>(n, false));
	    for(int i = 0; i < board.size(); i++){
	        for(int j = 0; j < board[i].size(); j++){
	            if(board[i][j] != '.'){
                    if(!isUniqueRow(board[i][j], copysuoku, n, i)){
                        return false;
                    }
	            }
	        }   
	    }
	
	    for(int i = 0; i < board.size(); i++){
	        for(int j = 0; j < board[i].size(); j++){
	            if(board[i][j] != '.'){
                    if(!isUniqueCol(board[i][j], copysuokuCol, n, j)){
                        return false;
                    }
	            }
	        }
	    }
	
	    for(int boxRow = 0; boxRow < 9; boxRow = boxRow + 3){
	        bool isUniqueGridResult = false;
	        for(int boxCol = 0; boxCol < 9; boxCol = boxCol + 3){
	            vector<bool> uniqueGrid(9, false);
	            for(int i = boxRow; i < boxRow + 3; i++){
	                for(int j = boxCol; j < boxCol + 3; j++){
                        if(!isUniqueGrid(uniqueGrid, board[i][j], i, j)){
                            return false;
                        }
	                }
	            }
            }
	    }
        return true;
    }
int main() {
	// your code goes here
    vector<vector<char>> sudoku = {{'5','3','.','9','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'1','9','8','.','.','4','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    bool result = isValidSudoku(sudoku);
    cout<<result<<endl;
    return 0;
}

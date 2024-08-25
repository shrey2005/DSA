#include <iostream>
#include <vector>
using namespace std;

int visited[10][10];

bool isValid(int x, int y, int n){
    //Up
    for(int i = 0; i < x; i++){
        if(visited[i][y] == 1){
            return false;
        }
    }

    //Top Left
    for(int i = x, j = y; i >= 0 && j >= 0; i--, j--){
        if(visited[i][j] == 1){
            return false;
        }
    }

    //Top Right
    for(int i = x, j = y; i >= 0 && j <n; i-- , j++){
        if(visited[i][j] == 1){
            return false;
        }
    }
    return true;
}

void solved(vector<vector<int>> &result, int row, int n){
    if(row == n){
        vector<int> arrResult;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                arrResult.push_back(visited[i][j]);
            }
        }
        result.push_back(arrResult);
        return;
    }
    for(int j = 0; j < n; j++){
        if(isValid(row, j, n)){
            visited[row][j] = 1;
            solved(result, row+1,n);
            visited[row][j] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> visited;
    int row = 0;
    solved(visited, row, n);
    return visited;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> answer;
    answer = solveNQueens(n);

    for (auto sol : answer) {
        for (auto i : sol) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
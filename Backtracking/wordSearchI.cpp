#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, int m,char ch, vector<vector<char>> board){
    if(x < 0 || x >= n){
        return false;
    }
    if(y < 0 || y >= m){
        return false;
    }
    if(board[x][y] != ch){
        return false;
    }
    return true;
}

bool isWordPresent(int x, int y, int n,int m, int index, string &word, vector<vector<char>> &board){
    if(index == word.length() - 1){
        return true;
    }

    char originalChar = board[x][y];
    board[x][y] = '#';

    int currentIndex = index + 1;
    bool found = false;
    
    if(isValid(x+1, y, n, m, word[currentIndex], board)){
        found = isWordPresent(x+1, y, n, m, currentIndex, word, board);
    }
    if(!found && isValid(x-1, y, n, m, word[currentIndex], board)){
        found =  isWordPresent(x-1, y, n, m, currentIndex, word, board);
    }
    if(!found && isValid(x, y +1, n, m, word[currentIndex], board)){
        found = isWordPresent(x, y +1, n, m, currentIndex, word, board);
    }
    if(!found && isValid(x, y-1, n, m, word[currentIndex], board)){
        found = isWordPresent(x, y-1, n, m, currentIndex, word, board);
    }
    board[x][y] = originalChar;
    return found;
}

bool present(vector<vector<char>> &board, string &word, int n, int m) 
{
    // Write your code here.
    if(n == 0 || m == 0) return false;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == word[0] && isWordPresent(i, j, n, m, 0, word, board)){
                return true;
            }
        }
    }

    return false;
}


class Runner
{
    string s;
    int n,m;
    vector<vector<char>> mat;

public:
    
    void takeInput()
    {
        cin >> s >> n >> m;
        mat = vector<vector<char>> (n,vector<char> (m));
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin >> mat[i][j];
    }
    void execute()
    {
        // make copy if vector
        auto cmat = mat;
        present(cmat,s,n,m);
    }
    void executeAndPrintOutput()
    {
        auto cmat = mat;
        if(present(cmat,s,n,m))cout << "true";
        else cout << "false";
    }
};

int main()
{
        Runner runner;
        runner.takeInput();
        runner.executeAndPrintOutput();   
    return 0;
    
}
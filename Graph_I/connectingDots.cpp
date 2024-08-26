#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int i, int j, int pi, int pj, char ch){
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != ch ){
        return false;
    }

    if(visited[i][j]){
        return true;
    }

    visited[i][j] = true;

    int direction[4][2] = {{-1, 0},{1, 0}, {0, -1},{0, 1}};

    for(auto dir : direction){
        int ni = i + dir[0];
        int nj = j + dir[1];

        if(ni == pi && nj == pj){
            continue; 
        }
        if(dfs(board, visited, ni, nj, i, j, ch)){
            return true;
        }
    }
    return false;
}
bool isConnectingDots(vector<vector<char>> board, int n, int m){
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j]){
                if(dfs(board, visited, i, j, -1, -1, board[i][j])){
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    //Write your code here
    int n, m;
    cin>>n>>m;

    vector<vector<char>> board(n, vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>board[i][j];
        }
    }

    cout<<(isConnectingDots(board, n, m) ? "true" : "false")<<endl; 
}
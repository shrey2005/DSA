#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


#include <bits/stdc++.h> 
bool isValid(int x, int y, vector<vector<int>> &arr, vector<vector<int>> &board, int n) {
  return x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 1 && board[x][y] == 0;
}

void ratInMazeHelper(int x, int y, vector<vector<int>> &maze, int n, vector<vector<int>> &result, vector<vector<int>> &board){
    if (x == n - 1 && y == n - 1) {
      vector<int> path;
      board[x][y] = 1;
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          path.push_back(board[i][j]);
        }
      }
      result.push_back(path);
      board[x][y] = 0;
      return;
  }

  if(isValid(x + 1, y, maze, board, n)){
    board[x][y] = 1;
    ratInMazeHelper(x + 1, y, maze, n, result, board);
    board[x][y] = 0;
  }

  if(isValid(x, y + 1, maze,board,  n)){
    board[x][y] = 1;
    ratInMazeHelper(x, y + 1, maze, n, result, board);
    board[x][y] = 0;
  }

  if(isValid(x - 1, y, maze,board,  n)){
    board[x][y] = 1;
    ratInMazeHelper(x - 1, y, maze, n, result, board);
    board[x][y] = 0;
  }

  if(isValid(x, y - 1, maze, board, n)){
    board[x][y] = 1;
    ratInMazeHelper(x, y - 1, maze, n, result, board);
    board[x][y] = 0;
  }
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
   vector<vector<int>> result;
   vector<vector<int>> board(n,vector<int>(n, 0));

   if(maze[0][0] == 1 && maze[n-1][n-1] == 1){
     ratInMazeHelper(0, 0, maze, n, result, board);
   }
   return result;
}

int main()
{

  int n;
  cin >> n;
  vector<vector<int>> maze(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> maze[i][j];
    }
  }
  
  vector<vector<int>> ans = ratInAMaze(maze, n);

  // sort(ans.begin(),ans.end());

  int s = ans.size();
  for (int i = 0; i < s; i++)
  {
    int t = ans[i].size();
    for (int j = 0; j < t; j++)
    {
      cout << ans[i][j] << " ";
    }

    cout << endl;
  }
}
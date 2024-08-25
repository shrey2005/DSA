#include <iostream>
#include <vector>

using namespace std;

#include <bits/stdc++.h> 
bool isValid(int x, int y, vector<vector<int>> &arr, int n) {
    return x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 1;
}

void searchRatInMaze(int x, int y, int n, vector<vector<int>> &arr, string path, vector<string> &allPaths) {
    if (x == n - 1 && y == n - 1) {
        allPaths.push_back(path);
        return;
    }

    arr[x][y] = 2;  // Mark as visited

    // Move Down
    if (isValid(x + 1, y, arr, n)) {
        searchRatInMaze(x + 1, y, n, arr, path + "D", allPaths);
    }

    // Move Left
    if (isValid(x, y - 1, arr, n)) {
        searchRatInMaze(x, y - 1, n, arr, path + "L", allPaths);
    }

    // Move Right
    if (isValid(x, y + 1, arr, n)) {
        searchRatInMaze(x, y + 1, n, arr, path + "R", allPaths);
    }

    // Move Up
    if (isValid(x - 1, y, arr, n)) {
        searchRatInMaze(x - 1, y, n, arr, path + "U", allPaths);
    }

    arr[x][y] = 1;  // Unmark the current cell
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    vector<string> allPaths;
    if (arr[0][0] == 1 && arr[n - 1][n - 1] == 1) {
        searchRatInMaze(0, 0, n, arr, "", allPaths);
    }
    return allPaths;
}

class Runner {
    int t;
    vector<vector<int>> arr;

public:
    void takeInput() {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            arr.push_back(vector<int>());
            for(int j=0;j<n;j++)
            {
                int x;
                cin>>x;
                arr[i].push_back(x);
            }
        }
    }

    void execute() {
        vector<vector<int> > arrCopy = arr;

        vector<string> ans= searchMaze(arrCopy, arrCopy.size());
    }

    void executeAndPrintOutput() {
        vector<string> ans = searchMaze(arr,arr.size());
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
};

int main() {

    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}
#include <bits/stdc++.h> 

#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

vector<vector<int>> transpose(int m, int n, vector<vector<int>> &mat){
    // Write your code here.

        vector<int> row(m ,n);
        vector<vector<int>> result(n, vector<int>(m,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j <m; j++){
                result[i][j] = mat[j][i];
            }
        }

        // for(int i =0 ; i <n ; i++){
        //     for (int j = 0; j < m; j++) {
        //         cout << result[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    return result;

}

class Runner
{
    int t;
    vector<vector<vector<int>>> mat1;

public:
    void takeInput()
    {
        cin >> t;
      
        mat1.resize(t);
        for (int c = 0; c < t; c++)
        {   
            int m,n;
            cin>>m>>n;
            mat1[c].resize(m);
            for(int k = 0; k < m; k++){
                mat1[c][k].resize(n);
                for(int l = 0; l < n; ++l) {
                    cin>>mat1[c][k][l];
                }
            }
        }
    }

    void execute()
    {
        for (int i = 0; i < t; i++)
        {   
            vector<vector<int>> ans = transpose(mat1[i].size(), mat1[i][0].size(), mat1[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            vector<vector<int>> ans = transpose(mat1[i].size(), mat1[i][0].size(), mat1[i]);
        
            for(int m = 0; m < ans.size(); ++m) {
                for(int n = 0; n < ans[0].size(); ++n) {
                    cout<<ans[m][n]<<" ";
                }
                cout<<"\n";
            } 
        }
    }
};

int main()
{   
// #ifndef ONLINE_JUDGE
//     freopen("Testcases/large/in/input4.txt", "r", stdin);
//     //freopen("Testcases/large/out/output1.txt", "w", stdout);
// #endif
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}

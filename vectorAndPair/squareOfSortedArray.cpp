
#include <iostream>
#include<fstream>
#include <vector>
#include<string>
#include<cstring>
#include <bits/stdc++.h> 
#include <cmath>

using namespace std;

vector < int > sqsorted(vector < int > & arr) {
    // Write your code here.
    // int totalItr;
    // cin>>totalItr;
    
    // for(int i = 0 ; i < totalItr; i++){
        int n = arr.size();
        
        for(int i = 0 ; i < n; i++){
            int sqr = pow(arr[i],2);
            arr[i] = sqr;
        }
        
        sort(arr.begin(), arr.end());

        return arr;
    // }
}

class Runner
{
    int t;
    vector<vector<int>> arr;
   
public:

    void takeInput()
    {
        cin >> t;
        for (int c = 0; c < t; c++)
        {
            int n;
            cin>>n;
          
            vector<int>temp(n);
            for(int i=0;i<n;i++)
            {
                cin>>temp[i];
            }
            arr.push_back(temp);
 
 using namespace std;
 }

    }

    void execute()
    {
        vector<vector<int>> arrCopy = arr;
       
        for (int i = 0; i < t; i++)
        {
            vector<int> ans = sqsorted(arrCopy[i]);
        }

    }

    void executeAndPrintOutput()
    {
    for (int i = 0; i < t; i++)
        {
            vector<int> ans = sqsorted(arr[i]);
            for(int i=0;i<ans.size();i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }   
    }

};

int main()
{
   Runner runner;
   runner.takeInput();
   runner.executeAndPrintOutput();
   
}

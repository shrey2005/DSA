#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h> 
#include<unordered_map>

using namespace std;

vector<int> removeDuplicates(vector<int> arr) {

  // Write your code here
  vector<int> output;
  unordered_map<int,bool> seen;
  for(int i = 0; i < arr.size(); i++){
    if(seen.count(arr[i]) > 0){
      continue;
    }
    seen[arr[i]] = true;
    output.push_back(arr[i]);
  }
  return output;
}

class Runner
{
    int t;

    
    vector<vector<int> > arr;


public:
    void takeInput()
    {

 cin >> t;
        arr.resize(t);
        

        for (int tc = 0; tc < t; tc++)
        {
            int n;
            cin >> n;



            arr[tc].resize(n);

            for (int i = 0; i < n; i++)
            {
                cin >> arr[tc][i];
            }
        }

        
    }

    void execute()
    {
         vector<vector<int> > arrCopy = arr;
        for (int i=0;i<t;i++){
            removeDuplicates(arrCopy[i]);
        }
    }


    void executeAndPrintOutput()
    {
        for (int tt=0;tt<t;tt++){
            vector<int> v=removeDuplicates(arr[tt]);
            for (int i=0; i < v.size(); i++){
              cout<<v[i]<<" ";         
            }
            cout<<"\n";
        }
    }
};

int main()
{

    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}

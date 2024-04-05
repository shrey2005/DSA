#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;


void reverseArray(vector<int> &arr , int m){
    // Write your code here   
    reverse(arr.begin() + m + 1, arr.end());    	
}


class Runner
{
    int t;
    vector<vector<int>> arr;
    vector<int> ks;

public:
    void takeInput()
    {
        cin >> t;
        for (int c = 0; c < t; c++)
        {
            int n, k, val;

            cin >> n >> k;

            vector<int> nums;
            for (int i = 0; i < n; i++)
            {
                cin >> val;
                nums.push_back(val);
            }

            ks.push_back(k);
            arr.push_back(nums);
        }
    }

    void execute()
    {
        vector<vector<int>> arrCopy = arr;
        vector<int> ksCopy = ks;

        for (int i = 0; i < t; i++)
        {
            reverseArray(arrCopy[i], ksCopy[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            reverseArray(arr[i], ks[i]);
            for (auto x : arr[i]) {
                cout << x << " ";
            }
            cout << "\n";
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
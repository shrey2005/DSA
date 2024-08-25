#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

void uniqueSubsetsHelper(vector<int> &input, int index, vector<int> &current, vector<vector<int>> &res){
    res.push_back(current);

    for(int i = index; i < input.size(); i++){
        if(i > index && input[i] == input[i-1]){
            continue;
        }

        current.push_back(input[i]);
        uniqueSubsetsHelper(input, i+1, current, res);
        current.pop_back();
    }
}
vector<vector<int>> getUniqueSubsets(vector<int>& arr) {
    // Write Your Code Here
    sort(arr.begin(), arr.end());    
    vector<vector<int>> res;
    vector<int> current;

    uniqueSubsetsHelper(arr, 0, current,res);
    return res; 
}

class Runner
{
    vector<int> arr;
    int n;
public:
    void takeInput()
    {
        cin >> n;
        arr.assign(n, 0);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
    }
    void execute()
    {
        getUniqueSubsets(arr);
    }

    void executeAndPrintOutput()
    {
        auto c = getUniqueSubsets(arr);
        sort(c.begin(), c.end());
        
        for(auto val : c) {
            for(auto vall : val) cout << vall << ' ';
            cout << '\n';
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

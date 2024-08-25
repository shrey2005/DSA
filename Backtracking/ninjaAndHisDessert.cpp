#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bits/stdc++.h> 

using namespace std;

int getAns(int currCost, int newCost, int target){
    int diff1 = abs(target - currCost);
    int diff2 = abs(target - newCost);
    if(diff1 == diff2){
        return min(newCost, currCost);
    }
    return diff1 < diff2 ? currCost : newCost;
}

int f(vector<int> toppingCosts, int currentToppingIndex, int numTopIndex, int target){
    if(currentToppingIndex < 0){
        return 0;
    }

    int takeTop = 0, notTakeTop = 0;

    if(numTopIndex < 2){
        takeTop = toppingCosts[currentToppingIndex] + f(toppingCosts, currentToppingIndex, numTopIndex + 1, target - toppingCosts[currentToppingIndex]);
    }
    notTakeTop = f(toppingCosts, currentToppingIndex - 1, 0,target);
    return getAns(takeTop, notTakeTop, target);
}

int closestCost(int n, int m, vector<int> &baseCosts, vector<int> &toppingCosts, int target)
{
    // wrtie your code here;
    int ans = INT_MAX;
    for(int i = 0; i < n ; i++){
        if(baseCosts[i] <= target){
            ans = getAns(ans, baseCosts[i] + f(toppingCosts, m-1, 0, target - baseCosts[i]), target);
        }
        ans = getAns(ans, baseCosts[i], target);
    }
    return ans;
}

class Runner
{
    int t;
    vector<int> n, m, target;
    vector<vector<int>> base, toppings;

public:
    void takeInput()
    {
        cin >> t;

        for (int i = 0; i < t; i++)
        {
            int N;
            cin >> N;
            n.push_back(N);

            vector<int> v;
            for (int j = 0; j < N; j++)
            {
                int B;
                cin >> B;
                v.push_back(B);
            }
            base.push_back(v);

            int M;
            cin >> M;
            m.push_back(M);

            vector<int> u;
            for (int k = 0; k < M; k++)
            {
                int top;
                cin >> top;
                u.push_back(top);
            }

            toppings.push_back(u);

            int tar;
            cin >> tar;

            target.push_back(tar);
        }
    }

    void execute()
    {
        vector<vector<int>> cpyB = base;
        vector<vector<int>> cpyT = toppings;

        for (int i = 0; i < t; i++)
        {
            int ans = closestCost(n[i], m[i], base[i], toppings[i], target[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int ans = closestCost(n[i], m[i], base[i], toppings[i], target[i]);
            cout << ans << "\n";
        }
    }
};

int main()
{

#ifndef ONLINE_JUDGE
//freopen("TestCases/large/in/input11.txt", "r", stdin);
//freopen("TestCases/large/out/output11.txt", "w", stdout);
#endif
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}

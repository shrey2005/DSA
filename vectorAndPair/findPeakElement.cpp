#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int findPeakElement(vector<int> &arr) {
    // Write your code here
    for(int i = 1; i < arr.size() ; i++){
        if(arr[i - 1] < arr[i] && arr[i+1] < arr[i]){
            return i;
        }
    }
    return 0;
}

class Runner {
    vector<int> v;

public:
    void takeInput() {
        int n;
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
    }

    void execute() {
        vector<int> temp = v;
        int ans = findPeakElement(temp);
    }

    void executeAndPrintOutput() {
        vector<int> temp = v;
        int ans = findPeakElement(temp);
        if (ans >= 0 && ans < v.size() && get(ans - 1) < get(ans) && get(ans) > get(ans + 1))
            cout << "True\n";
        else
            cout << "False\n";
    }

    int get(int i) {
        if (i < 0)
            return -100;
        if (i >= v.size())
            return -100;
        return v[i];
    }
};

int main() {
    // freopen("./Testcases/large/in/input.txt", "r", stdin);
    // freopen("./Testcases/large/out/output.txt", "w", stdout);
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}


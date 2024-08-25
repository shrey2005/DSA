#include <iostream>
#include <vector>
#include<queue>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < input.size();i++){
        vector<int>* ele = input[i];
        for(auto at = ele->begin(); at < ele->end(); at++){
            pq.push(*at);
        }
    } 

    vector<int> res;
    while(!pq.empty()){
        int ele = pq.top();
        res.push_back(ele);
        pq.pop();
    }
    return res;
}

int main() {
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}
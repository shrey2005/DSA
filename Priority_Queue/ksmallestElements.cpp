#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;

vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    priority_queue<int> pq;
    vector<int> res;

    for(int i = 0; i < k ; i++){
        pq.push(arr[i]);
    }

    for(int i = k; i < n; i++){
        int maxEle = pq.top();
        if(maxEle > arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    while(!pq.empty()){
        int topEle = pq.top();
        res.push_back(topEle);
        pq.pop();
    }
    return res;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete[] input;
}

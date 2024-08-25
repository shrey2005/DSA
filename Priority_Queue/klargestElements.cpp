#include <iostream>
#include <vector>
#include<queue>
using namespace std;

vector<int> kLargest(int input[], int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> res;

    for(int i = 0; i < k; i++){
        pq.push(input[i]);
    }

    for(int i = k; i < n; i++){
        int maxEle = pq.top();
        if(maxEle < input[i]){
            pq.pop();
            pq.push(input[i]);
        }
    }

    while(!pq.empty()){
        int ele = pq.top();
        res.push_back(ele);
        pq.pop();
    }
    return res;
}


int main() {
	
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
    
    int k;
    cin >> k;
    
    vector<int> output = kLargest(input, size, k);
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << endl;
	
	return 0;
}
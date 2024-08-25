#include <iostream>
#include <queue>
using namespace std;

void findMedian(int *arr, int n)
{
    // Write your code here
    if(n == 0){
        return;
    }
    priority_queue<int, vector<int>, greater<int>> maxpq;
    priority_queue<int> minpq;
    
    minpq.push(arr[0]);
    cout<<arr[0];
    
    for(int i = 1; i < n; i++){
        if(minpq.top() < arr[i]){
            maxpq.push(arr[i]);
        }
        else{
            minpq.push(arr[i]);
        }
        
        if(minpq.size() > maxpq.size() + 1){
            maxpq.push(minpq.top());
            minpq.pop();
        }
        else if(maxpq.size() > minpq.size()){
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        
        if(i % 2 == 0){
            cout<<" "<<minpq.top();
        }
        else{
            int calMed = (minpq.top() + maxpq.top()) / 2;
            cout<<" "<<calMed;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}

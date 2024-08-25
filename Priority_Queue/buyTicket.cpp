#include <iostream>
#include <vector>
#include<queue>
using namespace std;

int buyTicket(int *arr, int n, int k) {
    // Write your code here
    queue<int> q;
    priority_queue<int> pq;

    for(int i = 0; i < n; i++){
        pq.push(arr[i]);
        q.push(i);
    }

    int timer = 0;
    while(q.front() != k || pq.top() != arr[q.front()]){
        if(pq.top() > arr[q.front()]){
            int x = q.front();
            q.pop();
            q.push(x);
        }
        else if(pq.top() == arr[q.front()]){
            q.pop();
            pq.pop();
            timer++;
        }
    }
    return timer + 1;
}
int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}
#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    // Write your code here
    int parentIndex = 0;
    int leftChildIndex = ( 2 * parentIndex ) + 1;
    int rightChildIndex = ( 2 * parentIndex ) + 2;
    
    bool isMaxHeapFlag = false;
    while(leftChildIndex < n){
        if(arr[parentIndex] > arr[leftChildIndex] && arr[parentIndex] > arr[rightChildIndex]){
            isMaxHeapFlag = true;
        }
        else{
            isMaxHeapFlag = false;
            break;
        }
        parentIndex = parentIndex + 1;
        
        leftChildIndex = ( 2 * parentIndex ) + 1;
        rightChildIndex = ( 2 * parentIndex ) + 2;
    }
    return isMaxHeapFlag;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}
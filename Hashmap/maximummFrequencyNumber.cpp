#include <iostream>
#include<unordered_map>
using namespace std;

int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int, int> frq;
    for(int i = 0; i < n; i++){
        int value = frq[arr[i]];
        frq[arr[i]] = value + 1;
    }

    int max = arr[0];
    for(int i = 0 ; i < n ; i++){
        if(frq[arr[i]] > frq[max]){
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}
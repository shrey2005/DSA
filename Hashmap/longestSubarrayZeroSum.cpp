#include <iostream>
#include<unordered_map>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    unordered_map<int, int> frq;
    int sum = 0;
    int max = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum == 0 ){
            max = i + 1;
        }
        if(frq.count(sum) == 1){
            auto findIndex = frq.find(sum);
            int calIndex = i - findIndex->second;
            if(calIndex > max){
                max = calIndex;
            }           
            continue;
        }
        frq[sum] = i;
    }
    
    return max;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}
#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here

    unordered_map<int, int> frq;
    for(int i = 0; i < n; i++){
        frq[arr[i]]++;
    }

    vector<int> ans;
    for(int i = 0; i < n; i++){
        vector<int> temp;

        if(frq.count(arr[i] - 1) == 0){
            temp.push_back(arr[i]);

            int t = 1;
            while(frq.count(arr[i] + t)){
                temp.push_back(arr[i] + t);
                t++;
            }

            if(temp.size() > ans.size()){
                ans = temp;
            }
        }
    }

    int n1 = ans[0];
    int n2 = ans[ans.size() - 1];
    ans.clear();
    ans.push_back(n1);
    ans.push_back(n2);
    return ans;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}

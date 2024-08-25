#include <iostream>
#include<unordered_map>
using namespace std;

void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    unordered_map<int, int> frq;
    for(int i = 0; i < n; i++){
        frq[arr1[i]]++;
    }   

    for(int i = 0; i < m; i++){
        auto findVal = frq.find(arr2[i]);
        bool isPresent = (findVal != frq.end());
        if(isPresent && findVal->second > 0){
            cout<<arr2[i]<<endl;
            frq[arr2[i]]--;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}
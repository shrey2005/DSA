#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, size = 0;
    
    cin>>n;
    vector<int> arr(2*n+1);
    
    for(int i = 0; i <(2*n+1) ; i++){
        cin>>arr[i];
        size = max(size, arr[i]);
    }
    
    vector<int> f(size+1, 0);
    
    for(int i = 0 ; i < (2*n+1); i++){
        f[arr[i]]++;
    }
    
    for(int i = 0; i < (2*n+1);i++){
        if(f[i] == 1){
            cout<<i;
            break;
        }
    }
}
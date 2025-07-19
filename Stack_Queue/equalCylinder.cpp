#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    reverse(h1.begin(), h1.end());
    reverse(h2.begin(), h2.end());
    reverse(h3.begin(), h3.end());
    
    int h1Sum = accumulate(h1.begin(), h1.end(), 0);
    int h2Sum = accumulate(h2.begin(), h2.end(), 0);
    int h3Sum = accumulate(h3.begin(), h3.end(), 0);
  
    while(true){

        if(h1.empty() || h2.empty() || h3.empty()){
            return 0;
        }
        
        if(h1Sum == h2Sum && h2Sum == h3Sum){
            return h1Sum;
        }
        
        if(h1Sum >= h2Sum && h1Sum >= h3Sum){
            h1Sum -=  h1.back();
            h1.pop_back();
        }
        else if(h2Sum >= h1Sum && h2Sum >= h3Sum){
            h2Sum -= h2.back();
            h2.pop_back();
        }
        else{
            h3Sum -= h3.back();
            h3.pop_back();
        }   
    }
}

int main() 
{
    vector<int> h1 = {3, 2, 1, 1, 1};
    vector<int> h2 = {4, 3, 2};
    vector<int> h3 = {1, 1, 4, 1};
    
    int equalStackResult = equalStacks(h1, h2, h3);
    cout<<equalStackResult<<endl;
    return 0;
}c
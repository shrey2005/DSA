#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        unordered_map<int, int> element;
        for(int i = 0; i < n; i++){
            int value;
            cin>>value;
            element[value]++;
        }
        
        int dominant_element = -1;
        int maxFreq = 0;
        for(auto e : element){
            if(maxFreq < e.second){
                maxFreq = e.second;
                dominant_element = e.first;
            }
            else if(maxFreq == e.second){
                dominant_element = -1;
            }
        }
        
        if(dominant_element != -1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}

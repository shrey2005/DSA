#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        unordered_map<int, int> elements;
        for(int i = 0; i < n; i++){
            int value;
            cin>>value;
            elements[value]++;
        }
        
        for(auto e : elements){
            if(e.second % 2 == 0 ){
                cout<<e.first<<endl;
            }
        }
    }
}

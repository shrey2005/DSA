#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        set<int> elements;
        for(int i = 0; i < n; i++){
            int value;
            cin>>value;
            elements.insert(value);
        }
        
        cout<<elements.size()<<endl;
    }
}

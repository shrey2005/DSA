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
        int result = 0;
        for(int i = 0; i < n; i++){
            int value;
            cin>>value;
            elements[value]++;
            int count = elements[value];
            if(result < count){
                result = count;
            }
        }
        cout<<n-result<<endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    
    while(t--){
        int x;
        cin>>x;
        
        string s;
        cin>>s;
        
        int carlsen_point = 0;
        int chef_point = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'C'){
                carlsen_point += 2;
            }
            else if(s[i] == 'N'){
                chef_point += 2;
            }
            else if(s[i] == 'D'){
                chef_point += 1;
                carlsen_point += 1;
            }
        }
        
        if(carlsen_point > chef_point){
            cout<<60 * x;
        }
        else if(chef_point > carlsen_point){
            cout<<40  * x;
        }
        else{
            cout<<55 * x;
        }
        cout<<endl;
    }
}

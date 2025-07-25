#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        return true;
    }
    return false;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        // your code goes here
        int contiguousSubstring = 0;
        for(int i = 0 ; i < s.size(); i++){
            bool current = isVowel(s[i]);
            bool next = isVowel(s[i]);
            if(current && next){
                contiguousSubstring++;
                if(contiguousSubstring > 2){
                    break;
                }
            }
            else{
                contiguousSubstring = 0;
            }
        }
        
        if(contiguousSubstring > 2){
            cout<<"Happy";
        }
        else{
            cout<<"Sad";
        }
        cout<<endl;
    }
 }
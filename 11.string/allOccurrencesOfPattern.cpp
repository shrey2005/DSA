#include<iostream>
#include<string>
using namespace std;

int main(){
    // Write your code here

    string str;
    cin>>str;

    string pat;
   cin>>pat;

    for(int i = 0; str[i] != '\0'; i++){
        string subStr = str.substr(i, pat.size());
        if(pat == subStr){
            cout<<i<<" ";
        }
    }
}
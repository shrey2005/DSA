#include <bits/stdc++.h> 
#include <iostream>
#include <cstring>
using namespace std;

void printSubstrings(string input) {
    //Write your code here
    for(int i = 0; i < input.size(); i++){
        string word = "";
        for(int j = i; j < input.size();j++){
            word+= input[j];
            cout<<word<<endl;
        }
    }
}

int main() {
    string input;
    getline(cin, input);
    printSubstrings(input);
    return 0;
}
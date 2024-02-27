#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    //Write your code here
    string inputString;
    getline(cin, inputString);

    int strLen = inputString.size();
    string word = "";
    for(int i = 0 ; i <= strLen; i++){
        if(inputString[i] == ' ' || i == strLen){
            reverse(word.begin(), word.end());
            cout<<word<<" ";
            word="";
        }
        else{
            word+= inputString[i];
        }
    }
}
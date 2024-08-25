#include <iostream>
#include <algorithm>
#include <bits/stdc++.h> 
using namespace std;

void partitionPalindrome(string s, vector<vector<string>> &output, vector<string> palindrome, int index){
    if(index == s.length()){
        output.push_back(palindrome);
        return;
    }
    
    for(int i = index; i < s.length(); i++){
        string substr1 = s.substr(index, i - index + 1);
        string originalStr = substr1;
        reverse(substr1.begin(), substr1.end());
        if(substr1 == originalStr){
            palindrome.push_back(substr1);
            partitionPalindrome(s, output, palindrome, i + 1);   
            palindrome.pop_back();
        }
    }
}
    
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> output;
    vector<string> palindrome;
    
    partitionPalindrome(s, output, palindrome, 0);
    
    return output;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;

    //string str;
    //getline(cin, str);
    while(t--) {

    	string S;
    	getline(cin, S);

    	vector<vector<string>> ans = partition(S);
    	
    	for(int i = 0; i < ans.size(); i++) {

    		cout << "[";
    		
    		sort(ans[i].begin(), ans[i].end());
    		for(int j = 0; j < ans[i].size(); j++) {

    			if(j != ans[i].size() - 1) {
    				cout << "\"" << ans[i][j] << "\", ";
    			}
    			else {
    				cout << "\"" << ans[i][j] << "\"";
    			}

    		}

    		cout << "]" << endl;

    	}

    }

    return 0;

}